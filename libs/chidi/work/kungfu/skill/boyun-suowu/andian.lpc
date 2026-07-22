#include <ansi.h>
#include <skill.h>
#include <weapon.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon,ob;
        int skill,dex,dext,dod,dodt,sou,tag;
        string msg;
        
        me->clean_up_enemy();
        target = me->select_opponent();

        if( !target ) target = offensive_target(me);

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你手上不能装备任何东西。\n");

        if( (int)me->query_skill("boyun-suowu", 1) < 100 )
                return notify_fail("你的「拨云锁雾」不够娴熟，不能使用「云雾暗点」。\n");
        if( (int)me->query_skill("tangmen-xinfa",1) < 100)
                return notify_fail("你的心法不够熟练！\n");

        if( (int)me->query("neili") < 800 ) 
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("boyun-suowu");
        dex = me->query("dex");
        dext = target->query("dex");
        dod = me->query_skill("dodge");
        dodt = target->query_skill("dodge");
        sou = dex*dod;
        tag = dext*dodt*30/skill;

        msg = HIG "$N手腕一翻，信手一个拈花诀，内力暗吐，“嗤”的一声，破空而去!\n"NOR;

        message_vision(msg, me, target);

        me->add("neili", -500);
        
        if (random(sou) > tag)
        {
          target->start_busy( 2 + (int)me->query("hand")/50);
          msg = HIC "$n全身顿觉一麻，似乎不能动弹。\n"NOR;
        }  
        else msg = HIM "只见$n侧身一让，一阵风声，破空而过！\n"NOR;  
        message_vision(msg, me, target);
        
        return 1;
}
