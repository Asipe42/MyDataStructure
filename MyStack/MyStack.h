#pragma once
#include<list>

using namespace std;

/*
 * ����, ť, ���� ���� ������ ����� ���ɼ��� ����.
 * ���� ���������� ���� ����Ʈ�� ������� �����Ѵ�.
 *
 * (�������� ����� std::list�� �̿��Ѵ�)
 */

template<typename T>
class MyStack
{
private:
	list<T> m_list;
	size_t m_size;

public:
	MyStack();
	MyStack(const MyStack& x);
	~MyStack();

	bool empty();
	size_t size();
	T& top();
	void push(const T& val);
	void pop();
};

template<typename T>
inline MyStack<T>::MyStack()
	: m_size(0)
{
}

template<typename T>
inline MyStack<T>::MyStack(const MyStack& x)
{
	m_list = x.m_list;
	m_size = x.m_size;
}

template<typename T>
inline MyStack<T>::~MyStack()
{
}

template<typename T>
inline bool MyStack<T>::empty()
{
	return m_size == 0 ? true : false;
}

template<typename T>
inline size_t MyStack<T>::size()
{
	return m_size;
}

template<typename T>
inline T& MyStack<T>::top()
{
	return m_list.back();
}

template<typename T>
inline void MyStack<T>::push(const T& val)
{
	m_list.push_back(val);
	m_size++;
}

template<typename T>
inline void MyStack<T>::pop()
{
	m_list.pop_back();
	m_size--;
}