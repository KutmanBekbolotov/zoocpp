#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Zoo {

	/// <summary>
	/// Сводка для AnimalControl
	/// </summary>
	public ref class AnimalControl : public System::Windows::Forms::UserControl
	{
	public:
		AnimalControl(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AnimalControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnSpecies;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnAge;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnRation;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnLivEnv;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnEdit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnDelete;
	protected:





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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->columnSpecies = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnAge = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnRation = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnLivEnv = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnEdit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnDelete = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->columnSpecies,
					this->columnAge, this->columnRation, this->columnLivEnv, this->columnEdit, this->columnDelete
			});
			this->dataGridView1->Location = System::Drawing::Point(55, 17);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(900, 516);
			this->dataGridView1->TabIndex = 0;
			// 
			// columnSpecies
			// 
			this->columnSpecies->Frozen = true;
			this->columnSpecies->HeaderText = L"Species";
			this->columnSpecies->MinimumWidth = 100;
			this->columnSpecies->Name = L"columnSpecies";
			this->columnSpecies->Width = 200;
			// 
			// columnAge
			// 
			this->columnAge->Frozen = true;
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
			this->columnLivEnv->Width = 200;
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
			// AnimalControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->dataGridView1);
			this->Name = L"AnimalControl";
			this->Size = System::Drawing::Size(1000, 761);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
	};
}