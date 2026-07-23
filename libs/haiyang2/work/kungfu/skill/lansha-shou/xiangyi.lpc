#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
        int extrb;
	object weapon;
	 extra = me->query_skill("lansha-shou",1);
   if ( extra < 300) return notify_fail("你的［蓝砂手］还不够纯熟！\n");

        extrb = me->query("force");

    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");
        if (extra> 200) extra=200;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［帝王长相忆］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
        msg = HIB "$N配合着苏轼的 －－江城子－－ ，使出［帝王长相忆］，一气攻出十连技！\n\n" NOR;
	message_vision(msg,me,target);
        msg = HIB "十年生死两茫茫！\n"NOR + HIC"$N眼望远方，神不守舍，就在$n一怔时猛然出手攻向$n的$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "不思量，自难忘！\n"NOR + HIC"$N背向$n左手支头，右手向后虚空一挥，一道劲气直扑$n的$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "千里孤坟，无处话凄凉！\n"NOR + HIC"$n眼前一花，顿时失去了$N的踪影，只觉一股内力从后直射$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "纵使相逢应不识，\n"NOR + HIC"$N迎面向$n撞去，双臂微曲，同时击向$n的$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "尘满面，鬓如霜\n"NOR + HIC"只见$N满头的黑发根根竖起，刺向$n的$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "夜来幽梦忽还乡，\n"NOR + HIC"$N身形突转，口中发出摄人魂魄的梦唁，脚下却飞踢$n的$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "小轩窗，正梳妆！\n"NOR + HIC"$N双手直梳，十指张开，抓向$n的$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "相顾无言，惟有泪千行！\n"NOR + HIC"$n回头一看$N竟不知何时已到了身后，千道指力回旋着飞向$n的$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "料得年年断肠处，\n"NOR + HIC"$N化掌为刀，左削右削前削后削上削下削，一连六削，掌掌砍向$n的$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "明月夜，短松冈！\n"NOR + HIC"$N举手向天，手心劲力一吐，浑身内力如决堤的江水，滚滚翻向$n的$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili",-580);
        me->start_busy(5);
	return 1;
}
