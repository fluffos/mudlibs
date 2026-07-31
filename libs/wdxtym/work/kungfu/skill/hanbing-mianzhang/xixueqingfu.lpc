// xixueqingfu.c 吸血青蝠
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
string query_name() { return "青蝠"ZJBR"吸血"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me)
{
	string msg;
	object weapon, target;
	int damage;
	int skill;
	int ap, dp;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("hanbing-mianzhang", 1);

	if (! (me->is_fighting(target)))
		return notify_fail("「吸血青蝠」只能对战斗中的对手使用。\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");

	if (skill < 60)
		return notify_fail("你的「寒冰绵掌」等级不够, 不能使用「吸血青蝠」！\n");

	if (me->query_skill("dodge", 1) < 200)
		return notify_fail("你的轻功基础还没有打好，无法运用「吸血青蝠」！\n");

	if (me->query_skill_mapped("strike") != "hanbing-mianzhang")
		return notify_fail("你没有激发寒冰绵掌，无法运用「吸血青蝠」！\n");
 
       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "突然如同蝙蝠一样，倏的欺近$n"
	      HIR "的身前，张嘴便向$n" HIR "的咽喉咬去。"NOR"\n";
 
	ap = me->query_skill("dodge") + me->query_dex() * 10;
	dp = target->query_skill("dodge") + target->query_dex() * 10;
	if (ap / 4 + random(ap / 2) > dp)
	{
		me->add("neili", -300);
		damage = skill * 5 + random(skill);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 100,
					   HIG "$n" HIG "只觉喉头一痛，四肢渐渐乏"
					   HIG "力，鲜血在不断流失！\n"  NOR);
		me->start_busy(4);
	} else
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -200);
		damage = skill + random(skill);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 66,
					   HIG "$n" HIG "只觉得咽喉一阵剧痛，原来被$P" HIG
					   "要了个正中，只见$N" HIG "死死咬住狂吸$n" HIG "的鲜血！"NOR"\n");
		me->start_busy(3);
	} else
	{
		msg += CYN "只见$n" CYN "不慌不忙，轻轻一闪，躲过了$N"
		      CYN "的利齿！"NOR"\n";
		me->add("neili", -50);
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}

