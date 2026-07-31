// saoba.c
// Design By ymh 飞影 email:stcoolman@21cn.com

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("扫把", ({ "sao ba" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把扫地用的扫把。\n");
                set("value", 30);
                set("material", "wood");
                set("wield_msg", "$N拿出一把$n，扛在肩上。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(1);
        setup();
}
