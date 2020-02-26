#include "Disk.h"

Disk::Disk()
{
}

Disk::Disk(int diskSize)
{
	size = diskSize;
}

int Disk::getDiskSize()
{
	return size;
}
