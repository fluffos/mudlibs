
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
	"$N侧身一退，踏入左面的乾门，$n双眼一花。\n",
	"可是$N身形一晃，突然之间转到了坤门，出现在$n的身后，$n双眼一黑。\n",
	"只见$N连着几个旋身，自坎而离，过兑门入震门，脚下一点立在了艮门，$n双眼一黑。 \n",
	"说时迟那时快，$N在千钧一发之际不退反进，扑入巽门之中，$n双眼一黑$n双眼一黑 \n",
	"$N就势一转，退入右侧坎门之中，$n双眼一花。\n",
	"$N哈哈大笑几声，一个跟头翻入兑门，轻轻将来势尽数化解。$n双眼一黑，$n双眼一黑\n",
	"但是$N轻轻一纵，顿时没了踪影。$n定睛一看，原来$N早躲到了离门之中，$n双眼一黑。\n",
	"$N身形斜飞，落入震门之中，毫不费力地破坏了$n的步法，$n双眼一黑。\n"
});

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[八卦伏魔]只能在战斗中使用。\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("请使用崆峒心法!\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 30)
                return notify_fail("你的崆峒心法还不够。。。\n"); 

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
