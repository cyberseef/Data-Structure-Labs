#include<iostream>
using namespace std;

class lift_floors {
public:
	int  floor;
	char floor_status; //A for active N for not active
	lift_floors* next;
	lift_floors* prev;
	lift_floors(int data) {
		this->floor = data;
		this->next = NULL;
		this->prev = NULL;
		this->floor_status = 'A';
	}
};

int liftup(lift_floors*& current, lift_floors*& head, lift_floors*& tail, int requested_floor)
{

	if (requested_floor == current->floor)
	{
		return current->floor;
	}
	else
	{
		current = current->next;
		liftup(current, head, tail, requested_floor);
	}


}

int liftdown(lift_floors*& current, lift_floors*& head, lift_floors*& tail, int requested_floor)
{
	if (requested_floor == current->floor)
	{
		return current->floor;
	}
	else
	{
		current = current->prev;
		liftup(current, head, tail, requested_floor);
	}
}


int lift_operating_system(int requested_floor, lift_floors*& current, lift_floors*& head, lift_floors*& tail, char lift_status)
{
	//all lift related logic will be written in this bloack along with validation. In this funcation, decide
	//if the lift goes up or down
	int resultfloor;
	if (lift_status == 'H')
	{
		cout << "THE lift is halted" << endl;
	}
	else
	{
		if (requested_floor < current->floor && requested_floor >= -1)
		{
			cout << "*** going down ***" << endl;
			resultfloor = liftdown(current, head, tail, requested_floor);
		}
		else if (requested_floor > current->floor)
		{
			cout << "*** going up ***" << endl;
			resultfloor = liftup(current, head, tail, requested_floor);
		}
		else if (requested_floor == current->floor)
		{
			cout << "not moving" << endl;
			resultfloor = current->floor;
		}
		
	}
	


	return resultfloor;
}


char halt_lift(char status)
{
	cout << "\nThe lift is halted";
	return 'H';
	//halts the lift, no up and down operation can be performed. Stored H for halting

}
char un_halt_lift(char status)
{
	cout << "\nThe lift is unhalted";
	return 'W';
	//Unhatls the lift. Store W which represents that the lift is working

}
void add_floor(lift_floors*& new_floor, lift_floors*& head, lift_floors*& tail)
{
	//add a lift floor;
	
	if (head == NULL)
	{
		head = new_floor;
		tail = new_floor;
	}
	else
	{
		tail->next = new_floor;
		new_floor->prev = tail;
		tail = new_floor;
	}

}
void skip_floor(lift_floors*& head, lift_floors*& tail, int floorNo)
{
	lift_floors* pointer1 = head;

	while (pointer1 != NULL)
	{
		if (pointer1->floor == floorNo)
		{
			pointer1->floor_status = 'S';
			
			break;
		}
		pointer1 = pointer1->next;
	}
}
void make_floor_operational(lift_floors*& head, lift_floors*& tail, int floorNo)
{
	lift_floors* pointer1 = head;

	while (pointer1 != NULL)
	{
		if (pointer1->floor == floorNo)
		{
			pointer1->floor_status = 'A';
			break;
		}
		pointer1 = pointer1->next;
	}
}
int main()
{
	lift_floors* head = NULL;
	lift_floors* tail = NULL;
	lift_floors* current = NULL;
	int floorNo = 0;
	int total_floors = 6; // total number of floors
	int current_floor = -1; // starts with basement
	int requested_service = 0; //choice of user
	int requested_floor = 0; //floor the lift goes on
	char status = 'W'; //W for working , H for halted

	//initialize everything and poplate the link list based on above data.
	//use add floor to add all the floors in the list

	while (1)
	{
		cout << "\n\nPlease select a funcation of your choice";
		cout << endl << "1. Go to a specific floor";
		cout << endl << "2. Halt Lift";
		cout << endl << "3. Unhalt Lift";
		cout << endl << "4. add floor";
		cout << endl << "5. skip floor";
		cout << endl << "6. operational floor";

		//.. add other options
		cout << endl;
		cin >> requested_service;
		switch (requested_service)
		{
			case 1:
			{
			
				cout << endl << "Enter Floor Number ";
				cin >> requested_floor;
				current_floor = lift_operating_system(requested_floor, current, head, tail, status);
			
				break;
			}
			case 2:
			{
				status = halt_lift(status);
				break;
			}
			case 3:
			{
				status = un_halt_lift(status);
				break;
			}
			case 4:
			{
				lift_floors* new_floor = new lift_floors(current_floor);

				add_floor(new_floor, head, tail);
				cout << "The new floor is added : floor " << current_floor << endl;
				current_floor++;
				break;
			}
			case 5:
			{
				cout << "\please nEnter the floor number you want to Skip the lift on  : ";
				cin >> floorNo;
				skip_floor(head, tail, floorNo);
				break;
			}
			case 6:
			{
				cout << "\nplease Enter the floor number you want to make operational again : ";
				cin >> floorNo;
				make_floor_operational(head, tail, floorNo);
				break;
			}
		}


	}
}