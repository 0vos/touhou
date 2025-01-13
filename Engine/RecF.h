#pragma once
class RecF
{
public:
	RecF(double left_in, double right_in, double top_in, double bottom_in);
	RecF() = default;
	bool IsOverlappingOf(int rx, int ry) const;
	bool IsOverlappingOf(RecF& orec) const;
public:
	double left;
	double right;
	double top;
	double bottom;
	int index;
	int life;
	bool moveable;
	bool hasshot;
};