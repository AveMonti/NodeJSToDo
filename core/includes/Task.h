//
// Created by Mateusz Chojnacki on 22.04.2018.
//

#ifndef CORE_TASK_H
#define CORE_TASK_H

#include <string>

class Task {
    std::string id = "";
    std::string name;
    int isDone;
public:
    Task(std::string _id, std::string _name,int _isDone);
    Task(std::string _name,int _isDone);
    std::string getId();
    std::string getName();
    int getIsDone();
};


#endif //CORE_TASK_H
