// xianglian.c
//cgbii 96.10.3
#include <armor.h>

inherit NECK;

void create()
{
        set_name("珍珠项链", ({ "xiang lian","lian" }));
	set("long","这是一串珍珠项链，是渔民女儿的嫁妆。\n"); 
        set_weight( 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("value",30);
                set("material", "silver");
                set("armor_prop/armor", 1);
        }
        setup();
}
