#pragma once
class Vec2
{
public:
	float x;
	float y;
public:
	Vec2() = default;
	Vec2(float x_in, float y_in);
	Vec2 operator+ (const Vec2& rhs) const;
	Vec2& operator+=(const Vec2& rhs);
};