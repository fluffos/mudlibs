// yufeng_poison.c 玉蜂针毒
// By Kayin @ CuteRabbit Studio 1999/3/23 new

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int i,dam_kee,dam_gin,dam_sen;
        
        i = 30/(duration+1);
    dam_kee = (int) me->query("max_qi")/i;
    dam_gin = (int) me->query("max_jing")/i;
    dam_sen = (int) me->query("max_jing")/i;


        if( duration < 1 ) {
            tell_object(me, MAG"烟锁残霞"NOR + "发作完了。\n");
                } else {
                        tell_object(me, MAG"烟锁残霞"NOR + "发作了，你觉得身上一阵僵冷，皮肤透出一层紫色。\n");
                        message("vision", me->name() + "似乎很怕冷，浑身僵硬，不停地打哆嗦，皮肤上透出一层诡异的紫色。\n", 
                                        environment(me), me);
                }
      me->receive_wound("qi",55 + random(100));
      me->receive_wound("jing", 50);
      me->apply_condition("canxia", duration - 1);
      me->start_busy(2);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

