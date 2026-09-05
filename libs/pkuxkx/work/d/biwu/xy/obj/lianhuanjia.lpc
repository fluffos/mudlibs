// lianhuanjia.c 连环甲
//created by zine 25 aug 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIB"连环甲"NOR, ({ "lianhuan jia", "armor", "jia" }) );
        set_weight(15000);
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("unit", "件");
				set("material", "steel");
				set("value", 1);
				set("long", "这是传说中岳飞使用过的战甲。\n");
				set("armor_prop/armor", 800);
			}
        setup();
}
