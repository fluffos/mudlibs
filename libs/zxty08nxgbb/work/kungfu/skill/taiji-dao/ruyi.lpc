#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
#define PFM_NAME        "圆转如意"
int perform(object me, object target)
{
    object weapon, ob;
    string msg;
    int i;
 
        me->clean_up_enemy();
    ob = me->select_opponent();
if (me->is_fighting())
{
if  (environment(me)!=environment(ob) ) 
     return notify_fail("对方已经不在了。\n");
}


    if( !me->is_fighting() )
        return notify_fail("「圆转如意」只能在战斗时使用。\n");
     if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    else me->set_temp("secondly_weapon",1);
    if( (int)me->query("neili") < 200 )
        return notify_fail("你的真气不够！\n");
    if( (int)me->query_skill("blade") < 100 ||
        me->query_skill_mapped("blade") != "taiji-dao")
        return notify_fail("你的「太极刀法」还不够精纯，无法使用「圆转如意」！\n");
        msg = HIY "$N" HIY "闭目凝神，心如点转，一招充满太极刀意的「" HIW + PFM_NAME +
              HIY "」缓缓使出，招式返朴归真，看似平淡无奇，\n实则汇集了天地之间的正气，"
              HIY "由手中" + weapon->name()+ HIY"幻化出无数太极八卦，铺天盖地的压向"+ob->query("name")+"！\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    me->add("neili", -150);
    me->set_temp("perform",time()+3);
    me->set_temp("perform_qunxie",1);
    for(i = 0; i < 3; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg",HIB"刀锋画圆\n\n"NOR);
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_qunxie");
    me->delete_temp("secondly_weapon");
    return 1;
}


