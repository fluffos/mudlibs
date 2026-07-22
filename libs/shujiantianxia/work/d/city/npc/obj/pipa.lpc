#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM "琵琶" NOR, ({ "pi pa"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是把琴头雕有如意，用紫檀制成的四相十三品琵琶。\n");
		set("value", 2000);
		set("material", "wood");
		}
	setup();
}