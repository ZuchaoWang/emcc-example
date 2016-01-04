#include "myclass.h"
#include <cmath>

MyClass::MyClass() {
    x = 0;
}

MyClass::~MyClass() {
    
}

void MyClass::setValue(float _x) {
    x = _x;
}

float MyClass::getAnswer() {
    return sqrt(x);
}

MyClassManager::MyClassManager() {
    nextID = 0;
}

MyClassManager::~MyClassManager() {
    for (std::unordered_map<int, MyClass*>::iterator it = instanceMap.begin(); it != instanceMap.end(); ++it ) {
        delete it->second;
    }
}

MyClass* MyClassManager::getMyClass(int _id) {
    return instanceMap[_id];
}

int MyClassManager::createMyClass() {
    int currentID = nextID;
    nextID++;
    instanceMap[currentID] = new MyClass();
    return currentID;
}

void MyClassManager::deleteMyClass(int _id) {
    if (instanceMap.find(_id) != instanceMap.end()) {
        delete instanceMap[_id];
        instanceMap.erase(_id);
    }
}

MyClassManager MyClassManager::instance = MyClassManager();

MyClassManager* MyClassManager::getInstance() {
    return &instance;
}

int createMyClass() {
    return MyClassManager::getInstance()->createMyClass();
}

void deleteMyClass(int _id) {
    MyClassManager::getInstance()->deleteMyClass(_id);
}

void setMyClassValue(int _id, float _x) {
    MyClassManager::getInstance()->getMyClass(_id)->setValue(_x);
}

float getMyClassAnswer(int _id) {
    return MyClassManager::getInstance()->getMyClass(_id)->getAnswer();
}



