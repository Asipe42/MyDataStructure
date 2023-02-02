#pragma once
#include<list>

using namespace std;

/*
 * 스택, 큐, 덱은 삽입 삭제가 빈번할 가능성이 높다.
 * 따라서 내부적으로 연결 리스트를 기반으로 구현한다.
 *
 * (안정성을 고려해 std::list를 이용한다)
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
