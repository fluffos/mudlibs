// written by lmimi
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    int extra,extrb;
    object weapon;
    extra = me->query_skill("diwangquan",1);

    if ( extra < 180) return notify_fail("您的神龙帝王拳还不够纯熟！\n");
if(me->is_busy()) me->remove_busy();

        if( me->query("neili") <= 500 )
                return notify_fail("你的内力不够！\n");
        if( me->query("jing") <= 500 )
                return notify_fail("你的精力不够！\n");
                
    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("［神龙八式］只能对战斗中的对手使用。\n");
    weapon = me->query_temp("weapon");

      if( objectp(me->query_temp("weapon")) )
           return notify_fail("你必须空手使用！\n");     
target->set_temp("is_unconcious",1);
if (extra > 200) extra=200;
    me->add_temp("apply/attack",100);
    me->add_temp("apply/damage",1500);
    msg = HIM  "$N大喝一声,使出了洪教主的成名绝技「" + HIC "神龙八式" + HIM "」，双掌绵绵不绝地向$n拍出！\n" NOR;
    message_vision(msg,me,target);

if (random(3)==0)
    target->start_busy(4);

   
    msg = HIW  "\n「第一式---龙马精神」！\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    
    msg = HIG  "\n  「第二式---龙蛇飞动」！\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   
    msg = HIY  "\n    「第三式---龙盘虎踞」！\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

    msg = BLU  "\n      「第四式---龙争虎斗」！\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   
    msg = WHT  "\n        「第五式---龙腾虎跃」！\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    
    msg = MAG  "\n          「第六式---龙越凤鸣」！\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
  
    msg = CYN  "\n            「第七式---龙凤呈祥」！\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    
    msg = HIC  "\n              「最后一式---龙的传人」！\n" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack",-100);
    me->add_temp("apply/damage",-1500);

target->delete_temp("is_unconcious");
  me->start_busy(3);
  me->add("neili",-380);
    return 1;
}
