// ziyawu-stone.c 紫牙乌

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY "紫牙乌" NOR, ({ "ziyawu stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIY "紫牙乌因其形状象石榴籽，又称石榴石。它是古代比较常见的中低档宝石\n"
                                "之一。颜色浓艳纯正，光泽明润，是人们喜爱的宝石品种。许多少数民族\n"
                                "以紫牙乌象征忠实、友爱和贞操。\n" NOR);
                set("value", 50000);
                set("unit", "块");
                set("can_be_enchased", 1);
                set("enchased_armor", 1);
                set("magic/type", "wood");
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

