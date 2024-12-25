#pragma once
#include "Model.h"
#include "ServiceContainer.h"
#include <msclr/marshal_cppstd.h>

namespace Zoo {

    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Form for editing or adding an animal.
    /// </summary>
    public ref class AnimalEditAddForm : public System::Windows::Forms::Form
    {
    private:
        Animal* existingAnimal;
        bool isEditMode;

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::TextBox^ textBoxSpecies;
        System::Windows::Forms::TextBox^ textBoxAge;
        System::Windows::Forms::TextBox^ textBoxRation;
        System::Windows::Forms::TextBox^ textBoxLivingEnvironment;
        System::Windows::Forms::Button^ buttonSave;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;

    public:
        AnimalEditAddForm(Animal* animal) {
            InitializeComponent();
            this->isEditMode = (animal != nullptr);
            this->existingAnimal = animal;

            if (isEditMode && existingAnimal) {
                // Pre-fill text boxes with existing animal data
                this->textBoxSpecies->Text = gcnew String(existingAnimal->getSpecies().c_str());
                this->textBoxAge->Text = existingAnimal->getAge().ToString();
                this->textBoxRation->Text = gcnew String(existingAnimal->getRation().c_str());
                this->textBoxLivingEnvironment->Text = gcnew String(existingAnimal->getLivingEnvironment().c_str());
            }
        }

    protected:
        ~AnimalEditAddForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->textBoxSpecies = (gcnew System::Windows::Forms::TextBox());
            this->textBoxAge = (gcnew System::Windows::Forms::TextBox());
            this->textBoxRation = (gcnew System::Windows::Forms::TextBox());
            this->textBoxLivingEnvironment = (gcnew System::Windows::Forms::TextBox());
            this->buttonSave = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBoxSpecies
            // 
            this->textBoxSpecies->Location = System::Drawing::Point(30, 30);
            this->textBoxSpecies->Name = L"textBoxSpecies";
            this->textBoxSpecies->Size = System::Drawing::Size(200, 20);
            this->textBoxSpecies->TabIndex = 0;
            // 
            // textBoxAge
            // 
            this->textBoxAge->Location = System::Drawing::Point(30, 70);
            this->textBoxAge->Name = L"textBoxAge";
            this->textBoxAge->Size = System::Drawing::Size(200, 20);
            this->textBoxAge->TabIndex = 1;
            // 
            // textBoxRation
            // 
            this->textBoxRation->Location = System::Drawing::Point(30, 110);
            this->textBoxRation->Name = L"textBoxRation";
            this->textBoxRation->Size = System::Drawing::Size(200, 20);
            this->textBoxRation->TabIndex = 2;
            // 
            // textBoxLivingEnvironment
            // 
            this->textBoxLivingEnvironment->Location = System::Drawing::Point(30, 150);
            this->textBoxLivingEnvironment->Name = L"textBoxLivingEnvironment";
            this->textBoxLivingEnvironment->Size = System::Drawing::Size(200, 20);
            this->textBoxLivingEnvironment->TabIndex = 3;
            // 
            // buttonSave
            // 
            this->buttonSave->Location = System::Drawing::Point(91, 194);
            this->buttonSave->Name = L"buttonSave";
            this->buttonSave->Size = System::Drawing::Size(75, 23);
            this->buttonSave->TabIndex = 4;
            this->buttonSave->Text = L"Save";
            this->buttonSave->UseVisualStyleBackColor = true;
            this->buttonSave->Click += gcnew System::EventHandler(this, &AnimalEditAddForm::OnSaveClick);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(27, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(45, 13);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Species";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(27, 54);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(26, 13);
            this->label2->TabIndex = 6;
            this->label2->Text = L"Age";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(27, 94);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(38, 13);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Ration";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(27, 134);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(96, 13);
            this->label4->TabIndex = 8;
            this->label4->Text = L"Living environment";
            // 
            // AnimalEditAddForm
            // 
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBoxSpecies);
            this->Controls->Add(this->textBoxAge);
            this->Controls->Add(this->textBoxRation);
            this->Controls->Add(this->textBoxLivingEnvironment);
            this->Controls->Add(this->buttonSave);
            this->Name = L"AnimalEditAddForm";
            this->Text = L"Animal Edit/Add";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        void OnSaveClick(System::Object^ sender, System::EventArgs^ e) {
            auto animalService = ServiceContainer::getService<AnimalService>();

            if (animalService == nullptr) {
                MessageBox::Show("Animal service is not available!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Validate inputs
            if (String::IsNullOrWhiteSpace(textBoxSpecies->Text) ||
                String::IsNullOrWhiteSpace(textBoxAge->Text) ||
                String::IsNullOrWhiteSpace(textBoxRation->Text) ||
                String::IsNullOrWhiteSpace(textBoxLivingEnvironment->Text)) {
                MessageBox::Show("All fields must be filled!", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            int age;
            if (!Int32::TryParse(textBoxAge->Text, age) || age < 0) {
                MessageBox::Show("Age must be a valid non-negative integer!", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Retrieve data from text boxes
            std::string species = msclr::interop::marshal_as<std::string>(textBoxSpecies->Text);
            std::string ration = msclr::interop::marshal_as<std::string>(textBoxRation->Text);
            std::string livingEnvironment = msclr::interop::marshal_as<std::string>(textBoxLivingEnvironment->Text);

            try {
                if (isEditMode && existingAnimal) {
                    existingAnimal->setSpecies(species);
                    existingAnimal->setAge(age);
                    existingAnimal->setRation(ration);
                    existingAnimal->setLivingEnvironment(livingEnvironment);
                    animalService->update(existingAnimal->getId(), *existingAnimal);
                    MessageBox::Show("Animal updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
                else {
                    int newId = animalService->readAll().size() + 1; // Example ID generation (should be improved)
                    animalService->insert(Animal(newId, species, age, ration, livingEnvironment));
                    MessageBox::Show("Animal added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }

                this->Close();
            }
            catch (const std::exception& ex) {
                MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    };
}
