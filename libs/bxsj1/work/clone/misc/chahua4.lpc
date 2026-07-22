// hshacha.c
// build by lklv 2001.9.28

#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
	set_name(HIR"红装素裹"NOR,({ "hongzhuang suguo", "flower", "hua" }) );
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("value", 90);
                set("material", "plant");
                set("long", "这是一朵红装素裹。\n");
                set("wear_msg", "$N拿起一朵"HIR"红装素裹"NOR"别在胸前。\n");
                set("unequip_msg", "$N摘下胸前的$n。\n");
                set("armor_prop/armor", 0);
        }

        setup();
}
