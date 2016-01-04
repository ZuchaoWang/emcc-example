#ifndef MYCLASS_H
#define MYCLASS_H

#include <unordered_map>

class MyClass {
public:
    MyClass ();
    ~MyClass ();
    void setValue(float _x);
    float getAnswer();
    
private:
    float x;
};

class MyClassManager {
private:
    MyClassManager();
    ~MyClassManager();
private:
    std::unordered_map<int, MyClass*> instanceMap;
    int nextID;
public:
    MyClass* getMyClass(int _id);
    int createMyClass();
    void deleteMyClass(int _id);
    
public:
    static MyClassManager* getInstance();
private:
    static MyClassManager instance;
};

int createMyClass();
void deleteMyClass(int _id);
void setMyClassValue(int _id, float _x);
float getMyClassAnswer(int _id);

#endif