#include <iostream>
#include <string>
#include <curl/curl.h>
#include "includes/TaskReq.h"

int main() {
    std::cout<< "Start" << std::endl;
    TaskReq req = TaskReq();
    //req.getTask("5adc71b5ee6a9804ad76b649");

//    std::cout<<"Tutaj "<<req.getTasks().getCountList()<<std::endl;

    Task newTask = Task("NewTask",0);
    req.addTask(newTask);
    return 0;
}