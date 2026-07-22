// /u/beyond/obj/chahua.c
// this is made by beyond
// update 1997.6.30

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIR"抓破美人脸"NOR,({ "mei renlian", "flower", "hua" }) );
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("value", 45);
                set("material", "plant");
                set("long", "这是一朵抓破美人脸。\n");
                set("wear_msg", "$N拿起一朵$n别在胸前。\n");
                set("unequip_msg", "$N摘下胸前的$n。\n");
                set("armor_prop/armor", 0);
        }

        setup();
}