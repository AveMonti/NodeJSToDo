//
// Created by Mateusz Chojnacki on 22.04.2018.
//

#ifndef CORE_TASKREQ_H
#define CORE_TASKREQ_H

#include <curl/curl.h>
#include <rapidjson/document.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <memory>

#include "Tasks.h"
#define staticUrl "http://localhost:3000/tasks/"

class TaskReq {
    CURL *curl;
    CURLcode res;
    std::string response;
    Tasks *tasks;

public:
    TaskReq();
    Task getTask(std::string key);
    Tasks getTasks();

};


#endif //CORE_TASKREQ_H
