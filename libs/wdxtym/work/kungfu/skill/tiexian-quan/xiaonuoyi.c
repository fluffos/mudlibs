#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

string name() { return HIW "小挪移" NOR; }
string query_name() { return "小"ZJBR"挪移"; }
inherit F_SSERVER;

int perform(object me, object target)
{
	int damage,ap,dp;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(HIW "「小挪移」只能对战斗中的对手使用。\n"NOR);
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	if( me->query_temp("weapon"))
		return notify_fail("你先放下手中的武器再说吧？！\n");
	if( (int)me->query_skill("tiexian-quan",1) < 300)
		return notify_fail(HIW "你的「铁线拳」还不到家，无法使用「小挪移」！\n"NOR);
	if( (int)me->query_skill("guiyuan-dafa",1) < 300 )
		return notify_fail(HIW "你的「归元大法」还不到家，无法使用「小挪移」！\n"NOR);
	if( me->query_skill_mapped("force")!="guiyuan-dafa")
		return notify_fail(HIW "你未使用「归元大法」，无法使用「小挪移」！\n"NOR);	
	if (me->query_skill_mapped("unarmed") != "tiexian-quan")
		return notify_fail("你没正确激发该技能 。\n");
	if (me->query("max_neili")<=10000) 
		return notify_fail(HIW "你的内力太差了足，恐怕挪移不动对方！\n"NOR);

	if (me->query("neili")<=1000) 
		return notify_fail(HIW "你的内力不足，无法带动敌人攻势！\n"NOR);

	me->add("neili",-500);
	message_vision(HIR "\n$N使出浣花剑派的不传之秘「小挪移」\n\n"NOR,me);
	ap = me->query("xyzx_sys/level") + me->query_skill("tiexian-quan", 1) + me->query_skill("unarmed") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");	
	damage = me->query_skill("tiexian-quan",1);
	damage = damage*2 + random(damage*2);
	if (random(ap)>dp/3)
	{
		message_vision(HIY "$N伸手带动$n的攻势，使之攻向"+target->name()+"！\n" NOR,me,target);
		COMBAT_D->do_attack(target,target, target->query_temp("weapon"));
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage +"。\n" NOR);
	//	if (!target->is_busy()) target->start_busy(3);
	}
	else
	{
		message_vision(HIR "但$n看破$N的意图，趁势发动攻击！\n"NOR,me,target);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
	}
	 me->start_busy(3);
	return 1;
}
