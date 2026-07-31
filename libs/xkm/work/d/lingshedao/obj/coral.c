//Cracked by Roath
// fear 2002/1/31
#include <weapon.h>
#include "ansi.h"
// inherit ITEM;
inherit HAMMER;

string* titles = ({
        "珊瑚",
        "珊瑚",
        "珊瑚",
        "珊瑚",
        "珊瑚",
        "珊瑚",
        "珊瑚",
        "珊瑚",
        "珊瑚",
        "珊瑚",
});

void create()
{
        int i;
        i = random(sizeof(titles));
        if (i<2)
        set_name(HIW+titles[i]+NOR, ({ "white coral", "coral", "shan hu" }));
        else if (i<4)
        set_name(HIM+titles[i]+NOR, ({ "pink coral", "coral", "shan hu" }));
        else if (i<6)
        set_name(HIR+titles[i]+NOR, ({ "red coral", "coral", "shan hu" }));
        else if (i<8)
        set_name(HIB+titles[i]+NOR, ({ "blue coral", "coral", "shan hu" }));
        else
        set_name(HIY+titles[i]+NOR, ({ "yellow coral", "coral", "shan hu" }));

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个美丽的珊瑚。\n");
                set("value", 12000+random(10000));
                set("wield_msg","$N举起一块珊瑚准备战斗。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
                set("material", "stone");
        }
        init_hammer(15);
        setup();
}
