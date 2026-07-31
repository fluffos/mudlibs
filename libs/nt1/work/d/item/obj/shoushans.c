// shoushan-stone.c 寿山石

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIM "寿山石" NOR, ({ "shoushan stone" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM "寿山石质地晶莹脂润，纹理细腻，硬度适中，色彩瑰丽，常呈珍珠或玻璃\n"
                                "光泽，有的赤若鸡冠、有的黄似枇杷，有的白如雪花，有的黑似漆墨，民\n"
                                "间传说女娲曾用此石补天。\n" NOR);
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

