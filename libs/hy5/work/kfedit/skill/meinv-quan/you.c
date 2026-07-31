// you.c 美女拳-古墓幽居

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
	object weapon;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("古墓幽居只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须先放下手中的兵器！\n");

        if( (int)me->query_skill("meinv-quan", 1) < 50 )
                return notify_fail("你的美女拳级别不够，不会使用古墓幽居。\n");

        if( (int)me->query_skill("yunv-xinfa", 1) < 40 )
                return notify_fail("你的玉女心法还未娴熟，不能利用神功伤敌。\n");

        if( (int)me->query("neili", 1) < 150 )
                return notify_fail("你现在内力太弱，不能使用古墓幽居。\n");

        msg = RED "$N右手支颐，左袖轻轻挥出，长叹一声，使出「古墓幽居」，脸现寂寥之意。"NOR;

         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -100);
	
       me->start_busy(2);
        return 1;
}
