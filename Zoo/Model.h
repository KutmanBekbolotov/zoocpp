#pragma once
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

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

    Event(int id, const std::string& name, std::string date, const std::string& description)
        : id(id), name(name), description(description) {
        setDateString(date);
    }

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

    std::string getDateString() const {
        std::tm* tm = std::localtime(&date); // Convert to local time
        char buffer[100]; // Buffer to hold the formatted string
        std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", tm);
        return std::string(buffer);
    }

    void setDateString(const std::string& dateTimeStr) {
        std::tm tm = {}; // Initialize to zero
        std::istringstream ss(dateTimeStr);
        ss >> std::get_time(&tm, "%d-%m-%Y %H:%M:%S");
        if (ss.fail()) {
            throw std::invalid_argument("Invalid date/time format");
        }
        date = std::mktime(&tm);
    }
};

class User {
private:
    int id;
    std::string name;
    std::string phoneNumber;
    std::string password;
    std::string role;

public:
    User(int id, std::string name, std::string phoneNumber, std::string password, std::string role)
        : id(id), name(name), phoneNumber(std::move(phoneNumber)), password(std::move(password)), role(std::move(role)) {}

    int getId() const {
        return id;
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
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

