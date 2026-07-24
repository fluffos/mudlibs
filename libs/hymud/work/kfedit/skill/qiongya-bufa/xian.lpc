
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
     "$N低头细数裙褶，情思困困，步法回旋之际似乎娇柔无力，却将$n搞的眼花嘹乱。\n",
     "只见$N一个转身，忽然回眸一笑。$n一楞之下，哪里还有人在。\n",
     "$N婉尔一笑，不退反进，身形径向$N飘来。\n$n只觉一股甜香入鼻，这一招竟无着力之处。\n",
     "$N身法轻灵，腰肢几拧，居然幻出斑驳月影。$n眼一花，哪里分得出是人，是影。\n",
     "$N裙裾飘飘，白衣姗姗，已然从$n头顶飞过，这般女神端丽之姿，仙子缥缈之形，$n不由得看呆了！\n",
     "$N脚步轻盈，风姿嫣然，身子便如在水面上飘浮一般掠过，不等$n劲风袭到，已悄然隐去。$n双眼一黑。\n",
     "$N纤腰微颤，带飞如虹，轻轻将$n劲力拨在一旁，尽数化解。$n双眼一黑。\n",
});

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[仙女下凡]只能在战斗中使用。\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("请使用碧涛心法!\n");

        if((int)me->query_skill("bitao-shengong",1) < 30)
                return notify_fail("你的碧涛心法还不够。。。\n"); 

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = HIW+dodge_msg[random(sizeof(dodge_msg))]+NOR;
        if( me->query("combat_exp") > random((int)target->query("combat_exp")) ) {
                msg += HIR "结果$p被$P绕得不知所措！\n" NOR;
                target->start_busy(5);
                me->add("neili", -100);
                       } else {
                msg +=  GRN"结果$P自己绕了个头晕眼花。\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
