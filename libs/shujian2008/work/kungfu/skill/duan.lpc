#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
	string msg; 
	int lvl, j;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("「断」字诀只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if( me->query("neili") < 1500 || me->query("max_neili") < 2000 )
		return notify_fail("你的真气不够！\n");

	if( me->query_skill("wuhu-duanmendao") < 150 )
		return notify_fail("你的「五虎断门刀」还不到家，无法使用「断」字诀！\n");

	if( me->query_skill_mapped("blade") != "wuhu-duanmendao" )
		return notify_fail("你必须使用「五虎断门刀」，才能使用「断」字诀！\n");

	msg = HIY"\n$N猛然伏地，使出地堂刀「"HIR"断"HIY"」字决，顿时一片白光直向$n滚去！\n"NOR;
	message_vision(msg, me, target);

	lvl = me->query_skill("wuhu-duanmendao", 1);
	j = lvl/3;

	if( lvl > 200 )
		j = to_int( lvl/3.0 * lvl/200.0);


	if( wizardp(me) ) {
		tell_object(me,HIW"五虎断门刀的有效等级为: "+j+" \n"NOR);
	}

	me->add_temp("apply/blade", j);
	me->add_temp("apply/attack", j);
	me->add_temp("apply/damage", j/2);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	if ( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);

	if ( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	me->add_temp("apply/blade", -j);
	me->add_temp("apply/attack", -j);
	me->add_temp("apply/damage", -j/2);

	me->add("neili", -300);
	me->add("jingli", -100);
	me->start_perform(2, "断字诀");
	me->start_busy(random(2));
	return 1;
}

string perform_name(){ return HIY"断字诀"NOR; }

int help(object me)
{
	write(HIY"\n五虎断门刀之「断字诀」："NOR"\n\n");
	write(@HELP
	要求：	当前内力 1500 以上；
		最大内力 2000 以上；
		五虎断门刀等级 150 以上；
		激发招架为五虎断门刀；
		手持兵器。

HELP
        );
        return 1;
}
