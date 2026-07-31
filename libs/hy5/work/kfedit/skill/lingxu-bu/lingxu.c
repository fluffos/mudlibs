
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string *dodge_msg = ({
        "$n一招「晴日催花暖欲然」，不带烟火。\n",
        "只见$N身法一折三迭，一式「日长蝴蝶飞」早已在七尺之外。\n",
        "$N使出「桃李依依春黯度」，轻轻松松地一闪而过。\n",
        "$N左足一点，一招「带恨眉儿远岫攒」潇洒出尘。\n",
        "可是$N使一招「粉英金蕊自低昂」，身子轻轻飘了开去。\n",
        "$N身影连展，已经藉一招「渐岘绿娇红姹」迷惑得$n双眼一花。\n",
        "$N一招「醺酣争撼白榆花」使出，早已绕到$n身後！\n"
});

int perform(object me, object target)
{
        string msg;

int count;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[凌虚步]只能在战斗中使用。\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");



        if ( !wizardp(me) && me->query_skill_mapped("force") != "baiyun-xinfa")
                return notify_fail("请使用白云心法!\n");

        if((int)me->query_skill("baiyun-xinfa",1) < 50)
                return notify_fail("你的白云心法还不够。。。\n"); 

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
count = (int)me->query_skill("lingxu-bu") / 60 + 1;
  message_combatd(WHT "$N身行一晃，顿时无数条身影一下子出现在$n的面前。。\n" NOR, me,target);
if( count > 5 ) count = 5;
   while( count-- )
	 {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {

     break;
   }
  else

  message_combatd(HIW "$N化为一道白光，虚幻不定的出现在$n的周围。\n" NOR, me, ob);
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
if (!me->query("double_attack"))
  COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }

        return 1;
}
