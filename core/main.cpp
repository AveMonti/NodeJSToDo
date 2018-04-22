#include <iostream>
#include <string>
#include <curl/curl.h>
#include "includes/TaskReq.h"

int main() {
    std::cout<< "Start" << std::endl;
    TaskReq req = TaskReq();
    req.getTasks();

    return 0;
}