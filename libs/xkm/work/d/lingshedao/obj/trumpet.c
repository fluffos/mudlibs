//Cracked by Roath
// fear 2002/1/31
#include "ansi.h"
// #include <weapon.h>
// inherit HAMMER;
inherit ITEM;

string* titles = ({
        "海螺",
        "海螺",
        "海螺",
        "海螺",
        "海螺",
        "海螺",
        "海螺",
        "海螺",
        "海螺",
        "海螺",
});

void create()
{
        int i;
        i = random(sizeof(titles));
        if (i<2)
        set_name(HIW+titles[i]+NOR, ({ "hailuo" }));
        else if (i<4)
        set_name(HIM+titles[i]+NOR, ({ "hailuo" }));
        else if (i<6)
        set_name(HIR+titles[i]+NOR, ({ "hailuo" }));
        else if (i<8)
        set_name(HIB+titles[i]+NOR, ({ "hailuo" }));
        else
        set_name(HIY+titles[i]+NOR, ({ "hailuo" }));

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个颜色鲜艳的海螺。\n");
                set("value", 15000+random(15000));
                set("material", "stone");
        }
        setup();
}

void init()
{
        add_action("do_blow","blow");
}

int do_blow(string arg)
{
        object me = this_player();
        object hailuo = present("hailuo", me);
		string* msg;

        if ( !arg|| arg != "hailuo" ) 
           return notify_fail("你要吹什么？\n");

        if (this_player()->is_busy())
           return notify_fail("你正忙着呢！\n");

		msg = ({
				CYN"$N拿起"NOR + (string)hailuo->query("name") +CYN"，放在嘴边用力一吹，发出声音：“嘟～～～嘟～～～” "NOR,
					});
        me->start_busy(1);

        message_vision("\n"+ msg[random(sizeof(msg))] +"\n" , me);
        return 1;
}
