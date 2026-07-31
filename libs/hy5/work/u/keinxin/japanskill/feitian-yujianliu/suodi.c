// suodi.c 飞天御剑流.缩地

#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("飞天御剑流.缩地只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("你使用的武器不对。\n");

    if ((int)me->query_skill("shayi-xinfa", 1) < 50)
   return notify_fail("你的杀意心法火候不够。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前已经手忙脚乱了，放胆攻击吧ⅵ\n");
                
	if((int)me->query_skill("feitian-yujianliu",1) < 30)
		return notify_fail("你的飞天御剑流的修为不够, 不能使用这一绝技 !\n");
	if((int)me->query_skill("blade") < 30)
		return notify_fail("你的刀法修为不够， 目前不能使用! \n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("你的内力不够。\n");

        msg = HIG "$N企图扰乱$n，身法突然加快，以超高速切入$n攻击范围,如同将距离缩短一般。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIW " 结果$p被$P切入自己的攻击范围，结果大吃一惊！\n" NOR;
                target->start_busy( (int)me->query_skill("feitian-yujianliu",1) / 50 + 2 );
        } else {
                msg += HIC"可是$p看破了$P的企图，全力后退，逃开了缩地的攻击范围。\n"NOR NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
	me->add("neili", - 60);
        if(!target->is_fighting(me)) target->fight_ob(me);
if ((int)me->query_skill("feitian-yujianliu",1) > 200)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
         {
         attack_time = random((int)me->query_skill("feitian-yujianliu", 1) / 30);
        msg = HIY "「 龙鸣闪! 」$N使出神速的收刀术,由急速的收刀而发出超声波,扰乱了$n的平衡能力。\n";
        target->start_busy(1);
        message_combatd(msg, me, target);
  
        for(i = 0; i < attack_time; i++){
         msg = HIM "$N趁胜追击! 犹如在无尽的樱花中，伸出了一技花技！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                                        }
         }
                me->start_busy(3);
}
        return 1;
}

