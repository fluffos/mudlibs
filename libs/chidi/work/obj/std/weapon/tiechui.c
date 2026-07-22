// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("铁锤", ({ "tie chui" ,"tiechui" , "chui","hammer"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把沉甸甸的大铁锤，相当坚实。\n");
                set("value", 2000);
                set("material", "tie");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(25);
        setup();
}
