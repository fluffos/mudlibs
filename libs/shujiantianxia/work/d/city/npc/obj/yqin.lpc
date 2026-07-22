#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN "瑶琴" NOR, ({ "yao qin", "qin"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是把琴体呈扁长方形，用花梨木制成，十三弦的瑶琴。\n");
		set("value", 2000);
		set("material", "wood");
		}
	setup();
}