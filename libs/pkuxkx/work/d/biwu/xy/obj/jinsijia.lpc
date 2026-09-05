// jinsijia.c 金丝甲
// created by zine 25 aug 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY"金丝甲"NOR, ({ "jinsi jia", "armor", "jia" }) );
        set_weight(10000);
		set("long", "一件金光闪闪的战甲。\n");
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("unit", "件");
				set("material", "steel");
				set("value", 1);
				set("armor_prop/armor", 600);
			}
        setup();
}
