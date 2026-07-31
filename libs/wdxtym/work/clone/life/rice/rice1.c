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
	set_name("劣质的"+rices[i], ({"liezhi rice", "rice"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "条");
		set("long", "这是一通过种田得到的劣质的"+rices[i]+"。\n");
		set("base_value", 1000);
		set("base_weight", 1);
	}
	setup();
}
