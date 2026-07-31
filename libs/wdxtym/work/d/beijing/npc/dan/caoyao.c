// caoyao.c

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

void create() 
{
	set_name(HIG "不知名草药" NOR, ({"cao yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "这是一株生长在密林中的不知名的草药，一般人都会误认成杂草。\n");
		set("base_unit", "株");
		set("base_weight", 1);
	}
	setup();
}
