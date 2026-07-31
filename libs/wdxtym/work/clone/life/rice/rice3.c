// shedan.c

#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
string *rices=({"大米","玉米","番薯"});
int i=random(sizeof(rices));
void create()
{
	set_name("优质的"+rices[i], ({"youzhi rice", "rice"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "条");
		set("long", "这是一通过种田得到的优质的"+rices[i]+"。\n");
		set("base_value", 5000);
		set("base_weight", 1);
	}
	setup();
}
