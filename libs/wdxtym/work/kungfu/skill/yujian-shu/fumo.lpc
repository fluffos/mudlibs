// mie.c  痴心长情剑「御剑伏魔」

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "御剑"ZJBR"伏魔"; }

int perform(object me, object target)
{
	int damage, damagea;
	string msg;
	object weapon;
	int ap, dp, cp;
      weapon = me->query_temp("weapon");
	
       if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	
	if (! target || ! me->is_fighting(target))
		return notify_fail("「御剑伏魔」只能对战斗中的对手使用。\n");

        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("非蜀山不能用「御剑伏魔」！\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("没装备剑怎么使用「御剑伏魔」？\n");

	if ((int)me->query_skill("yujian-shu", 1) < 100 )
		return notify_fail("你的蜀山御剑术不够娴熟，还使不出「御剑伏魔」。\n");
	
        if((int)me->query_skill("xianfeng-spells", 1) < 50)
                return notify_fail("你的仙风云体术等级不够，还使不出「御剑伏魔」。\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功火候不够，难以施展「御剑伏魔」。\n");

	if ((int)me->query("neili") < 200)
	       return notify_fail("你现在真气不够，难以施展「御剑伏魔」。"NOR"\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("你的精神不足难以施展「御剑伏魔」。"NOR"\n");


       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "$N口中默念御剑口诀，手中"+weapon->name()+NOR+HIC"顿时间霞光四射，一招「御剑伏魔」直斩$n！"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");
      cp = ap/2 + ap + dp; 
	if (random(cp) > dp)
	{
	  me->start_busy(2);
        damage =ap + random((int) me->query("max_neili"))/30;
        damagea =ap + random((int) me->query("max_neili"))/50;
        target->receive_damage("qi",damage);
        target->receive_damage("jing",damagea);
        me->receive_damage("jing", 100);
        me->receive_damage("qi", 100);
        me->add("neili", -500);
        me->add("mana", -50);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
					   HIR "$n" HIR "全然无法躲避，" + weapon->name() +
					   HIR "端端正正扎进在$n" HIR "胸口，登时鲜血飞溅！"NOR"\n");
		me->add("neili", -150);
	} else
	{
		me->start_busy(3);
		msg += YEL "可是$p" YEL "轻轻一笑，侧身右转，伸"
		       "出两指，正弹在$P" YEL "的剑上，" + weapon->name() +
		       YEL "在$p" YEL "身侧划过，有惊无险。"NOR"\n";
            me->add("neili", -100);
            me->add("mana", -50);

	}
	message_combatd(msg, me, target);
	return 1;
}
