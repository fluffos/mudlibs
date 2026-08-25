// by fire on Dec. 12 1997
//   The following is an attempt at a value module.
// m_value.c
#include <mudlib.h>
#include <sanguo.h>
inherit CHINESE_DA;
int object_value = 0;
string currency_type="coin";
void set_value(int value)
{
    object_value = value;
}
int query_value()
{
    return object_value;
}
void set_currency_type(string stype)
{
	currency_type=stype;
}
string query_currency_type()
{
	return currency_type;
}
int query_absolutevalue()
{
	switch(currency_type)
	{
		case "coin" :
			return object_value;
		case "silver" :
			return object_value*100;
		case "gold" :
			return object_value*10000;
		default:
			return 0;
	}
}
			
string query_chinesevalue()
{
	int abv;
	abv=query_absolutevalue();
	return chinese_value(abv);
}
