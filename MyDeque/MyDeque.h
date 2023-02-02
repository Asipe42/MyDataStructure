#pragma once
#include <memory>

template<typename T>
class MyDeque
{
private:
	size_t m_front;
	size_t m_rear;
	size_t m_size;
	size_t m_maxSize;
	T* m_arr;

	void swap(MyDeque& x, MyDeque& y);

	bool full();

public:
	MyDeque(size_t maxSize = 16);
	MyDeque(const MyDeque& x);
	MyDeque(MyDeque&& x);
	~MyDeque();

	MyDeque& operator=(const MyDeque& x);
	MyDeque& operator=(MyDeque&& x);
	T& operator[](size_t idx);

	size_t size();
	size_t max_size();
	void resize(size_t n);
	void resize(size_t n, const T& val);
	bool empty();
	void shrink_to_fit();

	T& front();
	T& back();

	void push_back(const T& val);
	void push_front(const T& val);
	void pop_back();
	void pop_front();
};

template<typename T>
inline void MyDeque<T>::swap(MyDeque& x, MyDeque& y)
{
	size_t tempFront = x.m_front;
	size_t tempRear = x.m_rear;
	size_t tempSize = x.m_size;
	size_t tempMaxSize = x.m_maxSize;
	T* tempArr = x.m_arr;

	x.m_front = y.m_front;
	x.m_rear = y.m_rear;
	x.m_size = y.m_size;
	x.m_maxSize = y.m_maxSize;
	x.m_arr = y.m_arr;

	y.m_front = tempFront;
	y.m_rear = tempRear;
	y.m_size = tempSize;
	y.m_maxSize = tempMaxSize;
	y.m_arr = tempArr;
}

template<typename T>
inline bool MyDeque<T>::full()
{
	return m_size == m_maxSize ? true : false;
}

template<typename T>
inline MyDeque<T>::MyDeque(size_t maxSize)
	: m_front(0)
	, m_rear(1)
	, m_size(0)
	, m_maxSize(maxSize)
	, m_arr(new T[maxSize])
{
}

template<typename T>
inline MyDeque<T>::MyDeque(const MyDeque& x)
	: m_front(x.m_front)
	, m_rear(x.m_rear)
	, m_size(x.m_size)
	, m_maxSize(x.m_maxSize)
	, m_arr(new T[x.m_maxSize])
{
	memcpy(m_arr, x.m_arr, x.m_size * sizeof(T));
}

template<typename T>
inline MyDeque<T>::MyDeque(MyDeque&& x)
{
	swap(*this, x);
}

template<typename T>
inline MyDeque<T>::~MyDeque()
{
	m_front = 0;
	m_rear = 0;
	m_size = 0;

	delete[] m_arr;
}

template<typename T>
inline MyDeque<T>& MyDeque<T>::operator=(const MyDeque& x)
{
	m_front = x.m_front;
	m_rear = x.m_rear;
	m_size = x.m_size;
	m_maxSize = x.m_maxSize;
	m_arr = new T[x.m_maxSize];

	memcpy(m_arr, x.m_arr, x.m_size * sizeof(T));

	return *this;
}

template<typename T>
inline MyDeque<T>& MyDeque<T>::operator=(MyDeque&& x)
{
	swap(*this, x);

	return *this;
}

template<typename T>
inline T& MyDeque<T>::operator[](size_t idx)
{
	return m_arr[idx];
}

template<typename T>
inline size_t MyDeque<T>::size()
{
	return m_size;
}

template<typename T>
inline size_t MyDeque<T>::max_size()
{
	return m_maxSize;
}

template<typename T>
inline void MyDeque<T>::resize(size_t n)
{
	m_maxSize = n;

	T* temp = new T[m_maxSize];

	for (size_t i = 0; i < m_maxSize; i++)
	{
		if (i >= m_size)
		{
			m_size = i;
			m_rear = i + 1;
			break;
		}

		temp[i] = m_arr[i];
	}

	delete[] m_arr;
	m_arr = temp;
}

template<typename T>
inline void MyDeque<T>::resize(size_t n, const T& val)
{
	m_maxSize = n;

	delete[] m_arr;
	m_arr = new T[m_maxSize];

	for (size_t i = 0; i < m_maxSize; i++)
	{
		if (i >= m_size)
		{
			m_size = i;
			m_rear = i + 1;
			break;
		}

		m_arr[i] = val;
	}
}

template<typename T>
inline bool MyDeque<T>::empty()
{
	return m_size == 0 ? true : false;
}

template<typename T>
inline void MyDeque<T>::shrink_to_fit()
{
	m_maxSize = m_size;

	T* temp = new T[m_maxSize];

	for (size_t i = 0; i < m_maxSize; i++)
		temp[i] = m_arr[i];

	delete[] m_arr;
	m_arr = temp;
}

template<typename T>
inline T& MyDeque<T>::front()
{
	if (empty())
		return;

	size_t index = ((m_front + 1) % m_maxSize);
	return m_arr[index];
}

template<typename T>
inline T& MyDeque<T>::back()
{
	if (empty())
		return;

	size_t index = ((m_rear - 1) % m_maxSize);
	return m_arr[index];
}

template<typename T>
inline void MyDeque<T>::push_back(const T& val)
{
	if (full())
		return;

	m_arr[m_rear] = val;
	m_rear = ((m_rear + 1) + m_maxSize) % m_maxSize;
	m_size++;
}

template<typename T>
inline void MyDeque<T>::push_front(const T& val)
{
	if (full())
		return;

	m_arr[m_front] = val;
	m_front = ((m_front - 1) + m_maxSize) % m_maxSize;
	m_size++;
}

template<typename T>
inline void MyDeque<T>::pop_back()
{
	m_front = ((m_front + 1) + m_maxSize) % m_maxSize;
}

template<typename T>
inline void MyDeque<T>::pop_front()
{
	m_rear = ((m_rear - 1) + m_maxSize) % m_maxSize;
}
