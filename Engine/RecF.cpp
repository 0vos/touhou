#include "RecF.h"

RecF::RecF(double left_in, double right_in, double top_in, double bottom_in)
{
	left = left_in;
	right = right_in;
	top = top_in;
	bottom = bottom_in;
	moveable = true;
	hasshot = false;
	index = 1000;
	life = 0;
}

bool RecF::IsOverlappingOf(int rx, int ry) const
{
	if (rx >= left && rx <= right && ry <= bottom && ry >= top)
	{
		return true;
	}
	return false;
}

bool RecF::IsOverlappingOf(RecF& orec) const
{
	//up line overlap
	for (int i = orec.left; i <= orec.right; i+=5)
	{
		if (this->IsOverlappingOf(i, orec.top))
		{
			return true;
		}
	}
	//bottom line overlap
	for (int i = orec.left; i <= orec.right; i+=5)
	{
		if (this->IsOverlappingOf(i, orec.bottom))
		{
			return true;
		}
	}
	//left line overlap
	for (int i = orec.top; i <= orec.bottom; i+=5)
	{
		if (this->IsOverlappingOf(i, orec.left))
		{
			return true;
		}
	}
	//right line overlap
	for (int i = orec.top; i <= orec.bottom; i+=5)
	{
		if (this->IsOverlappingOf(i, orec.right))
		{
			return true;
		}
	}
	return false;
}

