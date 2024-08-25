//M.Hamza Shahzad
// 20i-0796
// Question 1
// Lab 8



#include <iostream>

using namespace std;

class Queue
{
private:
	int front;
	int rear;
	int size;
	int* arr;
public:
	Queue()
	{
		size = 0;
		front = rear = -1;
		arr = new int[size];
	}
	Queue(int size)
	{
		this->size = size;
		front = rear = -1;
		arr = new int[size];
	}
	bool IsEmpty()
	{
		if (front == -1)
			return true;
		return false;
	}
	void Enqueue(int value)
	{
		if (IsEmpty())
		{
			front = rear = 0;
			arr[front] = value;
		}
		else if (IsFull())
		{
			cout << "Queue Overflow" << endl;
		}
		else
		{
			if (rear == size - 1)
				rear = 0;
			else
				rear++;
			arr[rear] = value;
		}
	}
	int Dequeue()
	{
		int temp;
		if (IsEmpty())
		{
			cout << "Queue Underflow\n";
			return -1;
		}
		else if (front == rear)
		{
			temp = arr[front];
			front = rear = -1;
			return temp;
		}
		else
		{
			
			temp = arr[front];
			if (front == size - 1)
				front = 0;
			else
				front++;
			return temp;
		}
	}
	int Peek()
	{
		if (IsEmpty())
		{
			cout << "Queue Underflow\n";
			return -1;
		}
		return arr[front];
		
	}
	void Display()
	{
		if (front > rear)
		{
			for (int i = front; i < size; i++)
			{
				cout << arr[i] << "  ";
			}
			for (int j = 0; j <= rear; j++)
			{
				cout << arr[j] << "  ";
			}
		}
		else
		{
			for (int i = front; i <= rear; i++)
			{
				cout << arr[i] << "  ";
			}
		}
		cout << endl;
	}
};
void roundRobin(Queue tasks, int time_slot)
{
	int task;
	tasks.Display();
	while (!tasks.IsEmpty()) 
	{
		task = tasks.Peek();
		task = task - time_slot;
		if (task > 0)
		{
			tasks.Dequeue();
			tasks.Enqueue(task);
		}
		else
			tasks.Dequeue();
		if (!tasks.IsEmpty())
			tasks.Display();
	}
		

}
int main()
{
	Queue tasks(4);
	int time_slot = 2;
	tasks.Enqueue(5);
	tasks.Enqueue(3);
	tasks.Enqueue(8);
	tasks.Enqueue(10);
	roundRobin(tasks, time_slot);
}
