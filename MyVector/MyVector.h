#pragma once
#include <memory>

template <typename T>
class MyVector
{
private:
	size_t m_capacity;
	size_t m_size;
	T* m_arr;

private:
	void swap(MyVector& x, MyVector& y);

public:
	MyVector(size_t cap = 4);
	MyVector(const MyVector& x);
	MyVector(MyVector&& x);
	~MyVector();

	MyVector& operator=(const MyVector& x);
	MyVector& operator=(MyVector&& x);
	T& operator[](size_t idx);

	T* begin();
	T* end();

	T& front();
	T& back();

	size_t size();
	size_t capacity();
	bool empty();
	void reserve(size_t n);
	void shirink_to_fit();

	void assign(size_t n, const T& val);
	void push_back(const T& val);
	void pop_back();
	void swap(MyVector& x);
	void clear();
};

template<typename T>
inline void MyVector<T>::swap(MyVector& x, MyVector& y)
{
	size_t tempCapacity = x.m_capacity;
	size_t tempSize = x.m_size;
	T* tempArr = x.m_arr;

	x.m_capacity = y.m_capacity;
	x.m_size = y.m_size;
	x.m_arr = y.m_arr;

	y.m_capacity = tempCapacity;
	y.m_size = tempSize;
	y.m_arr = tempArr;
}

template<typename T>
inline MyVector<T>::MyVector(size_t cap)
	: m_capacity(cap)
	, m_size(0)
	, m_arr(new T[cap])
{
}

template<typename T>
inline MyVector<T>::MyVector(const MyVector& x)
	: m_capacity(x.m_capacity)
	, m_size(x.m_size)
	, m_arr(new T[x.m_capacity])
{
	for (size_t i = 0; i < x.m_size; i++)
		m_arr[i] = x.m_arr[i];
}

template<typename T>
inline MyVector<T>::MyVector(MyVector&& x)
	: m_capacity(x.m_capacity)
	, m_size(x.m_size)
	, m_arr(x.m_arr)
{
	m_capacity = 0;
	m_size = 0;
	m_arr = nullptr;
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	if (m_arr) // m_arr != nullptr
		delete[] m_arr;
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(const MyVector& x)
{
	if (m_capacity < x.m_capacity)
	{
		delete[] m_arr;
		m_arr = new T[x.m_capacity];
	}

	memcpy(m_arr, x.m_arr, x.m_capacity * sizeof(T));
	/*
	for (size_t i = 0; i < x.m_capacity; i++)
		m_arr[i] = x.m_arr[i];
	*/

	m_capacity = x.m_capacity;
	m_size = x.m_size;

	return *this;
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(MyVector&& x)
{
	this->swap(*this, x);

	return *this;
}

template<typename T>
inline T& MyVector<T>::operator[](size_t idx)
{
	return m_arr[idx];
}

template<typename T>
inline T& MyVector<T>::front()
{
	return m_arr[0];
}

template<typename T>
inline T& MyVector<T>::back()
{
	return m_arr[m_size - 1];
}

template<typename T>
inline T* MyVector<T>::begin()
{
	return m_arr;
}

template<typename T>
inline T* MyVector<T>::end()
{
	return m_arr + m_size;
}

template<typename T>
inline size_t MyVector<T>::size()
{
	return m_size;
}

template<typename T>
inline size_t MyVector<T>::capacity()
{
	return m_capacity;
}

template<typename T>
inline bool MyVector<T>::empty()
{
	return m_size == 0 ? true : false;
}

template<typename T>
inline void MyVector<T>::reserve(size_t n)
{
	if (n < m_size)
		return;
	
	T* temp = new T[n];

	memcpy(temp, m_arr, n * sizeof(T));
	/*
	for (size_t i = 0; i < n; i++)
		temp[i] = m_arr[i];
	*/

	delete[] m_arr;
	m_arr = temp;

	m_capacity = n;
}

template<typename T>
inline void MyVector<T>::shirink_to_fit()
{
	T* temp = new T[m_size + 1];

	memcpy(temp, m_arr, m_size * sizeof(T));
	/*
	for (size_t i = 0; i < m_size; i++)
		temp[i] = m_arr[i];
	*/

	delete[] m_arr;
	m_arr = temp;

	m_capacity = m_size;
}

template<typename T>
inline void MyVector<T>::assign(size_t n, const T& val)
{
	m_arr = new T[n * 2];

	for (size_t i = 0; i < n; i++)
		m_arr[i] = val;

	m_capacity = n * 2;
	m_size = n;
}

template<typename T>
inline void MyVector<T>::push_back(const T& val)
{
	if (m_size > m_capacity / 2)
	{
		m_capacity *= 2;

		T* temp = new T[m_capacity];

		memcpy(temp, m_arr, m_size * sizeof(T));
		/*
		for (size_t i = 0; i < m_size; i++)
			temp[i] = m_arr[i];
		*/

		delete[] m_arr;
		m_arr = temp;
	}

	m_arr[m_size] = val;
	m_size++;
}

template<typename T>
inline void MyVector<T>::pop_back()
{
	m_size = (m_size != 0 ? m_size - 1 : 0);
}

template<typename T>
inline void MyVector<T>::swap(MyVector& x)
{
	this->swap(*this, x);
}

template<typename T>
inline void MyVector<T>::clear()
{
	m_size = 0;
}
