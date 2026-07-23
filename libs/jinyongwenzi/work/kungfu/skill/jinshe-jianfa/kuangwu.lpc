// jinshe-jianfa perform
//by snowman

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
         int j, z;
        object weapon;
        j = me->query_skill("jinshe-jianfa", 1)/8;
        z = me->query_skill("jinshe-zhang", 1)/8;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「金蛇狂舞」只能在战斗中对对手使用。\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "jinshe-jianfa")
                return notify_fail("你必须在使用剑时才能使出「金蛇狂舞」！\n");

        if(me->query_skill("jinshe-jianfa", 1) < 120 )
                return notify_fail("你的金蛇剑法还不够娴熟，使不出「金蛇狂舞」绝技。\n");

        if(me->query_skill("jinshe-zhangfa", 1) < 120 )
                return notify_fail("你的金蛇游身掌还不够娴熟，使不出「金蛇狂舞」绝技。\n");

        if( (int)me->query_skill("force") < 170 )
                return notify_fail("你的内功等级不够，使不出「金蛇狂舞」绝技。\n");

        if( (int)me->query_str() < 27)
                return notify_fail("你的膂力还不够强劲，使不出「金蛇狂舞」绝技。\n");

        if( (int)me->query_dex() < 27)
                return notify_fail("你的身法还不够迅猛，使不出「金蛇狂舞」绝技。\n");

        if (me->query_skill_prepared("strike") != "jinshe-zhangfa"
        || me->query_skill_mapped("strike") != "jinshe-zhangfa")
                return notify_fail("「金蛇狂舞」需要使用金蛇游身掌。\n");                                                                                 

        if( (int)me->query("max_neili") < 800 )
                return notify_fail("你现在内力太弱，使不出「金蛇狂舞」。\n");      

        if( (int)me->query("neili") < 500 )
                return notify_fail("你现在真气太弱，使不出「金蛇狂舞」。\n");

        msg = HIY"\n突然$N绕着$n快速奔走，猛然击出两剑一掌，齐齐指向$n！\n\n"NOR;

        me->add_temp("apply/strength", z);
        me->add_temp("apply/attack", j); 

        if(weapon->query("id") == "jinshe sword" || !userp(me)){
          	me->set_temp("jsj", 1);
          	me->add_temp("apply/damage", 50);
          	msg = HIR"\n$N手中金蛇剑连划数剑，逼出道道金光，剑光中$N化身为二，掌剑齐出，直指$n！\n\n"NOR;
        }        

        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        me->add("neili", -100);
        me->add("jingli", -10); 
        if(me->query_temp("jsj"))
          	message_vision(HIY"                                                                     ※※  金  ※※\n"NOR,me);       

        weapon->unequip(); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        me->add("neili", -100);  
        me->add("jingli", -10);
        if(me->query_temp("jsj"))
          	message_vision(HIY"                                                                     ※※  蛇  ※※\n"NOR,me);

        weapon->wield();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        me->add("neili", -100);  
        me->add("jingli", -10);
        if(me->query_temp("jsj"))
          	message_vision(HIY"                                                                     ※※  狂  ※※\n"NOR,me);

        if(me->query_temp("jsj"))
        {          
        	weapon->unequip(); 
        	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        	me->add("neili", -50);  
        	me->add("jingli", -5);
       	 	message_vision(HIY"                                                                     ※※  舞  ※※\n"NOR,me);        
        	weapon->wield();               
        	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        	me->delete_temp("jsj");
        	me->add("neili", -50);
        	me->add("jingli", -5);
        	me->add_temp("apply/damage", -50);
        }

        me->add_temp("apply/strength", -z);
        me->add_temp("apply/attack", -j);

        me->start_busy(2+random(2));
        target->start_busy(1);
        return 1;
}
