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
class MyQueue
{
private:
	list<T> m_list;
	size_t m_size;

public:
	MyQueue();
	MyQueue(const MyQueue& x);
	~MyQueue();

	bool empty();
	size_t size();
	T& front();
	void push(const T& val);
	void pop();
};

template<typename T>
inline MyQueue<T>::MyQueue()
	: m_size(0)
{
}

template<typename T>
inline MyQueue<T>::MyQueue(const MyQueue& x)
{
	m_list = x.m_list;
	m_size = x.m_size;
}

template<typename T>
inline MyQueue<T>::~MyQueue()
{
}

template<typename T>
inline bool MyQueue<T>::empty()
{
	return m_size == 0 ? true : false;
}

template<typename T>
inline size_t MyQueue<T>::size()
{
	return m_size;
}

template<typename T>
inline T& MyQueue<T>::front()
{
	return m_list.front();
}

template<typename T>
inline void MyQueue<T>::push(const T& val)
{
	m_list.push_front(val);
}

template<typename T>
inline void MyQueue<T>::pop()
{
	m_list.pop_front();
}
