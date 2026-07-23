//suxing.c 玉女素心
//by sdong

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string weapon;
string msg;
        int bili,original,dodge,skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("玉女素心只能对战斗中的对手使用。\n");


        if( me->query_skill("yunv-xinfa", 1) < 60 )
                return notify_fail("你的玉女心经火候未到，无法施展玉女素心！\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");


        if( me->query_skill("sword") < 135 )
                return notify_fail("你的玉女剑法修为不足，还不会使用玉女素心！\n");

        if( me->query("neili") <= 400 )
                return notify_fail("你的内力不够使用玉女素心！\n");
        if( me->query("jing") <= 100 )
                return notify_fail("你的精力不够使用玉女素心！\n");

        if( (int)me->query_temp("suxin") ) 
                return notify_fail("你已经发动了玉女素心！\n");


        if(!me)
                return notify_fail("现在没人！\n");
        if(!target)
                return notify_fail("现在没人！\n");

//        message_vision(HIR "$N清啸一声，运起玉女素心内诀，将内力源源不断地注入"+(me->query_temp("weapon"))->query("name")+ HIR "，身法也突然加快！\n\n" NOR, me);
        message_vision(HIW"$N信手一剑，极尽潇洒脱逸之妙，手中"+(me->query_temp("weapon"))->query("name")+ HIR "幻化出无数虹芒，向$n电掣攻去。\n"NOR,me,target);
        skill = (int)me->query_skill("yunv-jian", 1);
        original = me->query_skill("yunv-xinfa")/2;
        bili = me->query_str();
        dodge = me->query_dex();

        me->add_temp("apply/strength", bili/2);
        me->add_temp("apply/dexerity", dodge/2);
        me->add_temp("apply/damage", 150);

	msg = HIR "$N满场游走，一招未毕，二招至。剑招初出时人尚在左，剑招抵敌时身已转右，竟似剑是剑，人是人，两都殊不相干！\n"NOR;
	message_vision(msg, me, target);
     msg = HIY  "$N剑走轻灵，招断意连，绵绵不绝，当真是优雅潇洒，翰逸神飞，大有晋人乌衣子弟裙屐风流之态！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIY  "$N只微一凝持，突然放剑，双掌直欺，猛击$n前胸，同时剑柄反弹上来，双掌一剑，三路齐至！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      if (!target->is_busy())
      target->start_busy(1); 
       msg = HIY  "$N双足连错，幌身闪到$n背后，$w"HIY"斜指，剑尖分花，竟向$n连刺三剑！" NOR;
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

//        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
//        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
//        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add_temp("apply/damage", -150);
        me->add_temp("apply/armor", original);
        me->add_temp("apply/damage", original);
        me->start_busy(1+random(2));
        me->add("neili", -150);
        me->add("jing", -50);
        me->set_temp("suxin", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, bili,original,dodge :), skill/5);
//      me->start_busy(3);


        return 1;
}


void remove_effect(object me, int bili, int amount,int dodge,int original)
{
        original = me->query_skill("yunv-xinfa")/2;
        me->add_temp("apply/strength", - bili/2);
        me->add_temp("apply/dexerity",-dodge/2);
        me->add_temp("apply/armor", -original);
        me->add_temp("apply/damage", -original);
        me->delete_temp("suxin");

        tell_object(me, "你缓缓吸了一口气，收回玉女素心，内力又回到丹田。\n");
}
