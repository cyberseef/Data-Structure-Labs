#include <iostream>
using namespace std;

class student_Node {
public:
	string data;
	student_Node* next;
	student_Node(string data) {
		this->data = data;
		this->next = NULL;
	}
};
//The above portion cannot be changed

string* check(student_Node*& head3, int& I1, string*& result)
{

	student_Node* pointer1 = head3;
	while (pointer1 != NULL)
	{
		string name = pointer1->data;

		int choose = 0;
		for (int i = 0; i < 100; i++)//checking the name is in the list
		{
			if (result[i] == name)
			{
				i = 100;
				choose = 1;
			}
		}

		if (choose == 1)
		{
			choose = 0;
		}
		else
		{
			result[I1] = name;
			I1++;

		}

		pointer1 = pointer1->next;
	}
	return result;
}

string* list_of_all_students(student_Node*& head1, student_Node*& head2, student_Node*& head3)
{
	string* result = new string[100];
	int I1 = 0;
	//enter your code here
	result = check(head1, I1,result);
	result = check(head2, I1,result);
	result = check(head3, I1, result);

	



	for (int i = 0; i < I1; i++)
	{
		cout << result[i] << endl;
	}


	return result;
}


string* list_common_student_society(student_Node*& head1, student_Node*& head2, student_Node*& head3)
{

	string* result = new string[100];

	student_Node* pointer1 = head1;
	student_Node* pointer12 = head2;
	student_Node* pointer13 = head3;

	int I1 = 0;
	while (pointer1 != NULL)
	{
		string name = pointer1->data;

		student_Node* pointer12 = head2;

		while (pointer12 != NULL)
		{

			if (pointer12->data == name)
			{
				student_Node* pointer13 = head3;

				while (pointer13 != NULL)
				{

					if (pointer13->data == name)
					{
						result[I1] = name;
						I1++;
					}


					pointer13 = pointer13->next;
				}
			}


			pointer12 = pointer12->next;
		}


		pointer1 = pointer1->next;
	}

	for (int i = 0; i < I1; i++)
	{
		cout << result[i] << endl;
	}
	return result;
}



void insert(student_Node*& head, string  arr[6])
{

	for (int i = 0; i < 6; i++)
	{
		string name = arr[i];

		student_Node* nn = new student_Node(name);
		student_Node* ptr = head;

		if (ptr == NULL)
		{
			head = nn;
		}
		else
		{
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = nn;
		}

	}
}



void insert2(student_Node*& head, string  arr[6])
{

	for (int i = 0; i < 6; i++)
	{
		string name = arr[i];

		student_Node* nn = new student_Node(name);
		student_Node* pointer1 = head;

		if (pointer1 == NULL)
		{
			head = nn;
		}
		else
		{
			while (pointer1->next != NULL)
			{
				pointer1 = pointer1->next;
			}
			pointer1->next = nn;
		}

	}
}
//you can make fuctions for input and output, Core logic will be in above two funcation. Main should only work as a runner.
int main()
{
	student_Node* FGC_List = NULL;
	student_Node* FAS_List = NULL;
	student_Node* FDS_List = NULL;
	string* result = NULL;

	string array1[6] = { "Ali", "Usman", "Haider", "Maryam", "Masooma", "Urooj" };
	string array2[6] = { "Ashiq", "Manika", "Ali", "Masooma", "Akbar", "Urooj" };
	string array3[6] = { "Masooma", "Bilal", "Amna", "Madiha", "Rohail", "Urooj" };

	insert(FGC_List, array1);
	insert(FAS_List, array2);
	insert(FDS_List, array3);




	cout << endl << endl;
	cout << " 1 common students " << endl;
	result = list_common_student_society(FAS_List, FDS_List, FGC_List);
	cout << "\n\n2 all students " << endl;
	result = list_of_all_students(FAS_List, FDS_List, FGC_List);


}