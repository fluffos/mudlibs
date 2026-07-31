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
        return notify_fail("「乱拳」只能在战斗时使用。\n");
     if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");
    if( me->query_temp("weapon"))
        return notify_fail("你先放下手中的武器再说吧？！\n");
        if( (int)me->query("neili") < 200 )
        return notify_fail("你的真气不够！\n");
       if( (int)me->query_skill("cxwx-quan") < 500 ||
        me->query_skill_mapped("unarmed") != "cxwx-quan")
        return notify_fail("你的「痴心妄想拳」还不够精纯，无法使用「乱拳」！\n");
msg = HIR "$N狂吼一声，双拳猛的一撞，两臂灌满内劲向前狂轰而出！！！" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    me->add("neili", -150);
    me->set_temp("perform",time()+3);
    me->set_temp("perform_luan",1);
    for(i = 0; i < 3; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg",HIY"招式未老\n"NOR);
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_luan");
    me->delete_temp("secondly_weapon");
    return 1;
}


