//Cracked by Roath

//Ansi 99.12
#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "血出"ZJBR"无痕"; }
int perform(object me, object target)
{
        int ap,dp,damage,chance;
        string msg;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「血出无痕」？\n");

        if(!me->is_fighting())
                return notify_fail("「血出无痕」只能在战斗中使用！\n");
   
        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("neili") < 500 )
                        return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("chuixue-jian", 1) < 300)
                return notify_fail("你的吹雪剑法修为还不够，使用这一招会有困难！\n");


        msg = CYN"\n$N手腕晃动如疾风，以砍断三千尺飞流的速度，直逼$n！\n"NOR;
        ap = me->query("combat_exp");
        ap = ap;
        dp = target->query("combat_exp"); 
	  if(random(ap/2)>dp) {
                damage = me->query_skill("sword") * 2 + me->query("jiali");
                if (damage > 1500) damage = target->query("max_qi")/10;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/3);
     target->start_busy(random(4)+2);
                msg += CYN"结果$n被$N的「血出无痕」拦腰而过！\n"NOR;
        }
        
        else 
                msg += "但是被$n躲开了。\n"NOR;
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
   
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->add("neili",-80-me->query("jiali"));
        me->start_busy(3);
        return 1;
}
