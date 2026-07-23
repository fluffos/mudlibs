
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
 int extra;
        if( !target ) target = offensive_target(me);
 
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「"HIW"雪花六出"NOR"」只能在战斗中使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail(" 你使用的武器不对\n");

        if( (int)me->query("neili") < 450 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("bingxue-xinfa",1) < 50 )
                return notify_fail("你的冰雪心法修为还不够！\n");

        if( (int)me->query_skill("sword",1) < 50 ||
            me->query_skill_mapped("sword") != "xueshan-sword" || 
            me->query_skill("xueshan-sword",1) < 50)
                return notify_fail("你的雪山剑法修为不够，无法使用「雪花六出」！\n");

        msg = HIY "$N一抖手中长剑，一式"HIW"「雪花六出」"NOR+HIY"，连续刺出六剑，剑剑快如流星，\n幻成雪花六点，带起一阵寒飚向前疾飘而去。\n" NOR;
        message_combatd(msg, me);

	extra = me->query_skill("xueshan-sword",1) / 3;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        me->clean_up_enemy();
        ob = me->select_opponent();

weapon=me->query_temp("weapon");
         msg = HIW "天雪九点！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "老枝横斜！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "暗香疏影！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "岭上双梅！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "梅雪争春！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIW "暗影浮香！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add("neili", -300);
        me->start_busy(2);

        me->add_temp("apply/damage", -extra);
        me->add_temp("apply/attack", -extra);
        return 1;
}

