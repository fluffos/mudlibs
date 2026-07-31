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
 
if ( (string)me->query("family/family_name") != "丐帮") 
     return notify_fail("只有丐帮弟子才能使用该PFM。\n");


    if( !me->is_fighting() )
        return notify_fail("天下无狗只能在战斗中使用。\n");
     if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "club")
        return notify_fail("你使用的武器不对。\n");
    else me->set_temp("secondly_weapon",1);
    if( (int)me->query("neili") < 200 )
        return notify_fail("你的真气不够！\n");
    if( (int)me->query_skill("club") < 160 ||
     me->query_skill_mapped("club") != "dagou-bang")
        return notify_fail("你的打狗棒法还不到家，无法使用「天下无狗」字决！\n");
msg = HIG "$N将手中兵器一挥，使出打狗棒法最后杀招"HIW"『天下无狗』"HIG",招式连续变换三次,让人防不胜防！\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -150);
    me->set_temp("perform",time()+3);  
     for(i = 0; i < 3; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
           me->set_temp("action_msg",HIW"紧接着"NOR);
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("secondly_weapon");
    return 1;
}

