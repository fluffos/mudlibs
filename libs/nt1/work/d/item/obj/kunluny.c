// kunlun-yu.c 昆仑玉

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIM "昆仑玉" NOR, ({ "kunlun yu" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM "盛产于西部昆仑山脉，是岫玉中的极品。色泽鲜艳、质地细腻、晶莹明亮，\n"
                                "硬度适中。\n" NOR);
                set("value", 500000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "soil");
                set("magic/power", 100);
                set("armor_prop/per", 7);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
        }
        setup();
}

int query_autoload() { return 1; }

