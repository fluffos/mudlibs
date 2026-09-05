inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

int perform(object me, object target)
{
        int damage, p;
        string msg;
        
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("神掌夺魄只能对战斗中的对手使用。\n");
        if( !target->is_busy())
                return notify_fail("神掌夺魄能对忙乱中的对手使用。\n");
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器！\n");   
        if( (int)me->query_skill("jiuyin-shenzhang",1) < 180 )
                return notify_fail("你的掌法修为不足，使不出神掌夺魄。\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("你现在内力太弱，不能打出神掌夺魄。\n");
        if( (int)me->query("jiali") < 100 )
                return notify_fail("你现在加力太弱，不能打出神掌夺魄。\n");
        if (me->query_skill_prepared("strike") != "jiuyin-shenzhang"
            || me->query_skill_mapped("strike") != "jiuyin-shenzhang")
                return notify_fail("你现在无法使用神掌夺魄！\n");
                
        me->start_perform(4,"神掌夺魄");
        msg = HIR"$N趁着$n手忙脚乱之时，使出“神掌夺魄”！\n"NOR;
        {
                me->start_busy(1);
                damage = (int)me->query_skill("strike")+(int)me->query_skill("force");
                damage += random(me->query("jiali") * 10);
                damage *= 2;
                if(target->query("neili") > me->query("neili")) damage /= 2;
                if (damage>5000) damage=5000+random(500);  

                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/2, me);
                me->add("neili", -damage/2);
                if (me->query("neili") < 0)
                      me->set("neili",0);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += HIG"$N偷袭得手，重重的打在$n的胸口，$n登时鲜血狂喷。\n"NOR;
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
        }
        message_vision(msg, me, target);
        return 1;
}

