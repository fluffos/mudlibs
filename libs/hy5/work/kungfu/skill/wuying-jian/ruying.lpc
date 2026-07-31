// ruying 如影随形
// campsun
//2000.9.17

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;
int perform(object me, object target)
{
  object weapon;
string msg;
int damage,p;        
int extra;
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「如影随形」只能在战斗中对对手使用。\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「分身无影」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
                return notify_fail("「如影随形」必须用剑才能施展。\n");

        if( (int)me->query_skill("wuying-jian", 1) < 150 )
                return notify_fail("你的「少林无影剑」不够娴熟，不会使用「如影随形」。\n");

        if (me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("你的内功中无易筋经。\n");

	if( (int)me->query_skill("yijinjing", 1) < 100 )
		return notify_fail("你的易筋经不够娴熟。\n");

        if( (int)me->query_dex() < 27 )
                return notify_fail("你的身法不够强，不能使用「如影随形」。\n");
      

        if( (int)me->query("neili") < 1000 )
                return notify_fail("你现在内力太弱，不能使用「如影随形」。\n");

        msg = HIY "\n$N忽然跃起，左脚一勾一弹，霎时之间踢出一招「如」字诀的穿心腿，直袭$n前胸！\n" NOR;
	            damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+50;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/6);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                   
 msg += damage_msg(damage, "内伤");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);               
        msg = HIY "\n紧接着$N左腿勾回，将腰身一扭，那右腿的一招「影」字诀便紧随而至，飞向$n！\n" NOR;
me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+100;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/6);

        
     msg += damage_msg(damage, "内伤");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  
        
         if( (int)me->query_skill("yijinjing", 1) >150  ){

        msg = HIY "\n只见$N右脚劲力未消，便凌空一转，左腿顺势扫出一招「随」字诀，如影而至！\n" NOR;
me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+200;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/6);

        
     msg += damage_msg(damage, "内伤");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  

}
if( (int)me->query_skill("yijinjing", 1) >180  ){

        msg = HIY "\n半空中$N脚未后撤，已经运起「形」字诀，内劲直透脚尖，在$n胸腹处连点了数十下！\n" NOR;
me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+350;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/5);

        
     msg += damage_msg(damage, "内伤");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  

}

 if( random((int)me->query_skill("yijinjing", 1)) >180  ){

        msg = RED "\n这时$N双臂展动，带起一股强烈的旋风，双腿霎时齐并，「如影随形」一击重炮轰在$n胸堂之上！\n" NOR;
me->add("neili",-100);
        target->start_busy(1+random(2));

damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+450;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/4);

        
     msg += damage_msg(damage, "内伤");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  

 }
extra = me->query_skill("wuying-jian",1) / 10;
if ((int)me->query_skill("yijinjing",1) >250
&&(int)me->query_skill("wuying-jian",1) >250
&& me->query("neili") >500)
{
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "眼看招式要完，突然间$N又施展出［迷踪幻影连环脚］，身形极度旋转，一丛人影中突然向$n飞出一腿！" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR  "人影中又飞出一腿！" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR  "$N身形渐稳，反身又是一腿！" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
me->add("neili",-150);
}
msg =YEL "\n$N连环飞腿使完，全身一转，稳稳落在地上。\n";
message_vision(msg, me, target);                  
me->start_busy(3);
        return 1;



}
