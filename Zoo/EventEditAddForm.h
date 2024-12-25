#pragma once
#include "Model.h"
#include "ServiceContainer.h"
#include <msclr/marshal_cppstd.h>

namespace Zoo {
    using namespace System;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace msclr::interop;

    /// <summary>
    /// Form for editing or adding an event.
    /// </summary>
    public ref class EventEditAddForm : public System::Windows::Forms::Form
    {
    private:
        Event* existingEvent;
        bool isEditMode;

    private:
        System::ComponentModel::Container^ components;
    private: System::Windows::Forms::TextBox^ textBoxName;
    private: System::Windows::Forms::TextBox^ textBoxDate;


    private: System::Windows::Forms::TextBox^ textBoxDescription;


        System::Windows::Forms::Button^ buttonSave;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;


    public:
        EventEditAddForm(Event* event) {
            InitializeComponent();
            this->isEditMode = (event != nullptr);
            this->existingEvent = event;

            if (isEditMode && existingEvent) {
                // Pre-fill text boxes with existing event data
                this->textBoxName->Text = gcnew String(existingEvent->getName().c_str());
                this->textBoxDate->Text = gcnew String(existingEvent->getDateString().c_str());
                this->textBoxDescription->Text = gcnew String(existingEvent->getDescription().c_str());
            }
        }

    protected:
        ~EventEditAddForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->textBoxName = (gcnew System::Windows::Forms::TextBox());
            this->textBoxDate = (gcnew System::Windows::Forms::TextBox());
            this->textBoxDescription = (gcnew System::Windows::Forms::TextBox());
            this->buttonSave = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBoxName
            // 
            this->textBoxName->Location = System::Drawing::Point(30, 30);
            this->textBoxName->Name = L"textBoxName";
            this->textBoxName->Size = System::Drawing::Size(200, 20);
            this->textBoxName->TabIndex = 0;
            // 
            // textBoxDate
            // 
            this->textBoxDate->Location = System::Drawing::Point(30, 70);
            this->textBoxDate->Name = L"textBoxDate";
            this->textBoxDate->Size = System::Drawing::Size(200, 20);
            this->textBoxDate->TabIndex = 1;
            // 
            // textBoxDescription
            // 
            this->textBoxDescription->Location = System::Drawing::Point(30, 110);
            this->textBoxDescription->Name = L"textBoxDescription";
            this->textBoxDescription->Size = System::Drawing::Size(200, 20);
            this->textBoxDescription->TabIndex = 2;
            // 
            // buttonSave
            // 
            this->buttonSave->Location = System::Drawing::Point(91, 169);
            this->buttonSave->Name = L"buttonSave";
            this->buttonSave->Size = System::Drawing::Size(75, 23);
            this->buttonSave->TabIndex = 4;
            this->buttonSave->Text = L"Save";
            this->buttonSave->UseVisualStyleBackColor = true;
            this->buttonSave->Click += gcnew System::EventHandler(this, &EventEditAddForm::OnSaveClick);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(27, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(35, 13);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Name";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(27, 54);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(30, 13);
            this->label2->TabIndex = 6;
            this->label2->Text = L"Date";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(27, 94);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(60, 13);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Description";
            // 
            // EventEditAddForm
            // 
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBoxName);
            this->Controls->Add(this->textBoxDate);
            this->Controls->Add(this->textBoxDescription);
            this->Controls->Add(this->buttonSave);
            this->Name = L"EventEditAddForm";
            this->Text = L"Event Edit/Add";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        void OnSaveClick(System::Object^ sender, System::EventArgs^ e) {
            auto eventService = ServiceContainer::getService<EventService>();

            if (eventService == nullptr) {
                MessageBox::Show("Event service is not available!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Validate inputs
            if (String::IsNullOrWhiteSpace(textBoxName->Text) ||
                String::IsNullOrWhiteSpace(textBoxDate->Text) ||
                String::IsNullOrWhiteSpace(textBoxDescription->Text)
                ) {
                MessageBox::Show("All fields must be filled!", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }


            // Retrieve data from text boxes
            std::string name = msclr::interop::marshal_as<std::string>(textBoxName->Text);
            std::string date = msclr::interop::marshal_as<std::string>(textBoxDate->Text);
            std::string description = msclr::interop::marshal_as<std::string>(textBoxDescription->Text);

            try {
                if (isEditMode && existingEvent) {
                    existingEvent->setName(name);
                    existingEvent->setDateString(date);
                    existingEvent->setDescription(description);
                    //eventService->update(existingEvent->getId(), *existingEvent);
                    MessageBox::Show("Event updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
                else {
                    int newId = eventService->readAll().size() + 1; // Example ID generation (should be improved)
                    eventService->insert(Event(newId, name, date, description));
                    MessageBox::Show("Event added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }

                this->Close();
            }
            catch (const std::exception& ex) {
                MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

    };
}
