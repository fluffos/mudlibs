// tiechui.c

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIB"水壶"NOR,({ "shui hu", "hu" }) );
         set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "bamboo");
                set("long", "这是一把水壶。\n");
                set("wield_msg", "$N拿出一把$n，。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_hammer(5);
        setup();
}

