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
void create()
{
	set_name("优质的草料", ({"quest grass", "cao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "堆");
		set("long", "这是一堆割下来的优质的草料。\n");
		set("base_value", 50);
		 set("no_shop",1);
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            set("no_get",1);
		set("base_weight", 1);
	}
	setup();
}
