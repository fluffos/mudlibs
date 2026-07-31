// donghai-stone.c 东海石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIM "东海石" NOR, ({ "donghai stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM "相传此石来自东海蓬莱等三座仙山，由于其外观貌不惊人，所以流落民间，\n"
                                "不为人知。但其神奇功能如果被利用出来，将具有不可预知的神效。 \n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "soil");
                set("magic/power", 100);
                set("armor_prop/per", 5);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
        }
        setup();
}

int query_autoload() { return 1; }

