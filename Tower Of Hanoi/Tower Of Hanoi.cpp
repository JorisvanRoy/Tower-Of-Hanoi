// Tower Of Hanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tower.h"

int diskAmount = -1;

std::vector<Tower> towers = { Tower({ Disk(3),Disk(2),Disk(1) }), Tower(), Tower() };

void render();
void askMove();
void moveDisks(int from, int to);
void checkCompletion();

int main()
{
	diskAmount = towers[0].getDisks().size();
	render();
}

void render()
{
	for (size_t i = 0; i < towers.size(); i++)
	{
		std::vector<Disk> disks = towers[i].getDisks();
		for (size_t j = 0; j < disks.size(); j++)
		{
			std::cout << disks[j].getDiskSize() << " ";
		}

		std::cout << std::endl << std::endl;
	}
	askMove();
}

void askMove()
{
	int fromIndex, toIndex;

	std::cout << "From what tower index do you want to move the right most piece?" << std::endl;
	std::cin >> fromIndex;
	std::cout << "To what index do you want to move the disk to?" << std::endl;
	std::cin >> toIndex;

	moveDisks(fromIndex, toIndex);
	render();
}

void moveDisks(int from, int to)
{
	Disk diskFrom;
	//Check if there is a disk to be moved
	if (towers[from].getDisks().size() > 0)
	{
		diskFrom = towers[from].getTopDisk(); 
		Disk diskTo;
		//Check if there is a disk on the new tower
		if (towers[to].getDisks().size() > 0)
		{
			diskTo = towers[to].getTopDisk();
			//Compare disk sizes
			if (diskFrom.getDiskSize() < diskTo.getDiskSize())
			{
				//Switch disk from old to new if disk is smaller
				towers[to].addDisk(diskFrom);
				towers[from].removeDisk();
				checkCompletion();
			}
			else {
				//If disk is bigger give error to user
				std::cout << "Illegal move! please try again" << std::endl;
				askMove();
			}
		}
		else {
			//If there is no disk on the new tower just place the disk
			towers[to].addDisk(diskFrom);
			towers[from].removeDisk();
		}
	}
	else {
		std::cout << "Illegal move! You are trying to move no disk" << std::endl;
		askMove();
	}
	
	
	
}

void checkCompletion()
{
	Tower tower = towers.back();
	if (tower.getDisks().size() == diskAmount)
	{
		char answer;
		std::cout << "Congratulations you have completed Tower of Hanoi! Would you like to play again? [Y/N]" << std::endl;
		std::cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			system("cls");
			towers = { Tower({ Disk(3),Disk(2),Disk(1) }), Tower(), Tower() };
			main();
		}
	}
}
