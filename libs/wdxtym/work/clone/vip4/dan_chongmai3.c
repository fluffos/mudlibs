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
	set_name(HIR "冲脉丹[上品]" NOR, ({ "chongmai dan3" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "用来辅助冲击奇经八脉的道具。\n");
		set("base_unit", "颗");
		set("base_value", 500);
		set("yuanbao", 30);
		set("needle/level",15);
		set("base_weight", 1);
	}
	setup();
}

