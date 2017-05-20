#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// NEED TO IMPLEMENT ERROR AND EXCEPTION HANDLING

enum route { mesh_left, mesh_down, mesh_right, mesh_up };

class ComputeUnit
{
	private:
	char reg;			// a 1 Byte register

	public:
	int setR(char x)	// sets the register value
	{
		reg = x;
		return 1;
	}

	char getR()
	{
		return reg;
	}
	
	void function()	// implement this as a variadic function with one argument as a function pointer
	{
		cout << reg++;
	}

	ComputeUnit()	// implement constructors as necessary
	{
		reg='A';
	}
};

/*
	The architecture using a mesh switch is as follows:

	0--0--1--1--0--0--1--0
	|  |  |  |  |  |  |  |
	1--0--0--1--0--1--1--0
	|  |  |  |  |  |  |  |
	0--0--0--0--1--0--1--1
	|  |  |  |  |  |  |  |
	1--1--1--0--1--0--0--1

	Each digit represents a node. 0 represents a switch, 1 represents a compute unit.

	Compute units can do computations ("smart node"), while switches can only transfer data from one node to another ("dumb nodes").

*/

struct mesh_switch // node of a 4 way mesh
{
	int hasCU;		// if true, then it can do computations
	int reg;
	ComputeUnit * cu = NULL;
	mesh_switch * left;
	mesh_switch * right;
	mesh_switch * up;
	mesh_switch * down;

	void ShiftData(route r)
	{
		switch(r)
		{
			case mesh_left:
				left->cu->setR(reg);
				break;

			case mesh_right:
				right->cu->setR(reg);
				break;

			case mesh_up:
				up->cu->setR(reg);
				break;

			case mesh_down:
				down->cu->setR(reg);
				break;

			default:
				printf("ShiftData NOT WORKING");
				break;
		}
	}
};