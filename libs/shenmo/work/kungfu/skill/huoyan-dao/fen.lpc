// fen.c 焚心以火
// by secret
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target, *inv;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;

	me->clean_up_enemy();
       if( !target ) target = offensive_target(me);

       if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("「焚心以火」只能对战斗中的对手使用。\n");
        skill = me->query_skill("huoyan-dao",1);

 
//	if (objectp(weapon = me->query_temp("weapon")))
//              return notify_fail("你必须空手运功。\n");

	if( skill < 120)
                return notify_fail("你的「火焰刀」等级不够, 不能使出「焚心以火」！\n");

	if( me->query_skill("xiaowuxiang",1) < 60)
                return notify_fail("你的「小无相」等级不够, 不能使出「焚心以火」！\n");

	if( me->query("neili") < 600 )
                return notify_fail("你的内力不够，无法运功！\n");
 
        msg = HIC "$N聚气于掌，使出一招「焚心以火」，向$n的胸口击去。\n"NOR;

	ap = me->query("combat_exp") + skill * 800;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 )
		dp = 1;
	if( (random(ap)+ skill*800) > dp )
	{
		if(userp(me))
			me->add("neili",-500);


		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		
                qi_wound = target->query("qi") - 100;
if (qi_wound <10) qi_wound=10;
if (neili_wound <10) neili_wound=10;
		target->receive_damage("qi", qi_wound/2);
		target->receive_wound("qi", qi_wound/2);
		target->add("neili", -neili_wound/2);
		if(userp(me)) me->add("neili",-300);
		me->start_busy(2);

		inv = all_inventory(target);
msg += HIR "$n只觉得眼前一黑，一阵热焰扑面而来，“哇”的一声喷出一口鲜血！\n"NOR;
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
msg += HIR "$n闻到一股焦味，发现身上的"+inv[equip]->query("name")+HIR"已被烧得残破不堪，掉在了地上！\n"NOR;
			inv[equip]->unequip();
			inv[equip]->reset_action();
			inv[equip]->move(environment(target));
			inv[equip]->set("name", inv[equip]->query("name") + "的碎片");
			inv[equip]->set("value", 0);
			inv[equip]->set("armor_prop", 0);
			inv[equip]->set("long", "一堆破碎物事，好象是布片铁片什么的。\n");
			}
		}
	}
	else
	{
msg += HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
		if(userp(me)) me->add("neili",-300);
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) me->fight_ob(target);

	return 1;
}
