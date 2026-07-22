// /u/beyond/obj/chahua1.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIY"十八学士"NOR,({ "shiba xueshi", "hua", "flower" }) );
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("value", 70);
                set("material", "plant");
                set("long", "这是一朵十八学士。\n");
                set("wear_msg", "$N拿起一朵$n别在胸前。\n");
                set("unequip_msg", "$N摘下胸前的$n。\n");
                set("armor_prop/armor", 0);
        }

        setup();
}
