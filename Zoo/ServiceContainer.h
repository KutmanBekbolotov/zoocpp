#pragma once
#include "CrudOperations.h"
#include <unordered_map>
#include <typeindex>

// Static service container for managing and accessing services
class ServiceContainer {
private:
    static std::unordered_map<std::type_index, std::shared_ptr<void>> services;

public:
    template<typename ServiceType, typename... Args>
    static void registerService(Args&&... args) {
        auto service = std::make_shared<ServiceType>(std::forward<Args>(args)...);
        services[typeid(ServiceType)] = service;
    }

    template<typename ServiceType>
    static std::shared_ptr<ServiceType> getService() {
        auto it = services.find(typeid(ServiceType));
        if (it != services.end()) {
            return std::static_pointer_cast<ServiceType>(it->second);
        }
        throw std::runtime_error("Service not found");
    }
};