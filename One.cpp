#include<iostream>
#include <cstring>
using namespace std;
class Stack 
{
	friend class QueueL;
	int* A;
	int top;
	int capacity;
public:
	
	Stack(int size)
	{
		A = new int[size];
		top = -1;
		capacity = size;
	}
	~Stack()
	{
		delete[] A;
	}

	void display()
	{
		for (int i = top; i >=0; i--)
		{
			cout << A[i] << endl;
		}
	}
	void push(int x)
	{
		if (isFull())
		{
			cout << "Stack overflow\n";
			return;
		}
		top++;
		A[top] = x;
	}
	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack underflow\n";
			return -1;
		}
		int x = A[top];
		top--;
		return x;
	}
	bool isFull()
	{
		return top == capacity - 1;
	}
	bool isEmpty()
	{
		return top == -1;
	}
	int peek()
	{
		if (isEmpty())
		{
			cout << "Stack is empty\n";
			return -1;
		}
		return A[top];
	}
	int size()
	{
		return top + 1;
	}
	bool isBalanced(char* exp)
	{
		Stack s(strlen(exp));
		int i = 0;
		while (exp[i] != '\0')
		{
			if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			{
				s.push(exp[i]);
			}
			else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
			{
				if (s.isEmpty())
				{
					return false;
				}
				char temp = s.pop();
				if ((exp[i] == ')' && temp != '(') || (exp[i] == ']' && temp != '[') ||
					(exp[i] == '}' && temp != '{'))
				{
					return false;
				}
			}
			i++;
		}
		return s.isEmpty();
	}
	int pre(char x)
	{
		if (x == '+' || x == '-')
			return 1;
		else if (x == '*' || x == '/')
			return 2;
	}
	bool isOperand(char x)
	{
		if (x == '+' || x == '-' || x == '*' || x == '/')
			return false;
		else
			return true;
	}
	char* InToPost(char* infix)
	{
		Stack myStack(strlen(infix));
		int i = 0, j = 0;
		int len = strlen(infix);
		char* postfix = new char[len + 1];
		while (infix[i] != '\0')
		{
			if (isOperand(infix[i]))
				postfix[j++] = infix[i++];
			else
			{
				if (pre(infix[i]) > pre(myStack.peek()))
					myStack.push(infix[i++]);
				else
					postfix[j++] = myStack.pop();
			}
		}
		while (!myStack.isEmpty())
			postfix[j++] = myStack.pop();

		postfix[j] = '\0';
		return postfix;
	}
};
class Queue {
private:
	int front{};
	int rear{};
	static const int Size = 10;
	int Arr[Size];
	int count{};
public:
	
	Queue()
	{
		front = -1;
		rear = -1;
	}


	void Enqueue(int x)
	{
		if (Isfull())
		{
			cout << "Queue is full:";
		}
		else
		{
			rear = rear + 1;
			Arr[rear] = x;
			cout << "Enqueued : " << x << endl;
		}
	}
	int Dequeue() {
		if (IsEmtpy()) {
			cout << "Queue is empty." << endl;
			return 0;
		}
		else {
			
			front = front + 1;
			return Arr[front];
		}
	}
	int getFront() {
		if (IsEmtpy()) {
			cout << "Queue is empty." << endl;
			return -1;
		}
		else {
			return Arr[front];
		}
	}
	int getRear() {
		if (IsEmtpy()) {
			cout << "Queue is empty." << endl;
			return -1;
		}
		else {
			return Arr[rear];
		}
	}
	bool Isfull()
	{
		return rear == Size - 1;
	}
	int size() {
		return count;
	}

	bool IsEmtpy()
	{
		return rear == -1 && front == -1;
	}
};
class Node {
public:
	int data;
	Node* next;

	Node(int data)
	{
		data = data;
		next = NULL;
	}
};
class StackL
{
private:
	Node* head;
	Node* tail;
	Node* front;
	int size;
	int maxSize;
public:
	StackL()
	{
		head = NULL;
	}
	StackL(int size)
	{

	}
	~StackL()
	{
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	void Push(int value)
	{
		Node* newnode = new Node(value);
		newnode->next = head;
		head = newnode;
	}
	void display()
	{
		Node* second_L_node = head;
		while (second_L_node->next->next != NULL)
		{
			second_L_node = second_L_node->next;
		}
		Node* temp = second_L_node->next;
		second_L_node->next = NULL;
		delete temp;
		cout << " NULL\n";
	}
	void deleteEnd()
	{
		if (head == NULL)
		{
			return;
		}
		
		

	}
	void pop() {
		if (head == NULL)
		{
			return;
		}
		Node* second_L_node = head;
		while (second_L_node->next->next != NULL)
		{
			second_L_node = second_L_node->next;
		}
		Node* temp = second_L_node->next;
		second_L_node->next = NULL;
		delete temp;
	}
	int peek()
	{
		cout<<head->data;
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	bool isFull()
	{
		return 0;
	}
	bool balancedParenthesis()
	{

	}
	void infixToPostfix()
	{

	}
};
class QueueL 
{
private:
	int* S;
	int top;
	int capacity;
	Node* head;
	Node* tail;
	Node* front;
	int size=0;
	int maxSize;
public:
	QueueL() {};
	QueueL(int maxSize)
	{
		head = NULL;
		tail = NULL;
		front = NULL;
		size = 0;
		this->maxSize = maxSize;
	}
	~QueueL()
	{
		delete[] head;
		delete[] tail;
		delete[] front;
	}
	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data;
			temp = temp->next;
		}
	}
	void EnQueue(int x) {
		if (size == maxSize) {
			cout << " Now Queue is full Cannot enqueue elements ." << endl;
			return;
		}

		Node* newnode = new Node(x);
		if (front == NULL) {
			front = tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
		tail->next = front;
		size++;
	}
	int Dequeue()
	{
		if (front == NULL)
		{
			cout << "Queue is Empty" << endl;
			return 0;
		}

		Node* temp = front;
		front = front->next;
		delete (temp);
		size--;
		if (size == 0) {
			tail = NULL;
		}
		else {
			tail->next = front;
		}

	}
	int Getsize()
	{
		return size;
	}
	bool IsEmpty()
	{
		return head == NULL;
	}
	bool IsFull()
	{
		return size == maxSize;
	}
	int getFront()
	{
		if (head == NULL) return -1;
		return head->data;
	}
	int getRear() {
		if (tail == NULL) return -1;
		return tail->data;
	}
	int reverseQueue()
	{
		
		Stack t(countNodes());
		Node* temp = head;

		while (!t.isEmpty())
		{
			t.push(temp->data);
			temp = temp->next;
		}
		temp = head;
		while (!t.isEmpty())
		{
			temp->data = t.pop();
			temp = temp->next;
		}
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		
		return 0;
	}
	int reverse()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			top++;
			S[top] = temp->data;
			temp = temp->next;
		}
		temp = head;
		while (temp != NULL)
		{
			temp->data = S[top];
			top--;
			temp = temp->next;
		}
		return 0;
	}
	
	int countNodes()
	{
		Node* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
};
int main()
{
	Stack s(10);
	StackL sl;
	Queue q;
	QueueL ql(10);
	int choice = 0;
BACK:
	system("cls");
	cout << "Assignemt no.4" << endl;
	cout << "1. STACK (LIFO) using Array" << endl;
	cout << "2. STACK (LIFO) using Singly LinkedList Only" << endl;
	cout << "3. QUEUE (FIFO) using Array" << endl;
	cout << "4. QUEUE (FIFO) using Singly LinkedList Only" << endl;
	cout << "5. Exit" << endl;
	do
	{

		
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int c1=0;
			system("cls");
			cout << "1. Stack using Array" << endl;
			cout << "\nFuntions" << endl;
			cout << "1. PUSH()" << endl;
			cout << "2. POP()" << endl;
			cout << "3. PEEK()" << endl;
			cout << "4. isEmpty()" << endl;
			cout << "5. isFull()" << endl;
			cout << "6. balancedParenthesis()" << endl;
			cout << "7. infixToPostfix()" << endl;
			cout << "8. Go Back" << endl;

			do 
			{
				cin >> c1;
				switch (c1)
				{
				case 1:
					int a;
					cout << "Enter the Value you want to push in Stack" << endl;
					do
					{
						cin >> a;

						if (cin.good())
							s.push(a);
						else
						{
							cout << "Wrong Entery" << endl;
						}

					} while (!cin.good());
					cout << "The Stack is: " << endl;
					s.display();

					break;
				case 2:
					cout << "The pop Element is: " << s.pop() << endl;
					break;
				case 3:
					cout << "The Peek Element is: " << s.peek() << endl;
					break;
				case 4:
					cout << "IS Empty ?" << s.isEmpty() << endl;

					break;
				case 5:
					cout << "Is Full ? " << s.isFull() << endl;

					break;
				case 6:
					cout << "Enter the paranthesis string:" << endl;
					 char exp1[] = "(a+b)*(c-d)()()";
					 cout << "Is " << exp1 << " balanced? "
						 << (s.isBalanced(exp1) ? "Yes \n" : "No \n");
					
					break;
				case 7:
					char infix[] = "a+b*c-d/e";
					cout << "Infix: " << infix << endl;
					cout << "Postfix: " << s.InToPost(infix) << endl;
					break;
				case 8:
					cout << "Want to go back" << endl;
					goto BACK;
					break;
				default:
					cout << "You Enter Wrong Choice." << endl;
					break;
				}
			} while (c1 != 8);

			break;

		}
		case 2:
		{

			int c2 = 0;
			system("cls");
			cout << "2. STACK (LIFO) using Singly LinkedList Only" << endl;
			cout << "\nFuntions" << endl;
			cout << "1. PUSH()" << endl;
			cout << "2. POP()" << endl;
			cout << "3. PEEK()" << endl;
			cout << "4. isEmpty()" << endl;
			cout << "5. isFull()" << endl;
			cout << "6. balancedParenthesis()" << endl;
			cout << "7. infixToPostfix()" << endl;
			cout << "8. Go Back" << endl;
			do
			{
				cin >> c2;
				switch (c2)
				{
				case 1:
					int c;
					cout << "Enter the Value you want to push in stack" << endl;
					do
					{
						cin >> c;

						if (cin.good())
							sl.Push(c);
						else
						{
							cout << "Wrong Entery" << endl;
						}

					} while (!cin.good());
					cout << "The Stack is: " << endl;
					
					break;
				case 2:
					cout << "The pop Element is: " << sl.pop()<< endl;
					break;
				case 3:
					cout << "The Peek Element is: " <<sl.peek()<< endl;
					break;
				case 4:
					cout << "IS Empty ?" <<sl.isEmpty()<< endl;
					break;
				case 5:
					cout << "Is Full ? " <<sl.isFull()<< endl;
					break;
				case 6:
					cout << "Enter the paranthesis string:" <<sl.balancedParenthesis()<< endl;
					break;
				case 7:
					cout << "Enter infix: " <<sl.infixToPostfix()<< endl;
					break;
				case 8:
					cout << "Go back" << endl;
					goto BACK;
				default:
					cout << "You Enter Wrong Choice." << endl;
					break;
				}
			} while (c2 != 8);
			break;

		}
		case 3:
		{
			int c3 = 0;
			system("cls");
			cout << "3. Queue using Array" << endl;
			cout << "\nFuntions" << endl;
			cout << "1. enque()" << endl;
			cout << "2. dequeue()" << endl;
			cout << "3. getFront()" << endl;
			cout << "4. getRear()" << endl;
			cout << "5. isFull()" << endl;
			cout << "6. size()" << endl;
			cout << "7. isEmpty()" << endl;
			cout << "8. reverseQueue() using STACK" << endl;
			cout << "9. Go Back" << endl;
			do
			{
				cin >> c3;
				switch (c3)
				{
				case 1:
					int e;
					cout << "Enter the Value you want to Enque: " << endl;
					do
					{
						cin >> e;

						if (cin.good())
							q.Enqueue(e);
						else
						{
							cout << "Wrong Entery" << endl;
						}

					} while (!cin.good());
					
					break;
				case 2:
					cout << "The deque Element is: " << q.Dequeue() << endl;
					break;
				case 3:
					cout << "The Front Element is: " << endl;
					break;
				case 4:
					cout << "IS Empty ?" << endl;
					break;
				case 5:
					cout << "Is Full ? " << endl;
					break;
				case 6:
					cout << "Enter the paranthesis string:" << endl;
					break;
				case 7:
					cout << "Enter infix: " << endl;
					break;
				case 8:
					cout << "Go back" << endl;
					goto BACK;
				default:
					cout << "You Enter Wrong Choice." << endl;
					break;
				}
			} while (c3 != 8);
			break;

		}
		case 4:
		{
			int c4 = 0;
			system("cls");
			cout << "4. QUEUE (FIFO) using Singly LinkedList Only" << endl;
			cout << "\nFuntions" << endl;
			cout << "1. enque() circular" << endl;
			cout << "2. dequeue() circular" << endl;
			cout << "3. getFront()" << endl;
			cout << "4. getRear()" << endl;
			cout << "5. isFull()" << endl;
			cout << "6. size()" << endl;
			cout << "7. isEmpty()" << endl;
			cout << "8. reverseQueue() using STACK" << endl;
			cout << "9. Go Back" << endl;
			do
			{
				cin >> c4;
				switch (c4)
				{
				case 1:
					int f;
					cout << "Enter the Value you want to Enque: " << endl;
					do
					{
						cin >> f;

						if (cin.good())
							ql.EnQueue(f);
						else
						{
							cout << "Wrong Entery" << endl;
						}

					} while (!cin.good());
					break;
				case 2:
					cout << "The deque Element is: " << ql.Dequeue()<< endl;
					break;
				case 3:
					cout << "The Front Element is: " << ql.getFront()<< endl;
					break;
				case 4:
					cout << "The Rear Element is: " << ql.getRear() << endl;
					break;
				case 5:
					cout << "Is Full ? " << ql.IsFull() << endl;
					break;
				case 6:
					cout << "Size of Queue is :" << ql.Getsize() << endl;
					break;
				case 7:
					cout << "Is Empty ? " << ql.IsEmpty() << endl;
					break;
				case 8:
					ql.display();
					ql.reverse();
					cout << "Queue is Reversed" << endl;
					ql.display();
					break;
				case 9:
					cout << "Go Back" << endl;
					goto BACK;
				default:
					cout << "You Enter Wrong Choice." << endl;
					break;
				}
			} while (c4 != 8);
			break;
		}
		case 5:
		{
			cout << "Program End!" << endl;
			exit(0);
			break;
		}
		default:
			cout << "You Enter Wrong Choice" << endl;
			break;

		}
	} while (choice != 5);

	return 0;
}
