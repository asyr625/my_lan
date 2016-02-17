#ifndef VALUE_H
#define VALUE_H
#include <iostream>

class Value
{
    enum Value_Type
    {
        BOOL,
        INT,
        DOUBLE,
        STRING
    };

public:
    Value();
    Value(Value_Type type);
    virtual ~Value();

    Value_Type type();
    Value& operator=(const Value& v);
private:
    Value_Type    _type;
};

class Bool : public Value
{
public:
    Bool();
    Bool(bool val);
    ~Bool();

    bool& get_val();
    void set_val(bool& val);
    Bool& operator=(const Bool& v);
private:
    bool    _val;
};

class Int : public Value
{
public:
    Int();
    Int(int& val);
    ~Int();

    int& get_val();
    void set_val(int& val);
    Int& operator=(const int& v);
private:
    int     _val;
};


class Double : public Value
{
public:
    Double();
    Double(Double& val);
    ~Double();

    int& get_val();
    void set_val(Double& val);
    Double& operator=(const Double& v);
private:
    double  _val;
};

class String : public Value
{
public:
    String();
    String(String& val);
    ~String();

    String& get_val();
    void set_val(String& val);
    String& operator=(const String& v);
private:
    std::string     _val;
};

#endif // VALUE_H
