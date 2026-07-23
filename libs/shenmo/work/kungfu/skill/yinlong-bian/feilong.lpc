#include <ansi.h>
#include <combat.h> 
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

void attack_1();
void attack_2();
void attack_3();
void finish();
void attack(int n);

int perform(object me, object target)
{
        string msg;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［飞龙］只能对战斗中的对手使用。\n");

        if( (me->query_skill("yinlong-bian",1) < 150 )
        ||      (me->query_skill("jiuyin-zhengong",1) < 150 ) ) 
                return  notify_fail("你的功夫还不够娴熟，不会使用飞龙。\n");

        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" ) 
                return  notify_fail("你现在无法使用飞龙。\n");

        if( me->query("neili") < 1500 )
                return notify_fail("你的内力不够。\n");

        me->start_perform(8,"飞龙");
        msg = HIG "$N使出九阴银龙鞭的「飞龙」，将一条鞭子使的滴水不漏。\n"NOR;

        me->add_temp("apply/dodge",300);
// busy 在各个 callout 连续增加
        me->start_busy(2);
        message_vision(msg, me, target);
        call_out("attack_1",3);
        me->add("neili", -1000);
        return 1;
}

void attack_1()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      attack(3);
      me->start_busy(2);
      call_out("attack_2",3); } else
      call_out("finish",1);
}

void attack_2()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      attack(4);
      me->start_busy(2);
      call_out("attack_3",3);} else
      call_out("finish",1);
}

void attack_3()
{
      object me = this_player();
      object target = offensive_target(me);
      if (me->is_fighting()) {
      attack(5);
      me->start_busy(1);
      call_out("finish",1);} else
      call_out("finish",1);
}

void finish()
{
      object me = this_player();
      message_vision(HIY"\n$N力气不济，鞭法缓了下来。\n"NOR, me);
      me->add_temp("apply/dodge",-300);
}

void attack(int n)
{
	object me = this_player();
	object target = offensive_target(me);
	int damage = me->query_skill("yinlong-bian", 1), p;
        object weapon = me->query_temp("weapon");
	string msg, dodge_skill;
        if( !weapon 
        ||      weapon->query("skill_type") != "whip"
        ||      me->query_skill_mapped("whip") != "yinlong-bian" )
		return;
	message_vision(HIY"\n$N突然抽空挥鞭向$n攻去！\n"NOR, me, target);
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
	 {
		message_vision(HIR"但见飞舞的"+weapon->name()+"从天而下和$n缠在一起，一股排山倒海的内劲无声息的向$n胸口撞去！\n"NOR, me, target);
		damage = damage * n + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", random(damage));
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg = damage_msg(damage, "拉伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
		message_vision(msg, me, target);
	} else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		message_vision(msg, me, target);
	}
}
else{	if (	random(me->query_skill("yinlong-bian", 1)) > target->query_skill("dodge", 1)/3	)
	
	 {
		message_vision(HIR"但见飞舞的"+weapon->name()+"从天而下和$n缠在一起，一股排山倒海的内劲无声息的向$n胸口撞去！\n"NOR, me, target);
		damage = damage * n + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", random(damage));
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg = damage_msg(damage, "拉伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
		message_vision(msg, me, target);
	} else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		message_vision(msg, me, target);
	}
}
}
