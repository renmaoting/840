#include <iostream>

using namespace std;

typedef int (*Callback)(int);

class Apple
{
public:
	int design(int problem)//苹果的技术部门，即回调函数
    {
        return problem %100;
    }
	void getIphone(int cnt){}
};

class Futukang
{
public:
	int produce(string Iphone, int (*Callback)(int))//函数指针原型：int (*Callback)(int)，指向了一个回调函数
	{
		int ans = Callback(999);//调用回调函数
        return ans;
	}
};

int main()
{
	Apple app;
	Futukang tu;
	int cnt = tu.produce("iphone", );//注册回调函数
	app.getIphone(cnt);//拿走Iphone
}
