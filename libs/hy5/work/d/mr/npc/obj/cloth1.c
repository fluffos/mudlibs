// /u/beyond/mr/obj/cloth1.c
// this is made by beyond
// update 1997.6.20
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(MAG"粉红绸衫"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","这是一件粉红色的女儿上衣。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
