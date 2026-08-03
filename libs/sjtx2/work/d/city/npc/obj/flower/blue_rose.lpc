
#include <ansi.h>
#include <armor.h>

//inherit HEAD;
inherit COMBINED_ITEM;


int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(BLU "蓝色妖姬" NOR, ({"lanse yaoji", "lanse", "yaoji"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵玫瑰中的极品，传说中的蓝色妖姬，象征着尊贵，浪漫爱情。\n");
		set("unit", "朵");

		set("value", 300000);
		set("base_unit", "朵");
        set("base_weight", 100);
	set("flower_w",1);
	
	        set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");

			}
	set_amount(1);
	 
}
#include "flower.h"