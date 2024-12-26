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


	public ref class DashboardVisitorsForm : public System::Windows::Forms::Form
	{
	public:
		Form^ dashboardAnimalForm;
		Form^ dashboardEventForm;
		DashboardVisitorsForm(void)
		{
			InitializeComponent();
			loadVisitors();
			//
			//TODO: добавьте код конструктора
			//
		}
		DashboardVisitorsForm(Form^ dashboardAnimalForm)
		{
			this->dashboardAnimalForm = dashboardAnimalForm;
			InitializeComponent();
			loadVisitors();
		}

		void setDashboardEventForm(Form^ dashboardEventForm) {
			this->dashboardEventForm = dashboardEventForm;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DashboardVisitorsForm()
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
	private: System::Windows::Forms::DataGridView^ dataVisitors;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnPhone;
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
			this->dataVisitors = (gcnew System::Windows::Forms::DataGridView());
			this->columnId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnPhone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnDelete = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataVisitors))->BeginInit();
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
			this->labelUser->ForeColor = System::Drawing::SystemColors::Highlight;
			this->labelUser->Location = System::Drawing::Point(53, 231);
			this->labelUser->Name = L"labelUser";
			this->labelUser->Size = System::Drawing::Size(92, 29);
			this->labelUser->TabIndex = 2;
			this->labelUser->Text = L"Visitors";
			this->labelUser->Click += gcnew System::EventHandler(this, &DashboardVisitorsForm::loadVisitors);
			// 
			// labelEvent
			// 
			this->labelEvent->AutoSize = true;
			this->labelEvent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelEvent->ForeColor = System::Drawing::SystemColors::ControlText;
			this->labelEvent->Location = System::Drawing::Point(53, 181);
			this->labelEvent->Name = L"labelEvent";
			this->labelEvent->Size = System::Drawing::Size(85, 29);
			this->labelEvent->TabIndex = 1;
			this->labelEvent->Text = L"Events";
			this->labelEvent->Click += gcnew System::EventHandler(this, &DashboardVisitorsForm::switchToEvents);
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
			this->labelAnimal->Click += gcnew System::EventHandler(this, &DashboardVisitorsForm::switchToAnimal);
			// 
			// dataVisitors
			// 
			this->dataVisitors->AllowUserToAddRows = false;
			this->dataVisitors->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataVisitors->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataVisitors->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->columnId,
					this->columnName, this->columnPhone, this->columnDelete
			});
			this->dataVisitors->Location = System::Drawing::Point(400, 32);
			this->dataVisitors->Name = L"dataVisitors";
			this->dataVisitors->Size = System::Drawing::Size(593, 516);
			this->dataVisitors->TabIndex = 1;
			this->dataVisitors->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DashboardVisitorsForm::OnCellContentClick);
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
			this->columnName->Width = 250;
			// 
			// columnPhone
			// 
			this->columnPhone->HeaderText = L"Phone number";
			this->columnPhone->Name = L"columnPhone";
			this->columnPhone->Width = 150;
			// 
			// columnDelete
			// 
			this->columnDelete->HeaderText = L"";
			this->columnDelete->Name = L"columnDelete";
			// 
			// DashboardVisitorsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 761);
			this->Controls->Add(this->dataVisitors);
			this->Controls->Add(this->panel1);
			this->Name = L"DashboardVisitorsForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataVisitors))->EndInit();
			this->ResumeLayout(false);

		};

		void OnCellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0) {
				// Retrieve the ID directly from the "ID" column
				int eventId = Convert::ToInt32(this->dataVisitors->Rows[e->RowIndex]->Cells["columnId"]->Value);

				if (e->ColumnIndex == this->columnDelete->Index) {
					HandleDeleteClick(eventId);
				}
			}
		}

		void HandleDeleteClick(int id) {
			try {
				auto eventService = ServiceContainer::getService<EventService>();

				eventService->deleteRecord(id);

				// Refresh the grid
				loadVisitors();
			}
			catch (const std::exception& ex) {
				MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

#pragma endregion
		void loadVisitors()
		{
			try
			{
				auto userService = ServiceContainer::getService<UserService>();
				this->dataVisitors->Rows->Clear();

				for (User visitor : userService->readAllVisitor())
				{
					this->dataVisitors->Rows->Add(gcnew array<Object^> {
							visitor.getId(),
							gcnew String(visitor.getName().c_str()),
							gcnew String(visitor.getPhoneNumber().c_str()),
							L"Delete"
					});
				}
			}
			catch (const std::exception& ex)
			{
				MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void loadVisitors(System::Object^ sender, System::EventArgs^ e) {
			loadVisitors();
		}

		void switchToAnimal(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
			dashboardAnimalForm->Show();
		}

		void switchToEvents(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
			dashboardEventForm->Show();
		}
};
}
