#pragma once
#include "ServiceContainer.h"
#include "AnimalEditAddForm.h"


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
	public ref class DashboardAnimalForm : public System::Windows::Forms::Form
	{
	public:
		DashboardAnimalForm(void)
		{
			InitializeComponent();
			LoadAnimals();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DashboardAnimalForm()
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
	private: System::Windows::Forms::DataGridView^ dataAnimal;







	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnSpecies;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnAge;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnRation;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnLivEnv;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnEdit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnDelete;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			this->dataAnimal = (gcnew System::Windows::Forms::DataGridView());
			this->columnId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnSpecies = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnAge = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnRation = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnLivEnv = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnEdit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnDelete = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataAnimal))->BeginInit();
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
			// 
			// dataAnimal
			// 
			this->dataAnimal->AllowUserToAddRows = false;
			this->dataAnimal->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataAnimal->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataAnimal->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->columnId,
					this->columnSpecies, this->columnAge, this->columnRation, this->columnLivEnv, this->columnEdit, this->columnDelete
			});
			this->dataAnimal->Location = System::Drawing::Point(224, 28);
			this->dataAnimal->Name = L"dataAnimal";
			this->dataAnimal->Size = System::Drawing::Size(943, 516);
			this->dataAnimal->TabIndex = 1;
			this->dataAnimal->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DashboardAnimalForm::OnCellContentClick);
			// 
			// columnId
			// 
			this->columnId->HeaderText = L"ID";
			this->columnId->Name = L"columnId";
			// 
			// columnSpecies
			// 
			this->columnSpecies->HeaderText = L"Species";
			this->columnSpecies->MinimumWidth = 100;
			this->columnSpecies->Name = L"columnSpecies";
			this->columnSpecies->Width = 200;
			// 
			// columnAge
			// 
			this->columnAge->HeaderText = L"Age";
			this->columnAge->Name = L"columnAge";
			// 
			// columnRation
			// 
			this->columnRation->HeaderText = L"Ration";
			this->columnRation->MinimumWidth = 50;
			this->columnRation->Name = L"columnRation";
			this->columnRation->Width = 150;
			// 
			// columnLivEnv
			// 
			this->columnLivEnv->HeaderText = L"Living environment";
			this->columnLivEnv->MinimumWidth = 50;
			this->columnLivEnv->Name = L"columnLivEnv";
			this->columnLivEnv->Width = 150;
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
			this->buttonAdd->Click += gcnew System::EventHandler(this, &DashboardAnimalForm::OnAddButtonClick);
			// 
			// DashboardAnimalForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 761);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->dataAnimal);
			this->Controls->Add(this->panel1);
			this->Name = L"DashboardAnimalForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataAnimal))->EndInit();
			this->ResumeLayout(false);

		};

		void OnCellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0) {
				// Retrieve the ID directly from the "ID" column
				int animalId = Convert::ToInt32(this->dataAnimal->Rows[e->RowIndex]->Cells["columnId"]->Value);

				// Check if Edit or Delete button was clicked
				if (e->ColumnIndex == this->columnEdit->Index) {
					OpenEditAddForm(true, animalId);
				}
				else if (e->ColumnIndex == this->columnDelete->Index) {
					HandleDeleteClick(animalId);
				}
			}
		}

		void OnAddButtonClick(System::Object^ sender, System::EventArgs^ e) {
			OpenEditAddForm(false, -1); // Add mode
		}

		void OpenEditAddForm(bool isEditMode, int animalId) {
			Animal* existingAnimal = nullptr;

			if (isEditMode) {
				auto animalService = ServiceContainer::getService<AnimalService>();
				auto animalOpt = animalService->findById(animalId);

				if (!animalOpt) {
					MessageBox::Show("Animal not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				existingAnimal = animalOpt->get(); // Use the existing animal
			}

			// Open AnimalEditAddForm
			//AnimalEditAddForm^ form = gcnew AnimalEditAddForm(existingAnimal);
			//form->ShowDialog();

			// Refresh the grid
			LoadAnimals();
		}



		void HandleDeleteClick(int animalId) {
			try {
				auto animalService = ServiceContainer::getService<AnimalService>();

				animalService->deleteRecord(animalId);

				// Refresh the grid
				LoadAnimals();
			}
			catch (const std::exception& ex) {
				MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

#pragma endregion
		void LoadAnimals()
		{
			try
			{
				auto animalService = ServiceContainer::getService<AnimalService>();
				this->dataAnimal->Rows->Clear();

				std::cout << animalService->readAll().size() << "\n";
				for (Animal animal : animalService->readAll())
				{
					this->dataAnimal->Rows->Add(gcnew array<Object^> {
							animal.getId(),
							gcnew String(animal.getSpecies().c_str()),
							animal.getAge(),
							gcnew String(animal.getRation().c_str()),
							gcnew String(animal.getLivingEnvironment().c_str()),
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

	};
}
