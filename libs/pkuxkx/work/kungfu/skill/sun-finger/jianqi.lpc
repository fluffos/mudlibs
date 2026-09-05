#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage, sword,ap,dp,lv;
        string msg;
        
        if (!me->query("yiyangzhi/sword"))
                return notify_fail("你并没有学会使用这项绝技。\n");
                
        if(me->query("family/family_name") != "大理段家" && me->query("chushi/last_family") != "大理段家" )
          return notify_fail("「剑气纵横」是段家不传之密，恐怕你现在不方便使用吧！\n");  

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("「剑气纵横」只能对战斗中的对手使用。\n");

        if( !objectp(weapon = me->query_temp("weapon")) 
           || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，怎能运用「剑气纵横」？！\n");
        
        if( (int)me->query_skill("sun-finger", 1) < 100 ||
           (int)me->query_skill("sword", 1) < 100 ||
            (int)me->query_str() <=25 )
                return notify_fail("你修为还不够，还未能领悟「剑气纵横」！\n");

        if( me->query_skill("duanjia-xinfa", 1) < 100 )
                return notify_fail("你的内功修为火候未到，施展只会伤及自身！\n");

        if( me->query_skill_mapped("force") != "duanjia-xinfa")
                return notify_fail("你所用的内功与「剑气纵横」心法相悖！\n");
                
        if (me->query_skill_mapped("sword") != "sun-finger" )
                return notify_fail("「剑气纵横」乃是一阳指运用于剑法中的绝招。\n");                                                                                 
      
        if( me->query("max_neili") <= 1000 )
                return notify_fail("你的内力修为不足，劲力不足以施展「剑气纵横」！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够，劲力不足以施展「剑气纵横」！\n");

        if(!wizardp(me) && time()-me->query_temp("jianqi_time") < 6)
                return notify_fail("你刚使完「剑气纵横」，目前气血翻涌，无法再次运用！\n");
        me->set_temp("jianqi_time",time());  
              
        lv=me->query_skill("sun-finger",1)/50;
       
        message_vision(HIM"\n突然$N脸上紫气隐现，一阳内力迸发，手中"+weapon->name()+HIM"倏然金芒大炽，锋锐不可逼视！
        这一招使得剑气纵横，竟有雷光隐动。不明其理之人，无不骇异！\n\n" NOR, me);

        me->add("neili", -100); 
        me->start_busy(2);
        ap = me->query("combat_exp");
        dp = target->query("combat_exp");
        if (random(ap) > dp/2 || !random(6))  
        {
                damage = (int)me->query_skill("sun-finger", 1) + (int)me->query_skill("sword",1);
                damage = damage/2 + random(damage/2);
                target->receive_damage("qi", damage, me);
                //加入busy效果
                if(!target->is_busy())  
                {
                        target->start_busy(3+lv);
                        msg = HIR"$n看到$N这气拔千钧的剑气，竟不知如何招架！\n"NOR;
                }
        }
        else
        {
                me->start_busy(2+random(2));
                msg = HIR"$n不以为动狂笑道:米粒之光,也敢与日月争辉！\n"NOR;
        }
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        return 1;
}

