// xianglian.c
//cgbii 96.10.3
#include <armor.h>

inherit NECK;

void create()
{
        set_name("玛瑙项链", ({ "manao lian","lian" }));
	set("long","这是一串昂贵的玛瑙项链，是倭寇从中国商船上掠夺来的。\n"); 
        set_weight( 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("value",3000);
                set("material", "gold");
                set("armor_prop/armor", 1);
        }
        setup();
}
