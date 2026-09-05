//麻袋
//create By Zine 21 Aug 2010
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
void create()
{
	set_name(YEL"麻袋"NOR, ({ "ma dai", "madai", "dai", "bag" }));
	set_weight(1000);
	if( clonep() )
                set_default_object(__FILE__);
    else 
		{
			set("long", "一个破破烂烂的麻袋，不知道有什么用。\n");
			set("material", "cloth");
			set("unit", "个");
			set("value", 0);
			set("remove_msg", "$N将身后的麻袋除了下来。\n");
			set("wear_msg", "$N将麻袋搭在肩上。\n");
		}
	setup();
}

