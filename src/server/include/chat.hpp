#pragma once

#include "session.hpp"
#include <unordered_map>
#include <memory>

class Session;

class Chat{

public:
int counter = 0;
std::unordered_map<int, std::shared_ptr<Session>> users;
private:

};


