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
	set_name(HIG "冲脉丹[中品]" NOR, ({ "chongmai dan2" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "用来辅助冲击奇经八脉的道具。\n");
		set("base_unit", "颗");
		set("base_value", 500);
        set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);
		set("yuanbao", 20);
		set("needle/level",10);
		set("base_weight", 1);
	}
	setup();
}

