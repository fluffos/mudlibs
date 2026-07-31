//zhenhuo.c 【太乙真火】weiqi...980305

#include <ansi.h>

inherit F_SSERVER;

int exert(object me)
{
        int success_adj, damage_adj;
        //object target;
        //int success_adj, damage_adj;
        object weapon;
        int damage,p;
        string msg,dodge_skill;
        object target;
        success_adj = 110;
        damage_adj = 100;

        if( !target ) target = offensive_target(me);

if (environment(me)->query("no_fight"))  return notify_fail("安全区内禁止施展法术。\n"); 

        if( !target
   

        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("你要对谁喷太乙真火？\n");


        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这门绝学只能对战斗中的对手使用。\n");

        if((int)me->query_skill("taiyi",1) < 100)
                return notify_fail("你的太乙道法还不够。。。\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("你的崆峒心法还不够。。。\n"); 
                

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不够，无法将真火喷出。\n");

        if((int)me->query("jing") < 10 )
                return notify_fail("你现在神智不清，别把自己烧伤了！\n");
   


        me->add("neili", -200);

        me->receive_damage("jing", 10);

        if( random(me->query("max_neili")) < 50 ) 
        {
                write("这一次好像不灵。\n");
                return 1;
        }

       msg = HIR "$N几个指头迅速捻动，突然张嘴一喷！红橙黄三道火焰呼！地一声向$n卷去！\n" NOR;
        message_combatd(msg, me,target);                
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = 100+(int)me->query_skill("kongdong-xinfa",1); 
            damage = damage + random(damage);
            damage +=(int)(me->query_skill("taiyi", 1)*8);
                        	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                msg=RED "结果$n被烧得焦头烂额！\n" NOR;
   

}
else
{
                msg="但是火焰被$n以内力一逼，反向$N回卷而去！\n" NOR; 
}
message_combatd(msg, me,target);                



        me->start_busy(3);
        return 3+random(5);
}


