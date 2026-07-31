// wugou.c 天下无狗

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "天下"ZJBR"无狗"; }
string *pfm_type() { return ({ "staff", }); }

int query_cd() { return 4; }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp, i, skill;

	

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}
	if (! target || ! me->is_fighting(target))
		return notify_fail("「天下无狗」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
		
	if (skill=(int)me->query_skill("dagou-bang", 1) < 150)
		return notify_fail("你的打狗棒法不够娴熟，不会使用「天下无狗」。\n");
				
	if ((int)me->query_skill("force") < 220)
		return notify_fail("你的内功修为不够高，难以运用「天下无狗」。\n");
			
	if ((int)me->query("neili") < 500)
		return notify_fail("你现在真气不够，不能使用「天下无狗」。\n");

	if (me->query_skill_mapped("staff") != "dagou-bang")
		return notify_fail("你没有激发打狗棒法，不能使用「天下无狗」。\n");

      if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

      message_vision(HIW"\n"HIW"$N"HIW"手中的" +weapon->name()+HIW "抖动，将一路“打狗棒法”使得变化万方，但见棒去如神龙夭矫，棒来又似灵蛇盘舞！\n",me);
      message_vision(HIG"这正是打狗棒法的绝招「天下无狗」,据说精妙绝伦，一招使出，劲力所至，四面八方全是棒影。\n",me);
      message_vision(HIG"此时纵是有几十条恶犬也可一并打死了，所谓“天下无狗”便是此意。"NOR"\n",me);

      me->add_temp("apply/damage", skill/1);
	write("你的攻击力瞬间提高了 "+skill/1+" 点。\n");

	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

      me->add_temp("apply/damage", skill/4);	
	me->add("neili", -500);
	me->start_busy(1+random(2));

/*
	switch (random(3))
	{
	case 0:
		msg = HIC "$N" HIC "手中的" + weapon->name() +
		      HIC "上挑下拨，点点戳戳，如暴风骤雨一般攻向$n" HIC "！"NOR"\n";
		break;

	case 1:
		msg = HIC "$N" HIC "哈哈大笑，手中" + weapon->name() +
		      HIC "带起阵阵风声，嘶嘶作响，$n"
		      HIC "只觉得眼前一花，四面八方都是" + weapon->name() + "！\n";
		break;

	default:
		msg = HIC "$N" HIC "手中" + weapon->name() +
		      HIC "疾刺而出，途中一化二、二化四、越变越多，层层叠叠将$n"
		      HIC "全然笼罩于内。"NOR"\n";
		break;
	}

	ap = me->query_skill("staff") + me->query("int") * 10;
	dp = target->query_skill("parry") + target->query("dex") * 10;
	if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("force") + ap;
		damage = damage / 2 + random(damage / 2);

		me->add("neili", -300);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
					   HIR "只见$p" HIR "手忙脚乱，招架不迭，接连中了$P"
					   HIR "数棍，疼痛难忍，连声大叫！"NOR"\n");
		me->start_busy(2);
	} else 
	{
		msg += HIC "可是$p" HIC "手明眼快，东挡西架，竟然挡住$P"
		       HIC "所有的来招！"NOR"\n";
		me->add("neili", -100);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
*/

	return 1;
}

