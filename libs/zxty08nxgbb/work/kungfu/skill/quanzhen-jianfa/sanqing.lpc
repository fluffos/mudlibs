#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon, ob;
    string msg;
        me = this_player();
    me->clean_up_enemy();
 ob = me->select_opponent();
if (me->is_fighting())
{
if  (environment(me)!=environment(ob) ) 
     return notify_fail("对方已经不在了。\n");
}
        if ( (string)me->query("family/family_name") != "全真教") 
                 return notify_fail("只有全真教弟子才能使用该PFM。\n");
   if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");
        if( !me->is_fighting() )
                  return notify_fail("全真剑法的「一剑化三清」只能在战斗时使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    else me->set_temp("secondly_weapon",1);

    if( (int)me->query_skill("sword") < 300 ||
        me->query_skill_mapped("sword") != "quanzhen-jianfa")
        if( (int)me->query("neili") < 5000 )
                return notify_fail("你的真气不够！\n");
        if( (int)me->query("max_neili") < 5000 )
                return notify_fail("你的内力修为不够！\n");


      msg = HIY "$N使出全真派绝技「一剑化三清」，身法陡然加快,手握剑柄晃成三条白龙！\n" NOR;
    message_vision(msg, me);
    me->set_temp("perform",time()+3);
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
       msg = WHT  "赤血白龙！" NOR;
    message_vision(msg, me);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = WHT  "化血白龙！" NOR;
    message_vision(msg, me);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = WHT "怒血白龙！" NOR;
    message_vision(msg, me);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->add("neili",-random(700));
}
    me->delete_temp("secondly_weapon");
    return 1;
}
