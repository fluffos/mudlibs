// qimen.c 奇门玉箫
// Created by Darken@sh.SJ
// Modified by Numa@ln.SJ

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time, lvl;

        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("「奇门玉箫」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if((int)me->query_skill("yuxiao-jian",1) < 70 )
                return notify_fail("你的玉箫剑法还不够火候，使不出「奇门玉箫」。\n");


        if((string)me->query_skill_mapped("sword") != "yuxiao-jian" && userp(me))
                  return notify_fail("你现在无法使用「奇门玉箫」！\n");

        if((string)me->query_skill_mapped("parry") != "yuxiao-jian" && userp(me))
                  return notify_fail("你现在无法使用「奇门玉箫」！\n");

        if( (int)me->query_skill("qimen-wuxing", 1) < 60 )
                return notify_fail("你的奇门八卦不够娴熟，无法施展出奇门玉箫。\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 60)
                return notify_fail("你的碧波神功生功火候不够，无法施展出奇门玉箫。\n");

        if((int)me->query_temp("yuxiao_lian") )
               return notify_fail("你现在已经在向对手使用「奇门玉箫」了。\n");

        if((int)me->query("neili", 1) < 500 )
                return notify_fail("你的内力太少了，无法使出「奇门玉箫」！\n");
                
        if((int)me->query("jing") < 100 )
                return notify_fail("你的精力太少了，无法使出「奇门玉箫」！\n");

        attack_time = random((int)me->query_skill("yuxiao-jian", 1) / 30)+2;

        if(attack_time < 1)
               attack_time = 1;
        if(attack_time > 4)  attack_time = 4;

        msg = HIG "$N手中"+weapon->name()+HIG"连刺，潇洒自如，招招都是攻势，一招不待$n化解开去，剑招已连绵而至！\n"+
                  "$N东刺一剑，西削一招，连出"+chinese_number(attack_time)+"招，与武学常理完全相反。\n"+
                  "$n愈斗愈惊，周身要害似已全在"+weapon->name()+HIG"笼罩之下！\n"NOR;
        message_vision(msg, me, target);
        lvl = random((me->query_skill("yuxiao-jian", 1) + me->query_skill("qimen-wuxing", 1)))/ 4;
	me->add_temp("apply/attack", lvl/8);	
	me->add_temp("apply/damage", lvl/8);
        me->add_temp("apply/dexerity", lvl);
        for(i = 0; i < attack_time; i++)
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        me->start_busy(2);
        me->add("neili", -150);
        me->add("jing", -30);
	me->add_temp("apply/attack", -lvl/8);	
	me->add_temp("apply/damage", -lvl/8);
        me->add_temp("apply/dexerity", -lvl);
        me->set_temp("yuxiao_lian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, lvl :), random(attack_time)+4);
        return 1;
}

void remove_effect(object me, object target)
{
        me->delete_temp("yuxiao_lian");
        if (me->is_fighting(target) )
        message_vision(HIC"$n慢慢看透了$N的攻势，不再受玉箫剑法的奇门剑路迷惑。\n"NOR,me,target);
}

