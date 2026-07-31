// bai 花败

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "花败"ZJBR"几何"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
	int delta;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「花败几何」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");


	if (me->query_skill("sword", 1) < 200)
		return notify_fail("你的剑术修为不够，目前不能使用「花败几何」！\n");

	if (me->query_skill("feixian-sword", 1) < 125)
		return notify_fail("你的飞仙剑法的修为不够，不能使用这一绝技！\n");

	if (me->query_skill("dodge") < 200)
		return notify_fail("你的轻功修为不够，无法使用「花败几何」！\n");
 
	if (me->query("neili") < 350)
		return notify_fail("你的真气不够！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	if (me->query("gender") == "女性" &&
	    target->query("gender") != "无性")
		delta =  me->query("per") - target->query("per") / 2;
	else
		delta = 0;

	msg = HIR "$N" HIR "“你。。。听过花哭的声音吗。”手中的" + weapon->name() +
	      HIG "像是演练招式般的砍。劈。刺。不过每次挥剑都带着莫名的意味。"NOR"\n";
	if (delta > 0)
		msg += HIY "$n" HIY "只觉得$N" HIY "眼神中隐然透出"
		       "一股寒意，心中不禁一颤。"NOR"\n";
	else
		delta = 0;

	me->add("neili", -250);
	ap = (me->query_skill("feixian-sword") + me->query_skill("sword")) / 2;
	dp = target->query_skill("dodge");
	me->start_busy(5);
	if (ap * 2 + random(ap) > dp )
	{
		damage = ap * 4 + random(ap * 2) + delta * 50;
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
					   HIR "$n" HIR "你感觉一柄利剑从自己身体穿过，骇怖到了极点！\n" NOR);
		if (objectp(weapon = me->query_temp("weapon")) &&
		    ap / 2 + random(ap) > dp)
		{
			damage /= 2;
			msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
						   HIW "$n目光呆滞不知今夕何年。$P"
						   HIW "手中" + weapon->name() +
						   HIW "光芒大胜，嗡嗡作响\n" HIR "只见$p"
						   HIR "噗的一声，从胸直入。"NOR"\n");
		}
	} else
	{
		  msg += "$N已跳了开去，避开了$n这一击，星目连闪“好功夫。好功夫！”\n"NOR;
              
	}

	message_combatd(msg, me, target);

	return 1;
}
