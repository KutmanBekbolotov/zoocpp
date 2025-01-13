#include "PostgresDB.h"
#include <bcrypt/BCrypt.hpp>

PostgresDB::PostgresDB(const std::string &host, const std::string &port, const std::string &dbname, const std::string &user, const std::string &password) {
    connection_string = "host=" + host + " port=" + port + " dbname=" + dbname + " user=" + user + " password=" + password;
    try {
        conn = new pqxx::connection(connection_string);
        if (conn->is_open()) {
            std::cout << "Connected to database successfully!\n";
        } else {
            throw std::runtime_error("Failed to connect to database.");
        }
    } catch (const std::exception &e) {
        std::cerr << "Database connection error: " << e.what() << std::endl;
        conn = nullptr;
    }
}

PostgresDB::~PostgresDB() {
    if (conn) {
        conn->disconnect();
        delete conn;
        std::cout << "Disconnected from database.\n";
    }
}

pqxx::result PostgresDB::executeQuery(const std::string &query) {
    if (!conn || !conn->is_open()) {
        throw std::runtime_error("Database connection is not open.");
    }

    try {
        pqxx::work txn(*conn);
        pqxx::result result = txn.exec(query);
        txn.commit();
        return result;
    } catch (const std::exception &e) {
        std::cerr << "Query execution error: " << e.what() << std::endl;
        throw;
    }
}

bool PostgresDB::registerUser(const std::string &username, const std::string &password, const std::string &role) {
    try {
        pqxx::work txn(*conn);
        std::string hashed_password = bcrypt::generateHash(password);
        std::string query = "INSERT INTO users (username, password_hash, role) VALUES (" +
                            txn.quote(username) + ", " +
                            txn.quote(hashed_password) + ", " +
                            txn.quote(role) + ")";
        txn.exec(query);
        txn.commit();
        return true;
    } catch (const std::exception &e) {
        std::cerr << "Registration error: " << e.what() << std::endl;
        return false;
    }
}

bool PostgresDB::loginUser(const std::string &username, const std::string &password) {
    try {
        pqxx::work txn(*conn);
        auto result = txn.exec("SELECT password_hash FROM users WHERE username = " + txn.quote(username));
        if (result.size() == 1) {
            std::string stored_hash = result[0]["password_hash"].c_str();
            return bcrypt::validatePassword(password, stored_hash);
        }
        return false;
    } catch (const std::exception &e) {
        std::cerr << "Login error: " << e.what() << std::endl;
        return false;
    }
}

std::string PostgresDB::getUserRole(const std::string &username) {
    try {
        pqxx::work txn(*conn);
        auto result = txn.exec("SELECT role FROM users WHERE username = " + txn.quote(username));
        if (!result.empty()) {
            return result[0]["role"].c_str();
        }
        return "";
    } catch (const std::exception &e) {
        std::cerr << "Get role error: " << e.what() << std::endl;
        return "";
    }
}
