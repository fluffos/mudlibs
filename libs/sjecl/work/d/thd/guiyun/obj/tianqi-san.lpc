#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIC"田七鲨胆散"NOR, ({"tianqi san", "san"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "这是一包桃花岛的田七鲨胆散，有解百毒的奇效。\n");
                set("value", 10);
		set("unique", 3);
		set("no_give",1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
              return notify_fail("你要吃什么？\n");
        me->clear_conditions_by_type("poison");
        message_vision(HIR"$N服下一包田七鲨胆散，一股清凉的气息自丹田涌上来。\n"NOR, this_player());
        destruct(this_object());
        return 1;
}
