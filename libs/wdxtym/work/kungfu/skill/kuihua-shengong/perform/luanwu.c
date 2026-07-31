// luanwu.c 剑魔乱舞

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return HIR"剑魔乱舞"NOR; }

int perform(object me, object target)
{
	string msg;
	object weapon;
	int i;
	int skill;
	int count;
	int isGhost;
	int num;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
		return notify_fail("「剑魔乱舞」只能对战斗中的对手使用。\n");

	skill = me->query_skill("kuihua-shengong", 1);
	if (userp(me)) {
		if (! me->query("can_perform/kuihua-shengong/luanwu"))
			return notify_fail("你还没有通晓剑魔乱舞的奥秘。\n");
		
		if (skill < 200)
			return notify_fail("你的葵花神功修为有限，现在不能使用「剑魔乱舞」！\n");
		
		if (me->query_skill_mapped("sword") != "kuihua-shengong")
			return notify_fail("你没有激发葵花神功为剑法，难以施展「剑魔乱舞」。\n");
		
		if (!me->query("special_skill/ghost"))
			return notify_fail("你没有鬼脉属性，无法运用「剑魔乱舞」。\n");
	}
	if (me->query("neili") < 100)
		return notify_fail("你的真气不够，无法运用「剑魔乱舞」！\n");

	weapon = me->query_temp("weapon");

	if (weapon &&
	    weapon->query("skill_type") != "pin")
		return notify_fail("你必须使用“针”这种兵器施展「剑魔乱舞」！\n");

    if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	if (weapon)
	{
		msg = HIR "$N" HIR "身形忽然变快，蓦的冲向$n"
		      HIR "，手中的" + weapon->name() + HIR "指指点点，如同"
		      HIR "寒夜晨星一般，点点光芒刺向$p" HIR "。"NOR"\n";
	} else
	{
		msg = HIR "$N" HIR "忽然冲向$n" HIR "，身法快得"
		      HIR "不可思议，几近鬼魅，伸手就是数掌拍向$n" HIR "！"NOR"\n";
	}

	message_combatd(msg, me, target);
	count = skill / 8;
	isGhost = me->query("special_skill/ghost");
	num = 7+random(4);
	if (num > 20)
		num = 20;
	
	if (isGhost && random(2))
		count *= 4;

	me->add_temp("apply/attack", count);

	for (i = 0; i < num; i++)
	{
		if (! me->is_fighting(target))
			break;
		if ((random(3) == 0 || (isGhost && random(2))) && ! target->is_busy())
			target->start_busy(1);
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	me->start_busy(3 +random(num -3));
	me->add_temp("apply/attack", -count);

	return 1;
}

