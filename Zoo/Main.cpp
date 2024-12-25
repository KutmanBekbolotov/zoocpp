#include "LoginSignUpForm.h"
#include "ServiceContainer.h"

using namespace System;
using namespace System::Windows::Forms;

// Declare functions before usage
void initServices();
void populateDB();

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    Zoo::LoginSignUpForm form;
    initServices(); // Call the function after declaration
    Application::Run(% form);
}

void initServices() {
    // Register services
    ServiceContainer::registerService<AnimalService>();
    ServiceContainer::registerService<EventService>();
    ServiceContainer::registerService<UserService>();

    populateDB();
}

void populateDB() {
    // Populate the database with initial data
    auto animalService = ServiceContainer::getService<AnimalService>();

    animalService->insert(Animal(1, "Lion", 4, "Meat", "Africa"));
    animalService->insert(Animal(2, "Zebra", 2, "Grass", "Africa"));

    auto eventService = ServiceContainer::getService<EventService>();
    std::time_t currentTime = std::time(nullptr);
    eventService->insert(Event(1, "Zoo event", currentTime, "Greet event"));
}