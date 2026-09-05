#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("三笑逍遥散", ({ "sanxiaoxiaoyao san", "poison", "xiaoyao san", "san" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "一包无色的粉末, 看样子不是寻常物品. \n");
                set("no_put", 1);
                set("pour_type", "sanxiao_poison");
        }
}

int init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();

                return notify_fail("你找死啊，毒药怎么可以乱吃？\n");

        //me->set_temp("death_msg", "误食逍遥散被毒死了。");
           me->receive_wound("qi", 5500, "服食三笑逍遥散" );
        message_vision("$N仰头咽下一包" + name() + "。\n", me);
        destruct(this_object());
        return 1;
}

void owner_is_killed()
{
    say("逍遥散落到地上不见了.....\n");
    destruct(this_object());
}
