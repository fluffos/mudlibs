// raincoat.c
// for xiakedao
// by aiai 98/10/28

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(YEL"油布雨衣"NOR, ({ "raincoat" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

