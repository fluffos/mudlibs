// tianhuang-stone.c 田黄石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY "田黄石" NOR, ({ "tianhuang stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIY "田黄石盛产于中国东南部，石质晶莹润泽，色彩明丽，纹理细腻，自古就\n"
                                "素有“一两田黄数两金”之说。\n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "gold");
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

