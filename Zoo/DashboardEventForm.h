#pragma once
#include "ServiceContainer.h"
#include "EventEditAddForm.h"

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Dashboard
	/// </summary>

	
	public ref class DashboardEventForm : public System::Windows::Forms::Form
	{
	public:
		Form ^dashboardAnimalForm;
		DashboardEventForm(void)
		{
			InitializeComponent();
			LoadEvents();
			//
			//TODO: добавьте код конструктора
			//
		}
		DashboardEventForm(Form^ dashboardAnimalForm)
		{
			this->dashboardAnimalForm = dashboardAnimalForm;
			InitializeComponent();
			LoadEvents();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DashboardEventForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ labelUser;
	private: System::Windows::Forms::Label^ labelEvent;
	private: System::Windows::Forms::Label^ labelAnimal;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;
	private: System::Windows::Forms::DataGridView^ dataEvent;







	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnDescription;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnEdit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnDelete;








	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->labelUser = (gcnew System::Windows::Forms::Label());
			this->labelEvent = (gcnew System::Windows::Forms::Label());
			this->labelAnimal = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->dataEvent = (gcnew System::Windows::Forms::DataGridView());
			this->columnId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnDescription = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnEdit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnDelete = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataEvent))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->labelUser);
			this->panel1->Controls->Add(this->labelEvent);
			this->panel1->Controls->Add(this->labelAnimal);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 761);
			this->panel1->TabIndex = 0;
			// 
			// labelUser
			// 
			this->labelUser->AutoSize = true;
			this->labelUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUser->Location = System::Drawing::Point(53, 231);
			this->labelUser->Name = L"labelUser";
			this->labelUser->Size = System::Drawing::Size(92, 29);
			this->labelUser->TabIndex = 2;
			this->labelUser->Text = L"Visitors";
			// 
			// labelEvent
			// 
			this->labelEvent->AutoSize = true;
			this->labelEvent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelEvent->ForeColor = System::Drawing::SystemColors::Highlight;
			this->labelEvent->Location = System::Drawing::Point(53, 181);
			this->labelEvent->Name = L"labelEvent";
			this->labelEvent->Size = System::Drawing::Size(85, 29);
			this->labelEvent->TabIndex = 1;
			this->labelEvent->Text = L"Events";
			// 
			// labelAnimal
			// 
			this->labelAnimal->AutoSize = true;
			this->labelAnimal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAnimal->Location = System::Drawing::Point(53, 131);
			this->labelAnimal->Name = L"labelAnimal";
			this->labelAnimal->Size = System::Drawing::Size(98, 29);
			this->labelAnimal->TabIndex = 0;
			this->labelAnimal->Text = L"Animals";
			this->labelAnimal->Click += gcnew System::EventHandler(this, &DashboardEventForm::switchToAnimal);
			// 
			// dataEvent
			// 
			this->dataEvent->AllowUserToAddRows = false;
			this->dataEvent->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataEvent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataEvent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->columnId, this->columnName,
					this->columnDate, this->columnDescription, this->columnEdit, this->columnDelete
			});
			this->dataEvent->Location = System::Drawing::Point(320, 28);
			this->dataEvent->Name = L"dataEvent";
			this->dataEvent->Size = System::Drawing::Size(743, 516);
			this->dataEvent->TabIndex = 1;
			this->dataEvent->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DashboardEventForm::OnCellContentClick);
			// 
			// columnId
			// 
			this->columnId->HeaderText = L"ID";
			this->columnId->Name = L"columnId";
			this->columnId->Width = 50;
			// 
			// columnName
			// 
			this->columnName->HeaderText = L"Name";
			this->columnName->MinimumWidth = 100;
			this->columnName->Name = L"columnName";
			this->columnName->Width = 150;
			// 
			// columnDate
			// 
			this->columnDate->HeaderText = L"Date";
			this->columnDate->Name = L"columnDate";
			// 
			// columnDescription
			// 
			this->columnDescription->HeaderText = L"Description";
			this->columnDescription->MinimumWidth = 50;
			this->columnDescription->Name = L"columnDescription";
			this->columnDescription->Width = 200;
			// 
			// columnEdit
			// 
			this->columnEdit->HeaderText = L"";
			this->columnEdit->Name = L"columnEdit";
			// 
			// columnDelete
			// 
			this->columnDelete->HeaderText = L"";
			this->columnDelete->Name = L"columnDelete";
			// 
			// buttonAdd
			// 
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAdd->Location = System::Drawing::Point(622, 602);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(134, 37);
			this->buttonAdd->TabIndex = 2;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &DashboardEventForm::OnAddButtonClick);
			// 
			// DashboardEventForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 761);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->dataEvent);
			this->Controls->Add(this->panel1);
			this->Name = L"DashboardEventForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataEvent))->EndInit();
			this->ResumeLayout(false);

		};

		void OnCellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0) {
				// Retrieve the ID directly from the "ID" column
				int eventId = Convert::ToInt32(this->dataEvent->Rows[e->RowIndex]->Cells["columnId"]->Value);

				// Check if Edit or Delete button was clicked
				if (e->ColumnIndex == this->columnEdit->Index) {
					OpenEditAddForm(true, eventId);
				}
				else if (e->ColumnIndex == this->columnDelete->Index) {
					HandleDeleteClick(eventId);
				}
			}
		}

		void OnAddButtonClick(System::Object^ sender, System::EventArgs^ e) {
			OpenEditAddForm(false, -1); // Add mode
		}

		void OpenEditAddForm(bool isEditMode, int eventId) {
			std::shared_ptr<Event> existingEvent = nullptr;

			if (isEditMode) {
				auto eventService = ServiceContainer::getService<EventService>();
				if (!eventService) {
					MessageBox::Show("Event service not available!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				auto eventOpt = eventService->findById(eventId);
				if (!eventOpt) {
					MessageBox::Show("Event not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				existingEvent = *eventOpt; // Dereference the pointer to assign the actual shared_ptr
			}

			// Create and display the form
			EventEditAddForm^ form = gcnew EventEditAddForm(existingEvent.get());
			form->ShowDialog();

			// Refresh the data grid
			LoadEvents();
		}

		void HandleDeleteClick(int id) {
			try {
				auto eventService = ServiceContainer::getService<EventService>();

				eventService->deleteRecord(id);

				// Refresh the grid
				LoadEvents();
			}
			catch (const std::exception& ex) {
				MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

#pragma endregion
		void LoadEvents()
		{
			try
			{
				auto eventService = ServiceContainer::getService<EventService>();
				this->dataEvent->Rows->Clear();

				for (Event event : eventService->readAll())
				{
					this->dataEvent->Rows->Add(gcnew array<Object^> {
							event.getId(),
							gcnew String(event.getName().c_str()),
							gcnew String(event.getDateString().c_str()),
							gcnew String(event.getDescription().c_str()),
							L"Edit",
							L"Delete"
					});
				}
			}
			catch (const std::exception& ex)
			{
				MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void switchToAnimal(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
			dashboardAnimalForm->Show();
		}
	};
}
