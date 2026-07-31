
#include <ansi.h>

inherit F_SSERVER;
//inherit COMBINED_ITEM;
//inherit SKILL;
void back(object target);

int perform(object me, object target)
{
        int skill,num;
        string msg;
        object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("jinshe-zhuifa", 1) < 120 )
                return notify_fail("你的金蛇锥法不够娴熟，不会使用蛇影万道。\n");

    if( (int)me->query("neili", 1) < 500 )
       return notify_fail("你现在内力不足！\n");  
        if( (int)me->query_str() < 40  )
                return notify_fail("你的臂力太低，无法同时发出那么多金蛇锥。\n");
       
        if (!weapon || !(weapon->id("zhui"))
        || me->query_skill_mapped("throwing") != "jinshe-zhuifa")
                return notify_fail("你现在无法使用蛇影万道。\n");
        if ((weapon->query_amount())<30)
             return notify_fail("你身上的暗器不够，无法使出蛇影万道。\n");  
       
        me->add("neili", -450);
        me->add("jingli", -150);
        message_vision(RED"$N清叱一声突然出手，数十道寒光随声暴射而出，有的交击互撞，有的借力反弹，盘旋飞舞，满天而来！\n"NOR, me, target);
        message_vision(RED"$n眼前刹那间寒芒闪动，无数金芒耀起万丈金光，急如飞蛇闪电，忙将兵刃狂舞，想护住全身！\n"NOR, me, target);;

  if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
     me->query_str() > (int)target->query_dex()) {
                destruct(weapon);
                message_vision(HIR"\n只听$n惨叫一声，无数"+HIY+"金蛇锥"+HIR+"已经击中全身要穴，看来已经被打成筛子了！\n"NOR, me, target);
                tell_object(target, HIY "啊！你全身上下都被暗器打穿了！\n" NOR);
                target->receive_damage("qi", (int)(me->query_skill("jinshe-zhuifa",1))*5);
                target->receive_wound("qi", 150);
                target->kill_ob(me);
                }
  else {
         message_vision(HIY"$n抱头缩颈一个滚翻，总算躲开了$N这致命攻击。\n"NOR, me, target);
         weapon->move(environment(me));
         me->start_busy(random(3));
         target->kill_ob(me);
        }
      
        return 1;
}


