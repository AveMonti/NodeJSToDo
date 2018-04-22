//
// Created by Mateusz Chojnacki on 22.04.2018.
//

#include "../includes/Tasks.h"

Tasks::Tasks(){
    taskCount = 0;
}

void Tasks::addTask(Task _task){
    tasksList.push_back(_task);
    taskCount++;
}

std::list<Task> Tasks::getTasksList() {
    return tasksList;
}

int Tasks::getCountList() {
    return taskCount;
}
