#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
 
int perform(object me, object target)
{
    object weapon, ob;
    string msg;
    int i;
 
 ob = me->select_opponent();

    if( !me->is_fighting() )
        return notify_fail("太极剑的「连」字决只能在战斗时使用。\n");
     if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    else me->set_temp("secondly_weapon",1);
    if( (int)me->query("neili") < 200 )
        return notify_fail("你的真气不够！\n");
    if( (int)me->query_skill("sword") < 100 ||
        me->query_skill_mapped("sword") != "taiji-jian")
        return notify_fail("你的「太极剑」还不够精纯，无法使用「连」字决！\n");
msg = BLINK HIY "$N手中长剑连连化出数个太级如意，一片太极圆圈向前涌去！！！\n\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    me->add("neili", -150);
    me->set_temp("perform",time()+3);
    me->set_temp("perform_lian",1);
    for(i = 0; i < 13; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg",HIM"圆转如意\n"NOR);
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_lian");
    me->delete_temp("secondly_weapon");
    return 1;
}

