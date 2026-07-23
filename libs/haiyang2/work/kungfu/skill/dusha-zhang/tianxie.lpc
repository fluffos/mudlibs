#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,damage;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
        extra = me->query_skill("dusha-zhang", 1);
        if ( extra < 180) return notify_fail("你的这门武功还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("［天邪六式］只能对战斗中的对手使用。\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");


        msg = HIB  "$N身法忽然加快，将天邪神掌的六式对着$n从头到底打了一遍！\n\n" NOR;
	message_vision(msg,me,target);

        damage=random(extra)+50;
        extra=extra/2;
        if (extra> 200) extra=200;

	message_vision("$N脚踩怪异方位，在$n眼前幻出万道身影！\n",me,target);
	        if( random(target->query("combat_exp")) < (int)me->query("combat_exp") / 2 ) {
                target->start_busy(3);
        message_vision("结果$N被扰得眼花潦乱，不知所措！\n", target, me);
        }

        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage",-extra*10);
        msg = GRN  "戴月披星！\n"NOR + HIG"$N左掌虚幌，右掌穿出击向$n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "翻云覆雨！\n"NOR + HIY"$N左掌化虚为实击向$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "颠沛琉离！\n"NOR + HIR"$N一掌拍向$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLU  "遮天盖地！\n"NOR + HIB"$N双掌一错连续拍向$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "雷历风行！\n"NOR + HIM"$N左掌立于胸前，右掌推出击向$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "惊涛骇浪！\n"NOR + HIC"$N身形凌空飞起，从空中当头出掌攻向$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",extra*10);
	      me->add_temp("apply/attack", -extra);
	me->add("neili",-300);
	me->start_busy(3);
	return 1;
}
