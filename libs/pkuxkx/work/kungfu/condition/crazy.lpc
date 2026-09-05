//modify by kiden
//发疯
inherit F_CLEAN_UP;

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( duration < 1 ) return 0;
    if( !living(me) ) 
    {
        message("vision", HIW+me->name() + "迷糊中嘿嘿奸笑了几声，显得十分诡异。\n"NOR, environment(me), me);
    }
    else 
    {
       switch(random(4))
       {
       case 0:
          message("vision", HIW+me->name() + "突然大笑三声，接着就嚎啕大哭起来。\n"NOR,environment(me), me);
          break;
       case 1:
          message("vision", HIW+me->name() + "解开裤带，旁若无人的在地上留下了一陀东西。\n"NOR,environment(me), me);
          break;
       case 2:      
          message("vision", HIW+me->name() + "指着自己说：“我是北侠第一高手！”\n"NOR,environment(me), me);
          break;
       case 3:
          message("vision", HIW+me->name() + "两眼无神，目光涣散，头发蓬松，嘴里咿咿呀呀的不知道说些什么。\n"NOR,environment(me), me);
          break;
       }                                
    }
    tell_object(me, HIB "你的头一阵眩晕！\n" NOR );

    me->receive_damage("qi", random(25), "发疯");
    me->receive_damage("jing", random(25), "发疯");
    COMBAT_D->report_status(me);
    me->start_busy(random(3));
    me->apply_condition("crazy", duration - 1);
    return CND_CONTINUE;
}

