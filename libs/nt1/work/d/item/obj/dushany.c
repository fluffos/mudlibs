// dushan-yu.c 独山玉

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIM "独山玉" NOR, ({ "dushan yu" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM "独山是位于中原地带的一座高拔孤立的石山。在其西南坡有着密集的玉脉，\n"
                                "此玉亦因山而得名独山玉。独山玉玉质细腻，色彩鲜艳。 \n" NOR);
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

