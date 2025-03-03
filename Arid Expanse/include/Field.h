#ifndef FIELD_H
#define FIELD_H


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

#endif // FIELD_H
