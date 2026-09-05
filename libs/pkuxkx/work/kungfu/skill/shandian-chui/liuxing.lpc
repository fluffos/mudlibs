#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
    mapping attack_val = ([
        "base" : ([ "weapon" : "hammer", ]),//基本功夫类型
        "skill" : ([ "weapon" : "shandian-chui", ]),//高级技能名称
        ]);

    if( !target ) target = offensive_target(me);

    if( !objectp(target) ||	!target->is_character() || !me->is_fighting(target) )
        return notify_fail("［反转流星］只能对战斗中的对手使用。\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "hammer" )
        return notify_fail("你必须装备锤类兵器时才能使出［反转流星］！\n");

    extra = me->query_skill("shandian-chui",1);
    if ( extra < 100) 
		return notify_fail("你的日月闪电锤还不够纯熟！\n");

	if (me->query("neili")<100)
		return notify_fail("你的内力不够！\n");

	//增加临时攻击力和damage
	me->add_temp("apply/attack", extra/3);
	me->add_temp("apply/damage", extra/5);  
	me->add("neili",-100);

    if ( objectp(me->query_temp("weapon")) )
	{
        msg = HIY  "$N使出日月闪电锤中的［反转流星］，假意抽身急退，蓦地反身抖手一锤！" NOR;
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    }

    if ( objectp(me->query_temp("weapon")) )
    {
        msg = HIY  "$N紧跟一招，另一锤反身又是一锤！！" NOR;
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    }

    if ( objectp(me->query_temp("weapon")) )
    {
        msg = HIY  "$N竟然还不回头，两臂一振，再来一锤！" NOR;
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    }

    if (me->query("riyuepfm/chui")&&me->query("family/family_name")=="日月神教")
    {
        if ( objectp(me->query_temp("weapon")) )
        {
            msg = HIY  "$N手中锤一起一落，又是一记！" NOR;
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }

        if (me->query("level")&&random((int)me->query("level"))&&!random(8))
        {
            if ( objectp(me->query_temp("weapon")) )
            {
                msg = HIY  "$N手中锤合而为一，只取对手中路而去！" NOR;
                me->set_temp("attack_val", attack_val);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
            }
        }
        me->add("neili",-100);
    }
	me->add_temp("apply/attack", -extra/3);
	me->add_temp("apply/damage", -extra/5);   
	me->start_busy(random(4));
	return 1;
}
