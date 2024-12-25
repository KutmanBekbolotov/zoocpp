#pragma once
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "DashboardAnimalForm.h"

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для LoginForm
	/// </summary>
	public ref class LoginSignUpForm : public System::Windows::Forms::Form
	{
	public:
		LoginSignUpForm(void)
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
		~LoginSignUpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelPhone;
	protected:

	private: System::Windows::Forms::Label^ labelPassw;
	private: System::Windows::Forms::TextBox^ textBoxPhone;
	private: System::Windows::Forms::TextBox^ textBoxPassw;
	private: System::Windows::Forms::Button^ buttonSubmit;
	private: System::Windows::Forms::Label^ labelSwitch;
	private: System::Windows::Forms::TextBox^ textBoxName;




	private: System::Windows::Forms::Label^ labelName;





	protected:


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
			this->labelPhone = (gcnew System::Windows::Forms::Label());
			this->labelPassw = (gcnew System::Windows::Forms::Label());
			this->textBoxPhone = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPassw = (gcnew System::Windows::Forms::TextBox());
			this->buttonSubmit = (gcnew System::Windows::Forms::Button());
			this->labelSwitch = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelPhone
			// 
			this->labelPhone->AutoSize = true;
			this->labelPhone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPhone->Location = System::Drawing::Point(432, 112);
			this->labelPhone->Name = L"labelPhone";
			this->labelPhone->Size = System::Drawing::Size(158, 25);
			this->labelPhone->TabIndex = 0;
			this->labelPhone->Text = L"Phone number:";
			// 
			// labelPassw
			// 
			this->labelPassw->AutoSize = true;
			this->labelPassw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPassw->Location = System::Drawing::Point(432, 205);
			this->labelPassw->Name = L"labelPassw";
			this->labelPassw->Size = System::Drawing::Size(112, 25);
			this->labelPassw->TabIndex = 1;
			this->labelPassw->Text = L"Password:";
			// 
			// textBoxPhone
			// 
			this->textBoxPhone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxPhone->Location = System::Drawing::Point(437, 140);
			this->textBoxPhone->Name = L"textBoxPhone";
			this->textBoxPhone->Size = System::Drawing::Size(327, 29);
			this->textBoxPhone->TabIndex = 2;
			// 
			// textBoxPassw
			// 
			this->textBoxPassw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxPassw->Location = System::Drawing::Point(437, 233);
			this->textBoxPassw->Name = L"textBoxPassw";
			this->textBoxPassw->Size = System::Drawing::Size(327, 29);
			this->textBoxPassw->TabIndex = 3;
			// 
			// buttonSubmit
			// 
			this->buttonSubmit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSubmit->Location = System::Drawing::Point(530, 443);
			this->buttonSubmit->Name = L"buttonSubmit";
			this->buttonSubmit->Size = System::Drawing::Size(140, 40);
			this->buttonSubmit->TabIndex = 4;
			this->buttonSubmit->Text = L"Sign in";
			this->buttonSubmit->UseVisualStyleBackColor = true;
			this->buttonSubmit->Click += gcnew System::EventHandler(this, &LoginSignUpForm::submit);
			// 
			// labelSwitch
			// 
			this->labelSwitch->AutoSize = true;
			this->labelSwitch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSwitch->Location = System::Drawing::Point(559, 498);
			this->labelSwitch->Name = L"labelSwitch";
			this->labelSwitch->Size = System::Drawing::Size(85, 25);
			this->labelSwitch->TabIndex = 5;
			this->labelSwitch->Text = L"Sign up";
			this->labelSwitch->Click += gcnew System::EventHandler(this, &LoginSignUpForm::switchToSignUpForm);
			// 
			// textBoxName
			// 
			this->textBoxName->Enabled = false;
			this->textBoxName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxName->Location = System::Drawing::Point(437, 319);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(323, 29);
			this->textBoxName->TabIndex = 7;
			this->textBoxName->Visible = false;
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Enabled = false;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelName->Location = System::Drawing::Point(432, 291);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(74, 25);
			this->labelName->TabIndex = 6;
			this->labelName->Text = L"Name:";
			this->labelName->Visible = false;
			// 
			// LoginSignUpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 761);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->labelSwitch);
			this->Controls->Add(this->buttonSubmit);
			this->Controls->Add(this->textBoxPassw);
			this->Controls->Add(this->textBoxPhone);
			this->Controls->Add(this->labelPassw);
			this->Controls->Add(this->labelPhone);
			this->Name = L"LoginSignUpForm";
			this->Padding = System::Windows::Forms::Padding(10);
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		System::Void submit(System::Object^ sender, System::EventArgs^ e) {
			std::string source = msclr::interop::marshal_as<std::string>(this->buttonSubmit->Text);
			std::string phone = msclr::interop::marshal_as<std::string>(this->textBoxPhone->Text);
			std::string password = msclr::interop::marshal_as<std::string>(this->textBoxPassw->Text);
			if (source == "Sign up") {
				std::string name = msclr::interop::marshal_as<std::string>(this->textBoxName->Text);
				std::cout << phone + ", " + password + ", " + name << "\n";
				switchToSignUpForm(sender, e);
			}
			else {
				if (phone == "+996778393607" && password == "user1") {
					std::cout << "You signed in\n";
					this->Hide();
					DashboardAnimalForm ^dashboardForm = gcnew DashboardAnimalForm();
					dashboardForm->ShowDialog();
				}
			}
		}

		System::Void switchToSignUpForm(System::Object^ sender, System::EventArgs^ e) {
			std::string source = msclr::interop::marshal_as<std::string>(this->labelSwitch->Text);
			if (source == "Sign up") {
				this->labelName->Visible = true;
				this->labelName->Enabled = true;
				this->textBoxName->Visible = true;
				this->textBoxName->Enabled = true;
				this->labelSwitch->Text = L"Sign in";
				this->buttonSubmit->Text = L"Sign up";
			}
			else {
				this->labelName->Visible = false;
				this->labelName->Enabled = false;
				this->textBoxName->Visible = false;
				this->textBoxName->Enabled = false;
				this->labelSwitch->Text = L"Sign up";
				this->buttonSubmit->Text = L"Sign in";

			}
			
		}


};
}
