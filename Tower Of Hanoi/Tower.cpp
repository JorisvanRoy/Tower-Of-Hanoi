#include "Tower.h"

Tower::Tower()
{
}

Tower::Tower(std::vector<Disk> disks)
{
	this->storedDisks = disks;
}

std::vector<Disk> Tower::getDisks()
{
	return storedDisks;
}

Disk Tower::getTopDisk()
{
	return storedDisks.back();
}

void Tower::addDisk(Disk disk)
{
	storedDisks.insert(storedDisks.end(),disk);
}

void Tower::removeDisk()
{
	storedDisks.erase(storedDisks.end()-1);
}
