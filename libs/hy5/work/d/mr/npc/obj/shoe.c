// /u/beyond/mr/obj/shoe.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <armor.h>
inherit BOOTS;
//inherit EQUIP;
void create()
{
        set_name(GRN"踏雪无痕"NOR, ({ "shoes", "xie" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","这是一双小巧的女儿鞋。\n");
                set("unit", "双");
                set("value", 0);
		set("no_transfer",1);
                set("material", "cloth");
                set("armor_type", "feet");

        }
}
