#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "������A��Ĭ�Ϲ��캯��:" << std::endl;
		std::cout << "A()" << std::endl;
	}

	A(int i) :n(i)
	{
		std::cout << "������A�Ĺ��캯��:" << std::endl;
		std::cout << "A()" << std::endl;
	}

	A(A& a)
	{
		n = a.n;
		std::cout << "������A�Ŀ������캯��:" << std::endl;
		std::cout << "A(A& a)" << std::endl;
	}

	A(A&& a)
	{
		n = a.n;
		std::cout << "������A���ƶ����캯��:" << std::endl;
		std::cout << "A(A& a" << std::endl;
	}

	A& operator=(const A& a)
	{
		n = a.n;
		std::cout << "������A�Ŀ�����ֵ�����:" << std::endl;
		std::cout << "A& operator=(const A& a)" << std::endl;
		return *this;
	}

	A& operator=(A&& a)
	{
		n = a.n;
		std::cout << "������A���ƶ���ֵ�����:" << std::endl;
		std::cout << "A& operator=(A&& a)" << std::endl;
		return *this;
	}
private:
	int n;
};

int main()
{
	std::cout << "--------------------1--------------------" << std::endl;
	A a;
	std::cout << "--------------------2--------------------" << std::endl;
	A aa(18);
	std::cout << "--------------------3--------------------" << std::endl;
	A aaa(a);
	std::cout << "--------------------4--------------------" << std::endl;
	A aaaa = a;
	std::cout << "--------------------5--------------------" << std::endl;
	aaaa = a;
	std::cout << "--------------------6--------------------" << std::endl;
	aaaa = std::move(a);
	std::cout << "--------------------7--------------------" << std::endl;
	A aaaaaa = std::move(a);
	std::cout << "--------------------8--------------------" << std::endl;
	A aaaaaaa(std::move(a));
	std::cout << "--------------------9--------------------" << std::endl;
}