#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <optional>
#include "Model.h"
#include <optional>

template<typename DT>
class CrudOperations {
protected:
    std::string tableName;
    std::vector<std::shared_ptr<DT>> data;

public:
    explicit CrudOperations(std::string tableName) : tableName(std::move(tableName)) {}

    void insert(DT object) {
        data.push_back(std::make_shared<DT>(object));
        std::cout << "Record inserted" << std::endl;
    }

    void update(int id, DT object) {
        auto record = findById(id);
        if (record) {
            *record = object;
            std::cout << "Record updated" << std::endl;
        }
        else {
            std::cerr << "Record with ID " << id << " not found" << std::endl;
        }
    }

    void deleteRecord(int id) {
        auto it = std::remove_if(data.begin(), data.end(), [id](std::shared_ptr<DT>& record) {
            return record && record->getId() == id;
            });

        if (it != data.end()) {
            data.erase(it, data.end());
            std::cout << "Record deleted" << std::endl;
        }
        else {
            std::cerr << "Record with ID " << id << " not found" << std::endl;
        }
    }

    std::vector<DT> readAll() {
        std::vector<DT> result;
        for (auto& record : data) {
            if (record) {
                result.push_back(*record);
            }
        }
        return result;
    }


    std::shared_ptr<DT>* findById(int id) {
        for (auto& record : data) {
            if (record && record->getId() == id) {
                return &record;
            }
        }
        return nullptr;
    }
};

class AnimalService : public CrudOperations<Animal> {
public:
    AnimalService() : CrudOperations<Animal>("AnimalTable") {}

    void update(int id, const Animal& object) {
        auto record = findById(id);
        if (record) {
            (*record)->setSpecies(object.getSpecies());
            (*record)->setAge(object.getAge());
            (*record)->setRation(object.getRation());
            (*record)->setLivingEnvironment(object.getLivingEnvironment());
            std::cout << "Record updated" << std::endl;
        }
        else {
            std::cerr << "Record with ID " << id << " not found" << std::endl;
        }
    }

};

class EventService : public CrudOperations<Event> {
public:
    EventService() : CrudOperations<Event>("EventTable") {}
};

class UserService : public CrudOperations<User> {
public:
    UserService() : CrudOperations<User>("UserTable") {}
};