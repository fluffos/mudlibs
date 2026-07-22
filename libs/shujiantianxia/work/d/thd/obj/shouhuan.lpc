#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit HANDS;

void create()
{
        set_name(HIW"银手环"NOR, ({"yin shouhuan", "yin", "shouhuan"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个奇怪的手环，似乎没有重量。\n");
                set("value", 1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("material", "silver");
                set("armor_prop/dodge",5);
                set("armor_prop/hand",5);
                set("wear_msg", HIW "$N戴上一个银手环。\n" NOR);
                set("remove_msg", HIW "只见$N将银手环褪了下来。\n" NOR);
        }
        setup();
}

