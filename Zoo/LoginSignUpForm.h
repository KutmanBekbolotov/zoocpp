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

	public ref class LoginSignUpForm : public System::Windows::Forms::Form
	{
	public:
		LoginSignUpForm(void)
		{
			InitializeComponent();
		}

	protected:
		~LoginSignUpForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ labelPhone;
		System::Windows::Forms::Label^ labelPassw;
		System::Windows::Forms::TextBox^ textBoxPhone;
		System::Windows::Forms::TextBox^ textBoxPassw;
		System::Windows::Forms::Button^ buttonSubmit;
		System::Windows::Forms::Label^ labelSwitch;
		System::Windows::Forms::TextBox^ textBoxName;
		System::Windows::Forms::Label^ labelName;

		System::ComponentModel::Container ^components;

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
			
			this->labelName->Visible = false;
			this->textBoxName->Visible = false;

			this->labelSwitch->Click += gcnew System::EventHandler(this, &LoginSignUpForm::switchToSignUpForm);
			this->buttonSubmit->Click += gcnew System::EventHandler(this, &LoginSignUpForm::submit);
		}

		System::Void submit(System::Object^ sender, System::EventArgs^ e) {
			std::string action = msclr::interop::marshal_as<std::string>(this->buttonSubmit->Text);
			std::string phone = msclr::interop::marshal_as<std::string>(this->textBoxPhone->Text);
			std::string password = msclr::interop::marshal_as<std::string>(this->textBoxPassw->Text);

			if (action == "Sign up") {
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
				else {
					MessageBox::Show("Invalid phone number or password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

		System::Void switchToSignUpForm(System::Object^ sender, System::EventArgs^ e) {
			std::string action = msclr::interop::marshal_as<std::string>(this->labelSwitch->Text);
			if (action == "Sign up") {
				this->labelName->Visible = true;
				this->textBoxName->Visible = true;
				this->labelSwitch->Text = L"Sign in";
				this->buttonSubmit->Text = L"Sign up";
			}
			else {
				this->labelName->Visible = false;
				this->textBoxName->Visible = false;
				this->labelSwitch->Text = L"Sign up";
				this->buttonSubmit->Text = L"Sign in";
			}
		}
	};
}