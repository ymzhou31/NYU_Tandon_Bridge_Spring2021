#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void openInputFile(ifstream& inFile, string filename);


void openInputFile(ifstream& inFile, string filename) {
	
	inFile.open(filename);
	while (!inFile) {
		cout << "BAD FILENAME!" << endl;
		cout << "Enter a filename: ";
		cin >> filename;
		inFile.clear();
		inFile.open(filename);
	}
}

template <class T> //class predefinition
class LList;
template <class T>
class LListItr;

template <class T>
class LListNode {
	T employee_id;
	string name;
	float hourly_pay;
	int hours_worked;
	float total_comp;
	LListNode<T>* next;
	LListNode<T>* prev;
public:
	LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr,
		string newName = "", float newHourlyPay = 0, int newHoursWorked = 0, float newTotalComp = 0)
		:employee_id(newdata), next(newnext), prev(newprev), name(newName), hourly_pay(newHourlyPay), hours_worked(newHoursWorked), total_comp(newTotalComp) {}
	friend class LList<T>;
	friend class LListItr<T>;
};

class EmptyListError {};

template <class S>
class LListItr {
	LListNode<S>* ptr;
public:
	LListItr(LListNode<S>* newptr = nullptr) :ptr(newptr) {}
	S& operator*() { return ptr->employee_id; }
	S operator*() const { return ptr->employee_id; }
	LListItr operator++(int);
	LListItr& operator++();
	LListItr operator--(int);
	LListItr& operator--();
	bool operator==(const LListItr<S>& rhs) const { return ptr == rhs.ptr; }
	bool operator!=(const LListItr<S>& rhs) const { return ptr != rhs.ptr; }
	string get_name() { return ptr->name; }
	int get_hours_worked() { return ptr->hours_worked; }
	float get_hourly_pay() { return ptr->hourly_pay; }
	float get_total_comp() { return ptr->total_comp; }
	void set_name(string new_name) { ptr->name = new_name; }
	void set_hours_worked(int new_hours_worked) { ptr->hours_worked = new_hours_worked; }
	void set_hourly_pay(float new_hourly_pay) { ptr->hourly_pay = new_hourly_pay; }
	void set_total_comp(float new_total_comp) { ptr->total_comp = new_total_comp; }
	friend class LList<S>;
};

template <class T>
LListItr<T> LListItr<T>::operator--(int) {
	LListItr<T> temp = *this;
	if (ptr->prev != nullptr)
		ptr = ptr->prev;
	return temp;
}

template <class T>
LListItr<T>& LListItr<T>::operator--() {
	if (ptr->prev != nullptr)
		ptr = ptr->prev;
	return *this;
}

template <class T>
LListItr<T> LListItr<T>::operator++(int) {
	LListItr<T> temp = *this;
	if (ptr->next != nullptr)
		ptr = ptr->next;
	return temp;
}	

template <class T>
LListItr<T>& LListItr<T>::operator++() {
	if (ptr->next != nullptr)
		ptr = ptr->next;
	return *this;
}

template <class T>
class LList {
	LListNode<T>* head;
	LListNode<T>* tail;
	int numElements;
public:

	LListItr<T> begin() { return head->next; }
	LListItr<T> end() { return tail; }
	bool isEmpty() const { return numElements == 0; }
	LList();
	virtual ~LList();
	void push_front(const T& newdata);
	void push_back(const T& newdata) { insertAfter(newdata, tail->prev); }
	int size() const { return numElements; }
	void clear();
	LList(const LList<T>& rhs);
	LList& operator=(const LList& rhs);
	T pop_front() { if (!isEmpty()) return removeNode(head->next); else throw EmptyListError(); }
	T pop_back() { if (!isEmpty()) return removeNode(tail->prev); else throw EmptyListError(); }

	void insertAfter(const T& newdata, LListItr<T> itr);
	T removeNode(LListItr<T> itr);
	void selectionSort();
	void swap(LListItr<T> i, LListItr<T> j);
};

template <class T>
T LList<T>::removeNode(LListItr<T> itr) {
	LListNode<T>* toDelete = itr.ptr;
	T retval = toDelete->employee_id;
	toDelete->prev->next = toDelete->next;
	toDelete->next->prev = toDelete->prev;

	delete toDelete;
	numElements--;
	return retval;
}

template <class T>
void LList<T>::insertAfter(const T& newdata, LListItr<T> itr) {
	LListNode<T>* temp = itr.ptr;
	numElements++;
	temp->next = new LListNode<T>(newdata, temp->next, temp);
	temp->next->next->prev = temp->next;
	
}

template <class T>
void LList<T>::clear() {
	while (!isEmpty())
		removeNode(head->next);
}

template <class T>
void LList<T>::push_front(const T& newdata) {
	insertAfter(newdata, head);
}

template <class T>
LList<T>::~LList() {
	clear();
	delete head;
	delete tail;
}

template <class T>
LList<T>::LList() {
	numElements = 0;
	head = new LListNode<T>(T(), new LListNode<T>); //create two dummy nodes.
	tail = head->next;
	tail->prev = head;
}

template <class T>
LList<T>::LList(const LList<T>& rhs) {
	numElements = 0;
	head = new LListNode<T>(T(), new LListNode<T>); //create two dummy nodes.
	tail = head->next;
	tail->prev = head;
	*this = rhs;
}

template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
	if (this == &rhs)
		return *this;
	clear();

	for (LListNode<T>* temp = rhs.head->next; temp != rhs.tail; temp = temp->next)
		push_back(temp->employee_id);
	return *this;
}


template <class T>
void LList<T>::swap(LListItr<T> i, LListItr<T> j) {
	
	LListNode<T> temp;
	temp.employee_id = *i;
	temp.name = i.get_name();
	temp.hourly_pay = i.get_hourly_pay();
	temp.hours_worked = i.get_hours_worked();
	temp.total_comp = i.get_total_comp();
	
	i.set_name(j.get_name());
	i.set_hourly_pay(j.get_hourly_pay());
	i.set_hours_worked(j.get_hours_worked());
	i.set_total_comp(j.get_total_comp());
	
	j.set_name(temp.name);
	j.set_hourly_pay(temp.hourly_pay);
	j.set_hours_worked(temp.hours_worked);
	j.set_total_comp(temp.total_comp);


}


template <class T>
void LList<T>::selectionSort() {

	LListItr<T> max;
	LListItr<T> i = this->begin();
	LListItr<T> j;
	while(i != this->end()) {
		max = i;
		j = i;
		while (j != this->end()) {
			if (j.get_total_comp() > max.get_total_comp()) {
				max = j;
			}
			j++;
		}
		swap(i, max);
		i++;
	}
}


int main() {

	ifstream infile;
	string filename = "emps.txt";
	openInputFile(infile, filename);

	string temp;
	int employee_id;
	float hourly_pay;
	string name;

	LList<int> employee_info;
	LListItr<int> i;

	while (infile >> employee_id >> hourly_pay) {
		infile.ignore();
		getline(infile, name);
		employee_info.push_front(employee_id);
		i = employee_info.begin();
		i.set_hourly_pay(hourly_pay);
		i.set_name(name);

	}
	infile.close();

	filename = "hours.txt";
	int hours_worked;
	openInputFile(infile, filename);

	while (infile >> employee_id >> hours_worked) {
		i = employee_info.begin();
		while (*i != employee_id) {
			i++;
		}
		i.set_hours_worked(i.get_hours_worked()+ hours_worked);
		i.set_total_comp(i.get_hours_worked() * i.get_hourly_pay());
	}

	employee_info.selectionSort();

	i = employee_info.begin();
	while (i != employee_info.end()) {
		cout << i.get_name() << ", $"<<i.get_total_comp() << endl;
		i++;
	}
}
