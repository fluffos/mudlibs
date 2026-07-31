// ning@fengyun
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
        extra = me->query_skill("wuzhan-mei",1);
        if ( extra < 280) return notify_fail("你的［五展梅］还不够纯熟！\n");



	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("［落花剑］只能对战斗中的对手使用。\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在内力太弱，不能使用「雨激梅花半瓣香」。\n");

	if(me->query_skill("wuzhan-mei")<300)
	return notify_fail("你的五展梅不够娴熟，不能运用「雨激梅花半瓣香」。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");


	weapon = me->query_temp("weapon");
        msg = HIW"$N配合［梅花步］双脚一顿，笔直跃起，手中"+ weapon->name() + HIW"不停地颤抖着\n随着李商隐的＜锦 瑟＞一诗剑光笼罩住$n全身！\n\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "锦瑟无端五十弦 \n" NOR + CYN "$N身形向上飘起，手中$w"NOR + CYN"虚虚实实纷纷扬扬撒向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "一弦一柱思华年 \n" NOR + CYN "$N左手向$n面门一晃，右手$w"NOR + CYN"抖出一朵剑花刺向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "庄生晓梦迷蝴蝶 \n" NOR + CYN "$N身形绕$n一转，手中$w"NOR + CYN"望空一指，幻出满天剑影，攻向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "望帝春心托杜鹃 \n" NOR + CYN "$N身形飘然而起，悠然一剑手中$w若有若无淡淡刺向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "沧海月明珠有泪 \n" NOR + CYN "$N纵起丈余，头下脚上，手中$w"NOR + CYN"舞成一个光球罩向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "蓝田日暖玉生烟 \n" NOR + CYN "$N手中$w"NOR + CYN"嗡嗡微振，幻成一条白光刺向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         me->add_temp("apply/damage",2000);
        msg = HIW  "此情可待成追忆 \n" NOR + HIC "$N纵身轻轻跃起，剑光如水，一泻千里，洒向$n全身！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "只是当时已茫然 \n" NOR + HIC "$N手中$w"NOR + HIC"一沉，无声无息地滑向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-2000);
me->add("neili",-380);
        me->start_busy(5);
	return 1;
}
