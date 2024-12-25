#pragma once

namespace Zoo {
	using namespace System;

	public ref class Animal {
	private:
		int id;
		String^ species;
		int age;
		String^ ration;
		String^ livingEnvironment;

	public:
		property int Id {
			int get() { return id; }
			void set(int value) { id = value; }
		}
		property String^ Species {
			String^ get() { return species; }
			void set(String^ value) { species = value; }
		}
		property int Age {
			int get() { return age; }
			void set(int value) { age = value; }
		}
		property String^ Ration {
			String^ get() { return ration; }
			void set(String^ value) { ration = value; }
		}

		property String^ LivingEnvironment {
			String^ get() { return livingEnvironment; }
			void set(String^ value) { livingEnvironment = value; }
		}

		Animal(int id, String^ species, int age, String^ ration, String^ livingEnvironment) {
			this->id = id;
			this->species = species;
			this->age = age;
			this->ration = ration;
			this->livingEnvironment = livingEnvironment;
		}
	};


	public ref class Event {
	private:
		int id;
		String^ name;
		DateTime date;
		String^ description;

	public:
		property int Id {
			int get() { return id; }
			void set(int value) { id = value; }
		}
		property String^ Name {
			String^ get() { return name; }
			void set(String^ value) { name = value; }
		}
		property DateTime EventDate {
			DateTime get() { return date; }
			void set(DateTime value) { date = value; }
		}
		property String^ Description {
			String^ get() { return description; }
			void set(String^ value) { description = value; }
		}

		Event(int id, String^ name, DateTime date, String^ description) {
			this->id = id;
			this->name = name;
			this->date = date;
			this->description = description;
		}
	};


	public ref class User {
	private:
		int id;
		String^ phoneNumber;
		String^ password;
		String^ role;

	public:
		property int Id {
			int get() { return id; }
			void set(int value) { id = value; }
		}
		property String^ PhoneNumber {
			String^ get() { return phoneNumber; }
			void set(String^ value) { phoneNumber = value; }
		}
		property String^ Password {
			String^ get() { return password; }
			void set(String^ value) { password = value; }
		}
		property String^ Role {
			String^ get() { return role; }
			void set(String^ value) { role = value; }
		}

		User(int id, String^ phoneNumber, String^ password, String^ role) {
			this->id = id;
			this->phoneNumber = phoneNumber;
			this->password = password;
			this->role = role;
		}
	};
}