#pragma once
class Field
{
public:
	// Constructor and Destructor
	Field();
	~Field();
	// Variables
	enum FieldType { EMPTY, DANGER, WELL, RELIC };
	FieldType type;
};

