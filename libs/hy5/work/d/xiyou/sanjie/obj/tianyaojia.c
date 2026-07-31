// tianyaojia.c 天妖战甲

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(RED"天妖战甲"NOR, ({"tianyao armor","zhanjia", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "大天妖的战甲，能蓄妖气为己用。\n");
                set("material", "gold");
                set("value", 100);
                set("armor_prop/armor", 70);
		set("armor_prop/dodge", 15);
        }
        setup();
}


