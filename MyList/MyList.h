#pragma once

template <typename T>
class MyList
{
private:
	struct Node
	{
		Node* m_prev;
		Node* m_next;
		T m_data;
	};

	Node* m_head;
	Node* m_tail;
	size_t m_size;

	void clear();

public:
	class iterator
	{
		private:
		Node* m_iter;

	public:
		iterator()
			: m_iter(new Node)
		{
		}

		iterator(Node* node)
			: m_iter(node)
		{
		}

		Node* operator&()
		{
			return m_iter;
		}
	};

	MyList();
	MyList(const MyList& x);
	MyList(MyList&& x);
	~MyList();

	MyList<T>& operator=(const MyList & x);
	MyList<T>& operator=(MyList&& x);
	T& operator[](size_t idx);

	bool empty();
	size_t size();

	iterator begin();
	iterator end();

	T front();
	T back();

	void assign(size_t n, const T& val);
	void push_front(const T& val);
	void pop_front();
	void push_back(const T& val);
	void pop_back();
	void insert(iterator pos, const T& val);
	void erase(iterator pos);
};

template<typename T>
inline void MyList<T>::clear()
{
	Node* newNode = m_head;

	for (size_t i = 0; i < m_size; i++)
	{
		Node* temp = newNode->m_next;

		delete newNode;

		newNode = temp;
	}

	m_size = 0;
}

template<typename T>
inline MyList<T>::MyList()
	: m_head(new Node())
	, m_tail(new Node())
	, m_size(0)
{
	m_head->m_prev = nullptr;
	m_head->m_next = m_tail;

	m_tail->m_prev = m_head;
	m_tail->m_next = nullptr;
}

template<typename T>
inline MyList<T>::MyList(const MyList& x)
	: m_size(x.m_size)
{
	if (x.m_head == nullptr)
	{
		m_head->m_prev = nullptr;
		m_head->m_next = m_tail;

		m_tail->m_prev = m_head;
		m_tail->m_next = nullptr;
		return;
	}

	Node* temp = x.m_head;
	Node* newNode = nullptr;

	for (size_t i = 0; i < x.m_size; i++)
	{
		newNode = new Node();
		newNode->m_data = temp->m_data;
		newNode->m_prev = temp->m_prev;
		newNode->m_next = temp->m_next;

		if (m_head == nullptr)
			m_head = newNode;

		temp = temp->m_next;
	}

	m_tail->m_prev = newNode;
	m_tail->m_next = nullptr;
}

template<typename T>
inline MyList<T>::MyList(MyList&& x)
{
	clear();

	m_head = x.m_head;
	m_tail = x.m_tail;
	m_size = x.m_size;

	x.m_head = nullptr;
	x.m_tail = nullptr;
	x.m_size = 0;
}

template<typename T>
inline MyList<T>::~MyList()
{
	this->clear();
}

template<typename T>
inline MyList<T>& MyList<T>::operator=(const MyList& x)
{
	if (x.m_head == nullptr)
	{
		m_head->m_prev = nullptr;
		m_head->m_next = m_tail;

		m_tail->m_prev = m_head;
		m_tail->m_next = nullptr;
		return;
	}

	Node* temp = x.m_head;
	Node* newNode = nullptr;

	for (size_t i = 0; i < x.m_size; i++)
	{
		newNode = new Node();
		newNode->m_data = temp->m_data;
		newNode->m_prev = temp->m_prev;
		newNode->m_next = temp->m_next;

		if (m_head == nullptr)
			m_head = newNode;

		temp = temp->m_next;
	}

	m_tail->m_prev = newNode;
	m_tail->m_next = nullptr;
}

template<typename T>
inline MyList<T>& MyList<T>::operator=(MyList&& x)
{
	if (this == &x)
		return *this;

	m_head = x.m_head;
	m_tail = x.m_tail;
	m_size = x.m_size;

	x.m_head = nullptr;
	x.m_tail = nullptr;
	x.m_size = 0;

	return *this;
}

template<typename T>
inline T& MyList<T>::operator[](size_t idx)
{
	Node* temp = m_head;

	for (size_t i = 0; i <= idx; i++)	
		temp = temp->m_next;

	return temp->m_data;
}

template<typename T>
inline bool MyList<T>::empty()
{
	if (m_size == 0)
		return true;

	return false;
}

template<typename T>
inline size_t MyList<T>::size()
{
	return m_size;
}

template<typename T>
typename inline MyList<T>::iterator MyList<T>::begin()
{
	return iterator(m_head->m_next);
}

template<typename T>
typename inline MyList<T>::iterator MyList<T>::end()
{
	return iterator(m_tail);
}

template<typename T>
inline T MyList<T>::front()
{
	if (!empty())
		m_head->m_next->m_data;
	else
		return -1;
}

template<typename T>
inline T MyList<T>::back()
{
	if (!empty())
		m_tail->m_prev->m_data;
	else
		return -1;
}

template<typename T>
inline void MyList<T>::assign(size_t n, const T& val)
{
	clear();
}

template<typename T>
inline void MyList<T>::push_front(const T& val)
{
	Node* newNode = new Node();

	newNode->m_data = val;
	newNode->m_prev = m_head;
	newNode->m_next = m_head->m_next;

	m_head->m_next->m_prev = newNode;
	m_head->m_next = newNode;

	m_size++;
}

template<typename T>
inline void MyList<T>::pop_front()
{
	if (empty())
		return;

	Node* target = m_head->m_next;

	m_head->m_next = target->m_next;
	target->m_next->m_prev = m_head;

	delete target;

	m_size--;
}

template<typename T>
inline void MyList<T>::push_back(const T& val)
{
	Node* newNode = new Node();

	newNode->m_data = val;
	newNode->m_prev = m_tail->m_prev;
	newNode->m_next = m_tail;

	m_tail->m_prev->m_next = newNode;
	m_tail->m_prev = newNode;
	
	m_size++;
}

template<typename T>
inline void MyList<T>::pop_back()
{
	if (empty())
		return;

	Node* target = m_tail->m_prev;

	m_tail->m_prev = target->m_prev;
	target->m_prev->m_next = m_tail;

	delete target;

	m_size--;
}

template<typename T>
inline void MyList<T>::insert(iterator pos, const T& val)
{
	Node* target = &pos;
	Node* prevNode = target->m_prev;

	Node* newNode = new Node();
	newNode->m_data = val;
	newNode->m_prev = prevNode;
	newNode->m_next = target;

	prevNode->m_next = newNode;
	target->m_prev = newNode;

	m_size++;
}

template<typename T>
inline void MyList<T>::erase(iterator pos)
{
	Node* target = &pos;
	Node* prevNode = target->m_prev;
	Node* nextNode = target->m_next;

	prevNode->m_next = nextNode;
	nextNode->m_prev = prevNode;

	delete target;

	m_size--;
}
