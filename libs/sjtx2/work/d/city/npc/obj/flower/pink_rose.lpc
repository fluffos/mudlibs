
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIM "粉玫瑰" NOR, ({"fen meigui", "fen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵含苞欲放的粉玫瑰，象征着永远的爱。\n");
		set("unit", "朵");
		set("value", 45000);
		set("base_unit", "朵");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
}
#include "flower.h"