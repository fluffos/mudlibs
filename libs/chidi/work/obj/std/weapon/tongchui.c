// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("铜锤", ({ "tong chui" ,"tongchui" , "chui","hammer"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把轻铜锤，相当坚实。\n");
                set("value", 1000);
                set("material", "tong");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(15);
        setup();
}
