// tianwai.c 天外清音

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;
int extra;
        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("yuxiao-jian",1);

        if( !(me->is_fighting() ))
            return notify_fail("「天外清音」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if( me->query_skill("bibo-shengong",1) < 120)
            return notify_fail("你的碧波神功等级不够, 不能使用「天外清音」！\n");

        if( skill < 90)
            return notify_fail("你的玉箫剑法等级不够, 不能使用「天外清音」！\n");

        if( me->query("neili") < 250 )
            return notify_fail("你的内力不够，无法运用「天外清音」！\n");

        msg = HIG 
"$N一声清啸，剑发琴音，深吸一口气，剑附内力，一式「天外清音」，"+weapon->name()
+"闪动不止，剑影如夜幕般扑向$n。\n";

	extra = me->query_skill("yuxiao-jian",1) / 5;
	extra += me->query_skill("bibo-shengong",1) /5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);

 	me->add("neili", -50);
	me->start_busy(1);
        return 1;
}
