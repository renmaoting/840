/*************************************************************************
	> File Name: deleteself.cpp
	> Author: Jonah 
	> Mail: mren@g.clemson.edu
	> Created Time: Thu 04 Feb 2016 03:05:33 PM EST
 ************************************************************************/

#include<iostream>

class Dachui 
{
public:
    typedef void (*Killer)(Dachui*);//函数指针原型
    void suicide(std::string lastWord, Killer killer)
    {
        std::cout << lastWord << std::endl;
        killer(this);
    }
};

void functionPointer(Dachui* chui)
{
    delete chui;
    chui = NULL;
}

int main()
{
    Dachui* dachui= new Dachui();
    dachui->suicide("我爱小美", &functionPointer);    
    return 0;
}

