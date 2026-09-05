//by hehe
//2003.3.18

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("锄头", ({ "chutou", "chu" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把种地用的锄头，非常光亮，看来是经常使用。\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(5);
        setup();
}