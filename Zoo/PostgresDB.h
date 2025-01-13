#ifndef POSTGRES_DB_H
#define POSTGRES_DB_H

#include <iostream>
#include <pqxx/pqxx>

class PostgresDB {
private:
    std::string connection_string;
    pqxx::connection *conn;

public:
    PostgresDB(const std::string &host, const std::string &port, const std::string &dbname, const std::string &user, const std::string &password);

    ~PostgresDB();

    pqxx::result executeQuery(const std::string &query);

    bool registerUser(const std::string &username, const std::string &password, const std::string &role);
    bool loginUser(const std::string &username, const std::string &password);
    std::string getUserRole(const std::string &username);
};

#endif
