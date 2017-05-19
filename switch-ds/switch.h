#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

enum route { mesh_left, mesh_down, mesh_right, mesh_up };

class ComputeUnit
{
	private:
	int reg;

	public:
	int setR(int x)
	{
		reg = x;
	}
	void function()
	{
		cout << reg++;
	}
	ComputeUnit()
	{
		reg=0;
	}
};

struct mesh_switch // node of a 4 way mesh
{
	int hasCU;
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