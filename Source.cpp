#include "Header.h"


void insertAfter(int F, int S, vector<int>& V1) {
	for (int i = 0; i < V1.size();i++) {
		if (V1[i] == F) {
			V1.insert(V1.begin() + i + 1, S);
			i++;
		}

	}
	V1.push_back(F);
	V1.push_back(S);
}



int main()
{

	int n, firstValue, secondValue;
	cout << " please insert the size of elements " << endl;
	cin >> n;
	vector<int> V1(n);
	cout << " please insert the first value to be stored in the vector" << endl;
	cin >> firstValue;
	cout << " please insert the second value to be stored in the vector" << endl;
	cin >> secondValue;
	insertAfter(firstValue, secondValue, V1);
	
	cout << " please insert the values to follow inside the vector " << endl;
	int a;
	for (int i = 2; i < n ; i++)
	{

		cin >> a;
		V1.push_back(a);
		
	}
	
	
	LinkedList list;
	list.createList(V1);
	cout << " the linked list elements are : " << endl;
	list.printList();
	cout << " the sum of nodes is " << endl;
	cout<< list.sumNodes();
	return 0;
}
