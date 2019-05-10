#pragma once
#include "IGeomtry.h"

class Circle : public IGeomtry
{
public:
	Circle();
	~Circle();

	void Draw() override;

private:

};