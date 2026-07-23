// ai.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    mapping fam;
    object obj, old_target, where = environment(me);

    if (me->query("age") < 17)
         return notify_fail("你连十七岁都没到，就学坏啊！\n");
    if(me->is_busy())
        return notify_fail("你现在正忙。\n");

    if (me->query("mud_age")-me->query("marks/makelove") < 180)
         return notify_fail("一天内连续这样很伤元气的，你就休息一会吧。\n");

    if ( !(where->query("sleep_room"))|| (where->query("no_sleep_room")) )
         return notify_fail("做这种事当然需要一个安全的地方。\n");

    if (!arg || !objectp(obj = present(arg, environment(me))))
         return notify_fail("你现在很冲动，可是一点辙都没有。\n");

    if (me->query("gender") =="无性")
         return notify_fail("你连那个工具都没有，还想干好事？\n");

    if(obj==me) return notify_fail("你自己解决？那就没必要这么麻烦嘛。\n");
    if(query_ip_name(obj)==query_ip_name(me))
         return notify_fail("你自己解决？那就没必要这么麻烦嘛。\n");

    if (obj->query("age") < 17)
         return notify_fail("人家十七岁都没到，你想害人啊！\n");

    if (userp(obj) && obj->query("mud_age")-obj->query("marks/makelove") < 180)
         return notify_fail("一天内连续这样很伤元气的，让"+obj->query("name")+"休息一会吧。\n");

    if (obj->query("gender") == me->query("gender"))
         return notify_fail("你心中大喊：可惜！对方生理结构居然和你一样。\n");

    if (!obj->is_character()) return notify_fail("哇，死的东西都不放过啊。\n");

    if (!living(obj) )
         return notify_fail(obj->name() + "的样子你没看到？干脆强奸得了。\n");

    if (userp(obj) && (object)obj->query_temp("pending/ai")!=me )
    {
         message_vision("\n$N对著$n说道：我的爱人，我...我想和你困觉.\n\n",me,obj);
         if( objectp(old_target = me->query_temp("pending/ai")) )
             tell_object(old_target,YEL+me->name()
                    + "忽然对你没什么兴趣了。\n"NOR);
         me->set_temp("pending/ai", obj);
         tell_object(obj, YEL"如果你接受对方爱抚，请你也对" + me->name() 
             + "("+(string)me->query("id")+")"+ "下一次 ai 指令。\n" NOR);

         write(YEL "对方是玩家控制的人物，你必须等对方同意才能干那事。\n" NOR);
         return 1;
    }

    if (!userp(obj) && ( random(10)!=2)) 
    {
         message_vision("\n$n对$N怒目相向: 你怎麽能这样？甩头就走了。\n",me,obj);
         destruct(obj);
         return 1;
    } else
    {
         message_vision("\n$N和$n云雨一番，曲尽温柔，无所不至。\n",me,obj);
         obj->start_busy(3);
         me->start_busy(3);
         message_vision("许久许久，$N和$n整衣理面，精神大振。\n\n", me,obj);

         me->add("eff_jing",-5);
         me->add("jing",-10);
         me->set("qi",me->query("eff_qi"));
         if (obj->query("id") == me->query("couple/couple_id"))
            me->set("neili",me->query("max_neili"));
         else
            me->add("neili",10);
         me->add("combat_exp",1);
         me->delete_temp("pending/ai");
         me->save();
         me->set("marks/makelove",me->query("mud_age"));
         obj->add("eff_jing",-5);
         obj->add("jing",-10);
         obj->set("qi",obj->query("eff_qi"));
         obj->delete_temp("pending/ai");
         if (userp(obj))
         {
             if (me->query("id") == obj->query("couple/couple_id"))
                 obj->set("neili",obj->query("max_neili"));
             else
                 obj->add("neili",10);
             obj->save();
             obj->set("marks/makelove",obj->query("mud_age"));
         }
     }
     me->set("couple/have_couple",1);
     obj->set("couple/have_couple",1);
     return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : ai <人物>

这个指令让你向一个人物进行爱抚，会消耗精力，却可以补充你的体力，
增长经验，但是有许多状况你的要求会被拒绝。

其他相关指令: qiangjian

HELP
    );
    return 1;
}

