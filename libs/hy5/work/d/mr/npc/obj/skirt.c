// /u/beyond/mr/obj/skirt.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(MAG"紫杉长裙"NOR, ({ "chang qun", "qun", "skirt" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","这是一条紫色的长裙。\n");
                set("unit", "条");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 5);
                

        }
setup();
}
