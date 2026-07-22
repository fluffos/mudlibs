//fogang.c 佛光普照
// by snowman@SJ

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, ap, dp, p;
	float at;
	string msg, dodge_skill;
 
	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target)
	 || !living(target))
		return notify_fail("「佛光普照」只能在战斗中使用。\n");

	if(objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「佛光普照」！\n");

	if( me->query_skill("linji-zhuang", 1) < 150 && !wizardp(me))
		return notify_fail("你的临济十二庄未成，不能使用「佛光普照」！\n");

	if((int)me->query("max_neili") < 2000 )
		return notify_fail("你的内力修为不足，不能使用「佛光普照」！\n"); 

	if((int)me->query("neili") < 1000 )
		return notify_fail("你现在内力不足，不能使用「佛光普照」！\n"); 

	if((int)me->query_skill("jieshou-jiushi", 1) < 150 )
		return notify_fail("你的截手九式不够娴熟，不能使用「佛光普照」。\n");

	if((int)me->query_str(1) < 25)
		return notify_fail("你的膂力不足，无法发挥「佛光普照」的气势。\n");

	if((int)me->query_con(1) < 25)
		return notify_fail("你的根骨欠佳，无法使用「佛光普照」。\n");

	if(me->query_skill_prepared("hand") != "jieshou-jiushi"
	|| me->query_skill_mapped("hand") != "jieshou-jiushi"
	|| me->query_skill_mapped("parry") != "jieshou-jiushi")
		return notify_fail("你必须全面运用截手九式，才能使用「佛光普照」。\n");

	if(me->query_skill_mapped("force") != "linji-zhuang" && !wizardp(me))
		return notify_fail("你不使用临济十二庄，怎么能使用「佛光普照」？\n");

	if(me->query_temp("huanying")) 
		return notify_fail("你正在使用无形幻影，不能再使用「佛光普照」。\n");

	if(me->query_temp("shuangdao_hebi")) 
		return notify_fail("你正在使用「双刀合璧」，无法使用「佛光普照」。\n");

	msg = MAG "\n只见$N面显庄严，突然间全身骨骼中发出劈劈拍拍的轻微爆裂之声，炒豆般的\n"+
		"响声未绝，一式「"HIY"佛光普照"MAG"」，提一口真气，飘身而上，半空中手掌交错，一\n"+
		"股内劲狭带着热浪，如风如火，似雷似电，这一招拍出，招式平平淡淡，一成\n"+
		"不变，击向$n，但却挡无可挡，避无可避！\n"NOR;

	ap = me->query("combat_exp")/ 1000 * me->query_skill("jieshou-jiushi",1) * me->query_str(1) / 200;;
	dp = target->query("combat_exp")/ 1000 * target->query_skill("force", 1) * target->query_con(1)/ 200;

	if ( target->is_busy())
		dp -= dp/3;

	if(random( ap + dp ) > dp) {
		target->add_busy(random(2));
		damage = me->query_skill("hand") + me->query_skill("force");
		damage += me->query("jiali") * 15;
             
		if(target->query("neili") < 10) at = 8;
		else at = me->query("neili") / (target->query("neili")+1);
		if(at < 1){
			if(at < 0.5) damage /= 2;
			else damage /= 1;
		}
		else if (at < 2 ) at = 2;

		else damage = to_int(damage*at);
		damage -= target->query_temp("apply/armor") * 2;
		if (damage < 0) damage = 0;
		damage = random(damage) + damage/2;
		if (target->query_skill_mapped("force") == "jiuyang-shengong"
		&& target->query_skill("jiuyang-shengong", 1) > 100){
			tell_object(me, HIY"\n哪知你一掌打在"+target->name(1)+"身上，却犹如江河入海，又如水乳交融，劲力登时无影无踪！\n"NOR);
			msg += "猛听得砰然一声大响，$N已打中在$n胸口，只道$p定然全身骨骼粉碎。哪知一掌过去，\n"+
				"$n脸露讶色，竟好端端的站着，$N却是脸如死灰，手掌微微发抖！\n";
			target->add_busy(2);
			message_vision(msg, me, target);
			me->add("neili", -500);
			me->add("jingli", -100);
			me->start_perform(2, "「佛光普照」");
			return 1;
		}
		if((target->query_skill_mapped("force") == "yijin-jing"
		|| target->query_skill_mapped("force") == "yinyun-ziqi")
		&& target->query_temp("fanzhen")) 
			damage /= 2;
		else
			damage *= 2;

              	if (damage > 5000) damage = 5000 + (damage-5000)/100;
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", random(damage), me);
		target->receive_damage("neili", damage/4);
		me->receive_damage("neili", 500);
		if(damage >= 4000)
			msg += HBCYN"这一招乃是使上了全力，丝毫不留余地，$n的生死存亡，便决于这顷刻之间！\n"NOR;
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += COMBAT_D->damage_msg(damage, "瘀伤");
		msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		message_vision(msg, me, target);
		me->start_perform(3, "「佛光普照」");
	}
        else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		msg += MAG"\n$N见一击不中，左手在空中划了一道弧线，右手顺手朝$n速攻了几招！\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me, target, 0, 1);
		COMBAT_D->do_attack(me, target, 0, random(2)?1:3);
		me->add("neili", -200);
		me->start_perform(2, "「佛光普照」");
	}
	me->add("jingli", -100);
	me->start_busy(random(2));
	return 1;
}

string perform_name(){ return MAG"佛光普照"NOR; }

int help(object me)
{
	write(MAG"\n截手九式之「佛光普照」："NOR"\n\n");
	write(@HELP
	要求：	当前内力 1000 以上；
		最大内力 2000 以上；
		截手九式等级 150 以上；
		临济十二庄等级 150 以上；
		后天膂力 25 以上；
		后天根骨 25 以上；
		激发手法为截手九式；
		激发招架为截手九式；
		空手且备截手九式。

HELP
        );
        return 1;
}
