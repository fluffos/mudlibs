// bamboo_stick.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("竹杖", ({"zhuzhang", "stick"}));
        set_weight(3000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根泛着黄的竹杖。\n");
                set("value", 1000);
                set("material", "bamboo");
                set("wield_msg", "$N抽出一根竹杖抓在手中。\n");
                set("unwield_msg", "$N把手中的竹杖插回腰中。\n");
        }
        init_staff(20);
    	setup();
}
