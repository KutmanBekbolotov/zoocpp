#pragma once
#include <string>
#include <ctime>


class Animal {
private:
    int id;
    std::string species;
    int age;
    std::string ration;
    std::string livingEnvironment;

public:
    Animal(int id, std::string species, int age, std::string ration, std::string livingEnvironment)
        : id(id), species(std::move(species)), age(age), ration(std::move(ration)), livingEnvironment(std::move(livingEnvironment)) {}

    int getId() const {
        return id;
    }

    const std::string& getSpecies() const {
        return species;
    }

    int getAge() const {
        return age;
    }

    const std::string& getRation() const {
        return ration;
    }

    const std::string& getLivingEnvironment() const {
        return livingEnvironment;
    }

    void setSpecies(const std::string& newSpecies) {
        species = newSpecies;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    void setRation(const std::string& newRation) {
        ration = newRation;
    }

    void setLivingEnvironment(const std::string& newEnvironment) {
        livingEnvironment = newEnvironment;
    }
};


class Event {
private:
    int id;
    std::string name;
    std::time_t date;
    std::string description;

public:
    Event(int id, const std::string& name, std::time_t date, const std::string& description)
        : id(id), name(name), date(date), description(description) {}

    int getId() const {
        return id;
    }

    const std::string& getName() const {
        return name;
    }

    std::time_t getDate() const {
        return date;
    }

    const std::string& getDescription() const {
        return description;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    void setDate(std::time_t newDate) {
        date = newDate;
    }

    void setDescription(const std::string& newDescription) {
        description = newDescription;
    }
};

class User {
private:
    int id;
    std::string phoneNumber;
    std::string password;
    std::string role;

public:
    User(int id, std::string phoneNumber, std::string password, std::string role)
        : id(id), phoneNumber(std::move(phoneNumber)), password(std::move(password)), role(std::move(role)) {}

    int getId() const {
        return id;
    }

    const std::string& getPhoneNumber() const {
        return phoneNumber;
    }

    const std::string& getPassword() const {
        return password;
    }

    const std::string& getRole() const {
        return role;
    }

    void setPhoneNumber(const std::string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }

    void setPassword(const std::string& newPassword) {
        password = newPassword;
    }

    void setRole(const std::string& newRole) {
        role = newRole;
    }
};

