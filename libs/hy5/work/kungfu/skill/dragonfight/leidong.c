// 应dxh建议 改动命中率和伤害

#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int def;
int perform(object me, object target)
{       
        string msg;
object weapon;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
        || !me->is_fighting(target) || !living(target) )
                return notify_fail("「雷动九天」只能在战斗中使用。\n");
       
        if( (int)me->query_skill("dragonfight", 1) < 100 
        ||  (int)me->query_skill("unarmed", 1) < 100 )
                return notify_fail("你有的功夫还不够娴熟，不会使用「雷动九天」。\n");

 if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展？\n");

        if( !wizardp(me) && me->query_temp("weapon") )
                return notify_fail("你必须空手才能使用本门绝学!\n");

    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("必须靖海神功才行。\n");

      if( (int)me->query_skill("jinghai-force", 1) < 60 )
                return notify_fail("你的靖海神功还差些火候。\n");

        if(me->query_skill("force", 1) <100)
                return notify_fail("以你现在的内功修为还使不出「雷动九天」。\n");        
        if (me->query_skill_mapped("unarmed") != "dragonfight")
                return notify_fail("你现在无法使用「雷动九天」进行攻击。\n");                                                                                 
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("你的内力修为太弱，不能使用「雷动九天」！\n");
        if( (int)me->query("neili") < 600 )
                return notify_fail("你的真气不够！\n");
        msg = RED "\n 突然$N大喝一声:「雷动」,面色唰的变得通红,须发皆飞,浑身上下充满杀气,\n" NOR;
        message_vision(msg, me, target); 
        msg = YEL "\n        “嗡”的一声，一掌凌空击向$n的胸口！\n" NOR;
        //if (random(me->query("combat_exp")) > random((target->query("combat_exp")/2))
        if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)) || random(3)==0)
        {
                me->start_busy(2);
                target->start_busy(2);
                damage = (int)me->query_skill("dragonfight", 1);
                damage = damage + random(damage/2);
                def=(int)target->query_temp("apply/armor");
                //damage -=damage*def/3000;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);               
                me->add("neili", -(damage/4));
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                target->set_temp("last_damage_from", me);
                if(me->query_skill("dragonfight", 1) > 119)
                        call_out("perform2", 0, me, target);    
        } 
        else 
        {       
                //me->start_busy(3);
                me->start_busy(2);
                me->add("neili", -200);                
                msg += HIY"可是$p伏地一滚，躲开了对手的攻击。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target)
{
        int damage, p,skill;
        string msg,weapon;
        weapon = me->query_temp("weapon");  
        
        if (!target || !me ) return notify_fail("对手已经不能再战斗了。\n");
        if(!living(target)) 
                return notify_fail("对手已经不能再战斗了。\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你待要再出第二击，却发现自己的内力不够了！\n");     
        msg = MAG "\n只见$N衣袍鼓起，猎猎飞舞，身子凌空飞起，又是一声大吼「九天」，\n" NOR;
        message_vision(msg, me, target); 
        msg = CYN "\n       “哗”的挥出九个光圈，居高临下，直向$n逼来。\n" NOR;
        //me->start_busy(1);
        //target->start_busy(2);
        damage = (int)me->query_skill("dragonfight", 1);
        damage = damage+(int)me->query_skill("unarmed", 1);
        damage = damage+(int)me->query_skill("jinghai-force", 1);
        damage = (damage + random(damage))/2;
                
        def=(int)target->query_temp("apply/armor");
        //damage -=damage*def/4000;
        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage,me);
        me->add("neili", -random(damage/10));
        p = (int)target->query("qi")*100/(int)target->query("max_qi");
        msg += damage_msg(damage, "内伤");
        msg += "( $n"+eff_status_msg(p)+" )\n";
        target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}

