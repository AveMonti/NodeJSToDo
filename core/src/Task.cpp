//
// Created by Mateusz Chojnacki on 22.04.2018.
//

#include "../includes/Task.h"

Task::Task(std::string _id, std::string _name, int _isDone):
        id(_id),
        name(_name),
        isDone(_isDone){}


std::string Task::getId() {
    return id;
}

std::string Task::getName() {
    return name;
}

int Task::getIsDone() {
    return isDone;
}