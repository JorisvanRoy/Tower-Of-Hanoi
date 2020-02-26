#pragma once

#include "Disk.h"
#include <vector>

class Tower
{
private:
	std::vector<Disk> storedDisks;

public:
	Tower();
	Tower(std::vector<Disk> disks);
	std::vector<Disk> getDisks();
	Disk getTopDisk();
	void addDisk(Disk disk);
	void removeDisk();
};

