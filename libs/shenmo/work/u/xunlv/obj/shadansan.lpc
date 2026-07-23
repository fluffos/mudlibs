// /clone/drug/shadansan.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");

}

void create()
{
        set_name(HIY"鲨胆散"NOR, ({"shadan san", "san"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 1500);
                set("medicine", "drug");
                set("make/drug", 1);
        }
        setup();
}

int do_eat(string arg)
{

        object me = this_player();
        if (!living(me)) return notify_fail("想当机吗？\n");
        if (!id(arg)) return 0;
          message_vision(HIW"\n$N吃下一颗鲨胆散，顿时觉得精力旺盛，伤口奇迹般的愈合了。\n\n"NOR,me);
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("eff_qi"));
        me->set("eff_jingli", me->query("max_jingli"));
        me->set("jingli", me->query("eff_jingli"));
        destruct(this_object());
        return 1;
}


