// tiechui.c

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name("铁锤",({ "tie chui", "chui" }) );
         set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "bamboo");
                set("long", "这是一个大石头。\n");
                set("wield_msg", "$N拿出一个$n，试了试重量后握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_hammer(20);
        setup();
}
