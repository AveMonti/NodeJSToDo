//
// Created by Mateusz Chojnacki on 22.04.2018.
//

#ifndef CORE_TASKS_H
#define CORE_TASKS_H

#include <string>
#include <string>
#include <list>

#include "Task.h"

class Tasks {
    std::list<Task> tasksList;
    int taskCount;
public:
    Tasks();
    void addTask(Task _task);
    std::list<Task> getTasksList();
    int getCountList();
};


#endif //CORE_TASKS_H
