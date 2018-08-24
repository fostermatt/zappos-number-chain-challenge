#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct queueNode {
	int initVal, currVal, val1, val2;
	string operation;
	queueNode *parentNode;
	queueNode *link;
};

queueNode nodeCopy(queueNode old){
	queueNode *newNode;
	newNode->initVal = old.initVal;
	newNode->currVal = old.currVal;
	newNode->operation = old.operation;
	newNode->val1 = old.val1;
	newNode->val2 = old.val2;
	newNode->parentNode = old.parentNode;

	return *newNode;
};

class linkedQueue {
public:
	linkedQueue(){
	count = 0;
	queueFront=NULL;
	queueRear=NULL;
	}

	~linkedQueue() {
		destroyQueue();
	}

	bool isEmptyQueue()  const {
		if (count == 0)
			return true;
		else
			return false;
	}

	void initializeQueue() {
		if (!isEmptyQueue())
			destroyQueue();
		linkedQueue();
	}

	void enqueue(const	int inputVal,
						int currVal = -1,
						string operation = "none",
						int val1 = -1,
						int val2 = -1,
						queueNode *parentNode = NULL){
		queueNode *newNode = new queueNode;
		newNode->initVal = inputVal;
		newNode->currVal = currVal;
		newNode->operation = operation;
		newNode->val1 = val1;
		newNode->val2 = val2;
		newNode->parentNode = parentNode;
		newNode->link = NULL;
		if (queueFront == NULL){
			queueFront = newNode;
			queueRear = newNode;
		}
		else
			queueRear->link=newNode;
		queueRear=newNode;
		count++;
	}

	int front() const{
		return queueFront->currVal;	
	}

	int back() const {
		return queueRear->currVal;
	}

	void dequeue() {
		queueNode *tmp;
		tmp = queueFront;
		queueFront = queueFront->link;
		if (queueFront == NULL)
			queueRear = NULL;
		count--;
		delete tmp;
	}

	int queueCount() {
		return count;
	}

	void destroyQueue(){
		if(queueFront!=NULL) {
			queueNode *temp;
			while (queueFront !=NULL)
			{
				temp = queueFront;
				queueFront = queueFront->link;
				delete temp;
			}
			count=0;
			queueRear=NULL;
		}
		else
			count=0;
	}

	// int getInitVal()


private:
	int count;
	// count of queue

	queueNode *queueFront, *queueRear;
	// pointers for front and rear of queue
};


int main(){
	int startNum = 1, endNum = 16, stepCount = 0;
	

	// queue<myNode> processing;
	// queue<myNode> doneProcessing;
	// myNode *newNode;
	// newNode = new myNode;
	// newNode->input1 = startNum;
	// newNode->operation = "none";
	// newNode->parentNode = NULL;
	// processing.push(newNode);

	linkedQueue processingQueue, doneQueue;
	processingQueue.enqueue(15);
	processingQueue.enqueue(15,20, "add", 15, 5);

	cout << "count = " << processingQueue.queueCount() << endl;
	cout << processingQueue.front() << endl;
	cout << processingQueue.back() << endl;



	return 0;
}
