// bian.c 诡辩奇学
// Created by Lonely@yxcs 21/2/2002

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

string name() { return HIM "诡辩奇学" NOR; }

int perform(object me, string skill)
{
        int heal;
        object target;

        if (me->query("jing") < 50)
                return notify_fail("你的精神不济，难以构思诡辩。\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        if (! me->is_fighting())
                return notify_fail("你又不是在打架，诡辩能起什么作用呢？\n");

        if (! target->query("can_speak") || target->query("not_living"))
                return notify_fail("可惜啊！看来" + target->name() +
                                   "是听不懂你的话了。\n");
        if (target->query("family/family_name")!=me->query("family/family_name") )
                return notify_fail("对方不是你的同门,你诡辩没有人理睬你! \n");

        message_vision(HIM "$N" HIM "情急生智，对着$n" HIM
                       "就来了一套长篇大论，当真是天花乱坠。\n",
                       me, target);

        me->receive_damage("jing", 30 + random(20));

                message_vision(HIM "$n" HIM "听得晕晕乎乎，不知所以，"
                               "开始相信了，$N" HIM "趁机溜走。\n" NOR,
                               me, target);
                me->set_temp("success_flee", HIG "你成功的逃走了！\n" NOR);
       /* if( (int)me->query_skill("literate",1)< 4630 )
        me->set_skill("literate",4630);
         if( (int)me->query("weiwang")< 10000 )
        me->add("weiwang",1000);
       tell_object(me, "你的江湖威望提高了。\n");*/
                GO_CMD->do_flee(me);

        return 1;
}
