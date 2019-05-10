#pragma once
#include "IGeomtry.h"

class Triangle : public IGeomtry
{
public:
	Triangle();
	~Triangle();

	void Draw() override;


private:

};