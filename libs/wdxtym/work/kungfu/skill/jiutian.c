// jiutian.c 九天式

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "九天式"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}
	if (! target || ! me->is_fighting(target))
		return notify_fail("「九天式」只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("liuyang-zhang", 1) < 120)
		return notify_fail("你的六阳掌法不够娴熟，不会使用「九天式」。\n");
				
	if ((int)me->query_skill("force") < 250)
		return notify_fail("你的内功修为不够高，难以运用「九天式」。\n");
			
	if ((int)me->query("neili") < 300)
		return notify_fail("你现在真气不够，不能使用「九天式」。\n");
	
	if (me->query_skill_prepared("strike") != "liuyang-zhang")
		return notify_fail("你没有准备使用六阳掌，无法施展「九天式」。\n");
			
	if (me->query_skill_mapped("strike") != "liuyang-zhang")
		return notify_fail("你没有激发天山六阳掌，不能使用「九天式」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");



	ap = me->query_skill("force");
	dp = target->query_skill("force");
	
	if (me->query_skill("tianchang-dijiu", 1) > 49)
	{
		damage = ap;
		damage += random(damage / 2);
        msg = HIY "但见$N" HIY "衣袂飘飘，闭目凝神默运玄功，手中生死符由内劲雾化蒸腾，"
              HIY "如云霞般随着双掌的翻飞缭绕周身，忽然$N" HIY "倾步前移，双掌破空击出，挟着丝丝寒意，直向$n" HIY "双肩贯去。\n" NOR;
        msg += HIR "$n" HIR "只觉胸口一闷，一丝凉意直入肺腑，脑中一片空白茫然不知所措！\n" NOR;
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
                                           HIR "$n" HIR "恍然惊醒，心下大骇，慌乱中抬手相抗，怎料得$N" HIR "那凝脂如雪的双掌竟然蕴含千钧力道，" HIR "一触之下顿让自己双臂气劲溃散，毫无抵挡之力，结结实实地受下此招。\n" NOR);
	} else
	{
                msg += CYN "$n" CYN "眼见$N" CYN "来势汹涌，情急之下力贯双臂，奋起抵抗，居然未占下风。\n" NOR;
	}

	// 第二招
        msg+= HIY "$N" HIY "一招未老，瞬即抽身回翔，接着反手推出一掌，看似漫无目的，那汇聚着白虹掌力的内劲确如浪涌一般奔至$n"HIY"胸前。\n" NOR;
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
                                           HIR "那掌劲不疾不徐，却又避无可避，从$n" HIR "胸口透体而过,直震得$n筋骨寸裂。"HIR "$n" HIR "只觉心脉如千道银针扎入，气海一阵翻涌，一团血雾从口中喷激而出。\n" NOR);
	} else
	{
                msg += CYN "只见$n" CYN "早有准备，猛一提气，内力从丹田源源不断灌入胸腔护住心脉，硬吃下这掌，倒也无甚大碍。\n" NOR;
	}

	// 第三招
        msg+= HIY "$N" HIY "纵身一跃，蓦然腾空数丈，悠悠飘摇而下，重重掌影层叠成一朵巨大的雪莲，朝$n" HIY "头顶压下。\n" NOR;
	if (ap / 2 + random(ap) > dp)
	{
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
                                           HIR "只听的一声闷响，一道雄浑的掌劲已在$n" HIR "天灵炸开，顺势泄入$n" HIR "周身，" HIR "$n" HIR "颅内一阵裂痛，全身经脉如浸寒冰，一下子瘫倒在地，动弹不得。\n" NOR);
	} else
	{
                msg += CYN "$n" CYN "见此招来势汹涌，岂敢贸然招架。俯腰移步，一个灵动，居然在千钧一发之际抽身而出。\n" NOR;
	}

	me->start_busy(2 + random(3));
	me->add("neili", -400 - random(100));
	message_combatd(msg, me, target);
	}
else
{
	msg = HIC "$N" HIC "双掌一振，化出满天掌影，团团笼罩住$n" HIC "！"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("strike") + ap - dp;
		damage += random(damage / 2);
        damage *= (me->query_skill("tiandi-xiaoyao", 1)+200)/200;

		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90 ,
					   HIR "$p" HIR "无奈，只能硬挡一招，结果被$P"
					   HIR "震得连退数步，吐血不止！"NOR"\n");
	me->add("neili", -200);
		me->start_busy(3);
	} else
	{
		msg += HIC "可是$p" HIC "强运内力，硬生生的挡住$P"
		       HIC "这一掌，没有受到任何伤害！"NOR"\n";
	me->add("neili", -80);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}

	return 1;
}
