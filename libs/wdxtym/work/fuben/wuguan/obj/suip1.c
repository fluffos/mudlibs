// jinsha.c

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
	set_name(HIW "神秘碎片①" NOR, ({ "sp1" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一片神奇的碎片，巫师说另有妙用。\n");
		set("base_unit", "片");
		set("base_value", 500);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);
		set("yuanbao", 10);
		set("base_weight", 1);
	}
	setup();
}

