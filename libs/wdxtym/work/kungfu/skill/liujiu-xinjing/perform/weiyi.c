// yi.c 剑意

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "唯一"ZJBR"一剑"; }

int perform(object me, object target)
{
	object weapon;
	string msg,wn;
	int ap, dp;
	int damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("你只能对战斗中的对手使用绝招。\n");


	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你手中没有装备剑类武器\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你现在的真气不够，无法使用唯一一剑！\n");

	if ((int)me->query_skill("liujiu-xinjing", 1) < 120)
		return notify_fail("你的六九心经还不到家，无法使用唯一一剑！\n");

	if (me->query_skill_mapped("sword") != "liujiu-xinjing")
		return notify_fail("你没有激发六九心经，无法使用唯一一剑！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

		wn = weapon->name();
                           
        msg = HIW "\n$N" HIW "将" + wn + HIW "横在胸前，"
              + wn + HIW "散发出微微金芒，" + wn + HIW
              "忽然一道剑气射向$n" HIW "心脏。这正是六九心经的「" HIG "唯一一剑" HIW "」，"
              "不愧是传说中的神功，当真恐怖如斯。" NOR;

	ap = me->query("bodyreset") + me->query_skill("liujiu-xinjing", 1) + me->query_skill("martial-cognize", 1) + me->query_skill("force") + me->query_skill("sword")+me->query_skill("unarmed");
	dp = target->query("bodyreset") + target->query_skill("dodge") + target->query_skill("parry");	
	if (ap / 2 + random(ap) < dp)
	{
		damage = me->query_skill("liujiu-xinjing",1)*5+me->query_skill("sword-cognize",1)*5+me->query_skill("martial-cognize",1)*5+me->query_skill("sword",1)+me->query_skill("dodge")+me->query_skill("force");	
		damage=damage+random(damage);
		me->add("neili", -180);
		msg += COMBAT_D->do_damage(me,target, WEAPON_ATTACK, damage, 200,
		   HIR "$n" HIR "没有一丝反应的机会"  HIW "一个瞬间，身受重创！"NOR"\n");
		me->start_busy(2);
	} 
	
	else
	{	damage = me->query_skill("liujiu-xinjing",1)*me->query("int",1)*10 + me->query_skill("sword-cognize",1)*me->query("int",1) + me->query_skill("parry",1)*me->query("dex",1) + me->query_skill("martial-cognize",1)*me->query("dex",1) + me->query_skill("sword") + me->query_skill("dodge") + me->query_skill("force") + me->query_dex();
		damage=damage+random(damage);
		msg += COMBAT_D->do_damage(me,target, WEAPON_ATTACK, damage, 200,
		 CYN "只见$n" CYN "陷入这虚假意境之中"
		       CYN "在没有挣扎的余地！！！！\n");
		me->add("neili", -80);
		me->start_busy(3);
	} 
	message_combatd(msg, me, target);

	return 1;
}
