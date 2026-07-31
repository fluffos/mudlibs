// kongque-stone.c 孔雀石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIM "孔雀石" NOR, ({ "kongque stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM "孔雀石由于颜色酷似孔雀羽毛上斑点的绿色而获得如此美丽的名字。其形\n"
                                "体各异，色彩艳丽，是古时的一种常用玉石。民间多是利用孔雀石作为儿\n"
                                "童的护身符。\n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "fire");
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

