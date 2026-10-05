#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
        add_action("do_quit","put");
        add_action("do_quit","beg");
        add_action("do_quit","give");
        add_action("do_quit","steal");

}
void create()
{
        set_name(HIW"礼物"NOR,  ({"liwu",}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
 set("long", "全体巫师 祝您：新婚快乐\n")
        }
        setup();
}
 int do_quit(string arg)
{
write(this_player()->query("name")+"，干什么呢，自己用不好吗？\n");
    return 1;
}
int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
        return notify_fail("你要吃什么？\n");
//  me->add("combat_exp", 5555)
//   me->add("potential", 22222)
me->add("per",1)
 message_vision(HIC "$N吃下礼物，恭喜你增加学习值22222，战斗值55555！\n" NOR, me);
        destruct(this_object());
        return 1;
}

