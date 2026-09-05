// chousui.c 抽髓三掌
#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string weapon;
    int skill, p_skill, enfor, amount, sp, dp, dmg, pflv, tpflv;
    int t_neili, t_max_neili, i;
    int m_force, t_force, point;
	object *enemy;
    mapping attack_val = ([
        "base" : ([ "no_weapon" : "strike", ]),//基本功夫类型
        "skill" : ([ "no_weapon" : "xingxiu-duzhang", ]),//高级技能名称
        ]);

    enfor = me->query("jiali");

    if (!target)
        target = offensive_target(me);

    if (!objectp(target) || !target->is_character() || !me->is_fighting(target))
        return notify_fail("「抽髓三掌」只能对战斗中的对手使用。\n");

//    if (me->query_skill("xingxiu-duzhang", 1) < 150 || me->query_skill_mapped("strike") != "xingxiu-duzhang")
    if ( me->query_skill("xingxiu-duzhang", 1) < 150 )
        return notify_fail("你的星宿毒掌修为还不够，不能施展「抽髓三掌」！\n");

    if (me->query_skill("huagong-dafa", 1) < 150)
        return notify_fail("你的化功大法修为火候未到，不能施展「抽髓三掌」！\n");

/*    if (objectp(me->query_temp("weapon")) && objectp(me->query_temp("secondary_weapon")))
        return notify_fail("星宿毒掌只能空手运用。\n"); */

    if (me->query_str() < 35)
        return notify_fail("你的臂力不足以施展！\n");

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
         me->query_skill_mapped("force") != "huagong-dafa")
        return notify_fail("你没有用化功大法用不出这么狠毒的招式！\n");

    if (me->query("max_neili", 1) < 2500)
        return notify_fail("你的内力修为不够，无法施展抽髓三掌！\n");

    if (me->query("neili", 1) < 1000)
        return notify_fail("你内力不足以施展抽髓三掌！\n");
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "星宿派") 
		pflv=0;

	tpflv = (int)target->query("purefamily/level");
	if (tpflv>0 && target->query("purefamily/family_name") != "星宿派") 
		tpflv=0;

	enemy = me->query_enemy();

    message_vision(HIR "$N眼光一闪，暗运化功大法，掌心凹陷向$n拍去，悄无声息的逼向$p！\n\n" NOR, me, target);

    sp = me->query_skill("force", "huagong-dafa") + me->query_skill("strike", "xingxiu-duzhang") + me->query_con();
    dp = target->query_skill("force") + target->query_skill("parry") + target->query_con();
    skill = me->query_skill("force", "huagong-dafa") + me->query_skill("strike", "xingxiu-duzhang");
    p_skill = me->query_skill("poison", 1);
    m_force = me->query_skill("force", 1);
	if (pflv>=4)
		m_force += m_force*(pflv-3)/10;
    t_force = target->query_skill("force", 1);
	if (tpflv>=4)
		t_force += t_force*(tpflv-3)/10;

    amount = skill / 3;
    amount += p_skill;

    me->add_temp("apply/attack", amount * 2 / 3);
    me->add_temp("apply/damage", amount / 2);
    me->add_temp("apply/strike", amount / 4);
    if (!me->query("newbiehongdou") && !me->query("newbiediaoyu"))
    {
		if (target->query_skill_mapped("force") == "huagong-dafa")
		{
			point = (int)me->query_skill("force", "huagong-dafa");
			if ((m_force + me->query_skill("poison", 1)) * 16 / 10 > (t_force + target->query_skill("poison", 1)))
			{
				message_vision(HIR "$N急忙也凝聚起化功大法，两道内力一撞，$P噔噔噔退了几步，好一阵气血翻涌！\n\n" NOR, target);
				if (random(me->query_skill("poison", 1)) > random(target->query_skill("poison", 1)))
					point *= 10;
				else
					point *= 5;
				if (pflv>=4)
					point += point*(3*pflv-10)/10;
				if (target->query("neili") < point)
					target->set("neili", 0);
				else
					target->add("neili", - point);
			}
			else
			{
				message_vision(HIR "$N叫了一声“来得好”，也凝聚起化功大法，两道内力一撞，身体晃了一晃！\n\n" NOR, target);
				if (random(me->query_skill("poison", 1)) > random(target->query_skill("poison", 1)))
					point *= 3;
				if (pflv>=4)
					point += point*(3*pflv-10)/10;
				if (target->query("neili") < point)
					target->set("neili", 0);
				else
					target->add("neili", - point);
			}
		}
		else
		{
			if (m_force * 16 / 10 > t_force)
			{
				message_vision(
					HIR "$N感到次招用意不在伤人，忙凝聚全身功力，却阻挡不住内力飞泄而出！\n\n" NOR,
					target);
				point = 15 * (int)me->query_skill("force", "huagong-dafa");
				if (pflv>=4)
					point += point*(3*pflv-10)/10;
				if (target->query("neili") < point)
					target->set("neili", 0);
				else
					target->add("neili", -point);
			}
			else
			{
				message_vision(
					HIC "$n感到次招用意不在伤人，忙凝聚全身功力，好在$p内功深厚，止住了内力流失，但仍被$N弄的狼狈不堪！\n\n" NOR,
					me, target);
				point = 5 * (int)me->query_skill("force", "huagong-dafa");
				if (pflv>=4)
					point += point*(3*pflv-10)/10;
				if (target->query("neili") < point)
					target->set("neili", 0);
				else
					target->add("neili", -point);
			}
        }
	}
    message_vision(HIR "$N顺势聚起全身功力，掌心凸出向$n狠命拍去，一股排山倒海的力量打向$p！\n" NOR, me, target);
	if (!userp(me)) me->set("jiali", (int)me->query_skill("force", "huagong-dafa") / 2);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, 0, TYPE_SPECIAL);
    message_vision(HIR "\n$N第二招既出，力贯双臂，双掌交错攻向$n，第三招连环而至！\n" NOR, me, target);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, 0, TYPE_SPECIAL);

	if ((int)me->query("neili")<=(amount/2))
		me->set("neili", 0);
	else
		me->add("neili", -amount / 2);

    me->set("jiali", enfor);
    me->add_temp("apply/attack", -amount * 2 / 3);
    me->add_temp("apply/damage", -amount / 2);
    me->add_temp("apply/strike", -amount / 4);

	if ( sizeof(enemy)>1 
		&& !me->query_temp("chousui_doublehit") 
		&& ((pflv==4 && !random(3)) || pflv>=5) // 嫡传弟子33%概率，真传弟子100% 
		&& me->query("neili")>1500 )
	{
		for (i=0;i<sizeof(enemy);i++)
		{
			if (enemy[i] == target)
			{				
				enemy -= ({enemy[i]});
				break;
			}
		}
		target = enemy[random(sizeof(enemy))];
		me->set_temp("chousui_doublehit", 1);
		message_vision(HIG"\n$N大喝一声，顺势对$n发动了攻击！\n\n", me, target);
		perform(me, target);
		me->delete_temp("chousui_doublehit");
	}
	if (!me->query_temp("chousui_doublehit"))
		me->start_busy(2);

    return 1;
}
