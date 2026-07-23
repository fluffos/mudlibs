// tengjia.c 藤甲
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("藤甲", ({ "teng jia" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "用藤编制的甲，可以取到一些防护作用。\n");
                set("material", "steel");
		set("value", 2000);
                set("armor_prop/armor", 80);
        }
        setup();
}

