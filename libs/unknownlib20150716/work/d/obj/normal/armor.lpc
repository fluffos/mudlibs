#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIG"战甲"NOR, ({"jia", "armor"}));
        set_level(1);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件金线织就的宝甲．\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 100);
				set("no_sell",1);
				set("armor_prop/dodge", -5);
        }
        setup();
}


