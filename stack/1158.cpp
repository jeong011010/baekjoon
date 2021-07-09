#include<iostream>
#include<string>
using namespace std;

class Queue {
	int front, rear, size, k;
	int* arr;
public:
	Queue(int n, int k) { front = 0; rear = 0; size = n; arr = new int[size]; this->k = k; }
	~Queue() { delete[] arr; }

	void push(int n) {
		rear = (rear+1) % size;
		arr[rear] = n;

	}
	int pop(){
		int tmp;
		
		for (int i = 0; i < k; i++) {
			front = (front + 1) % (size);
			while (arr[front] == 0) {
				front = (front+1) % (size);
			}
		}
		tmp = arr[front];
		arr[front] = 0;
		return tmp;
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	Queue q(n, k);
	for (int i = 0; i < n; i++)
		q.push(i+1);
	cout << "<";
	for (int i = 0; i < n-1; i++) {
		cout << q.pop() << ", ";
	}
	cout << q.pop() << ">";
	return 0;
}