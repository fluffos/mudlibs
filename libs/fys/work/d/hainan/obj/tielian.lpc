// blade.c

#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("寒铁链", ({"tielian", "lian", "whip"}));
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一条长长的铁链，上面隐现红茫．\n");
                set("unit", "条");
                set("value", 500);
        }
        init_whip(25);
        setup();
}

