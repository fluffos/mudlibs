#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
        "$N一招「天玑离枢戏七星」轻轻巧巧地避了开去。\n",
        "$N身影一晃，一式「天璇乱步踏星辰」早已避在七尺之外。\n",
        "$N使出「倒转北斗七星轮回」，轻轻松松地一闪而过。\n",
        "$N左足一点，一招「挪移逐影天枢转」腾空而起。\n",
        "$N使一招「风动玉衡星辰碎」，身子轻轻飘了开去。\n",
        "$N身影微动，已经藉一招「开阳薄雾邀月明」轻轻闪过。\n",
        "$N一招「瑶光音迟炎日淡」使出，早已绕到$n身後！\n"
        "$N身形陡地变得飘忽不定，令$n无法看清。\n",
        "$N双脚点地，全身化为一道白影，急速绕着$n打了几转。\n",
        "$N如一阵清风，舒缓地闪过了$n的凌厉攻势。\n",
        "$N便如闲庭信步，在弹指间已然退出丈外。\n",
        "$N左一转，右一绕，身影已消失不见。\n",
});

int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[北斗穿花步]只能在战斗中使用。\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "qingming-xuangong")
                return notify_fail("请使用青冥玄功!\n");

        if((int)me->query_skill("qingming-xuangong",1) < 50)
                return notify_fail("你的青冥玄功还不够。。。\n"); 

        if((int)me->query("neili") < 500)
                return notify_fail(HIY "你现在真气不足。\n" HIY);
        if((int)me->query("qi") < 500)
                return notify_fail(HIY "你现在气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        msg = HIW+dodge_msg[random(sizeof(dodge_msg))]+NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += HIR "结果$p被$P绕得不知所措！\n" NOR;
                target->start_busy(5);
                me->add("neili", -100);
                       } else {
                msg +=  GRN"结果$P自己绕了个头晕眼花。\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
count = (int)me->query_skill("chuanhua") / 50 + 2;
  message_combatd(HIR "$N身形陡地变得飘忽不定，令$n无法看清。\n" NOR, me);
if( count > 4 ) count = 4;
   while( count-- )
         {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {

     break;
   }
  else

  message_combatd(HIY "$N如一阵清风，瞬间出招。.\n" NOR, me, ob);

  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }

        return 1;
}