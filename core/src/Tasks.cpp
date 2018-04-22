//
// Created by Mateusz Chojnacki on 22.04.2018.
//

#include "../includes/Tasks.h"

Tasks::Tasks(std::list<Task> *_tasksList):
        tasksList(_tasksList),
        taskCount(_tasksList->size()) {}

std::list<Task> * Tasks::getTasksList() {
    return tasksList;
}

int Tasks::getCountList() {
    return taskCount;
}
