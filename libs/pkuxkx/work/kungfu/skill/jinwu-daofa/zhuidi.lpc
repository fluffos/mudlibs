// jinwu.c 金乌堕地

#include <ansi.h>
#define Menpai "雪山派"
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon, weapon2, *inv;
        int skill, ap, dp, damage, equip;

        if( !target ) target = offensive_target(me);  
        if( !target || !me->is_fighting(target) )
                return notify_fail("「"+HIR"金乌堕地"NOR+"」只能在战斗中对对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
            return notify_fail("你使用的武器不对。\n");
 
        if ((int)me->query_skill("jinwu-daofa",1) < 120) 
                return notify_fail("你的金乌刀法还不够纯熟！\n");
        if ((int)me->query_skill("xueshan-neigong", 1) < 120)
                return notify_fail("你的雪山内功功力太浅，使不出「"+HIR"金乌堕地"NOR+"」。\n");                
        if ((int)me->query("max_neili") < 2000)
                return notify_fail("你的内力修为太浅，使不出「"+HIR"金乌堕地"NOR+"」。\n");
        if ((int)me->query("neili") < 1000)
                return notify_fail("你的内力不够，使不出「"+HIR"金乌堕地"NOR+"」。\n");
    	if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        	&& !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        	&& me->query_skill_mapped("force") != "xueshan-neigong" )
            	return notify_fail("你真气运转方式不对，使不出「"+HIR"金乌堕地"NOR+"」。\n");                  

        message_vision(HIY"$N纵身跃起,使出"+HIR"「金乌堕地」"NOR+""+HIY"，半空中挥刀直劈，刀锋离地尚有数尺，地上已是尘沙飞扬。\n"NOR, me, target);
        me->start_perform(5,"「金乌堕地」");

        ap = me->query_int()*me->query_skill("blade");
        dp = target->query_dex()*target->query_skill("dodge");
        if( dp < 1 )  dp = 1;
//命中率C-        	
        if( F_KUNGFU->hit_rate( ap, dp, 9, me, target) ) {
                if(userp(me))  me->add("neili",-300); 
                message_vision( HIR"$n避无可避，极力后退隔挡，却只见刀光一闪，毫不停息，一刀正中面门。\n"NOR, me, target);
                damage = (int)me->query_skill("blade",1) + (int)me->query_str()*10;
                damage += random(damage);
                if(damage > 4000)  damage = 4000;
                F_KUNGFU->hit_wound("qi", damage, damage/4, me, target);
                COMBAT_D->report_status(target);
                if(!target->is_busy())
                  target->start_busy(2+random(1));
                me->start_busy(1+random(1)); 
                objectp(weapon2 = target->query_temp("weapon"));

                if( me->query("str") >= 20
                 && objectp(weapon2 = target->query_temp("weapon"))
                 && me->query_str() >= 40
                 && !me->query("betrayer")
                 && (int)me->query_skill("jinwu-daofa", 1) > 200
                 && (int)me->query_skill("xueshan-neigong", 1) > 200 ){
                       inv = all_inventory(target);
                       for(equip=0; equip<sizeof(inv); equip++){
                               if(inv[equip]->query("weapon_prop") && ((string)inv[equip]->query("equipped")=="wielded")){ 
                                       message_vision( HIW "\n$N力道未尽，手中刀势不绝，只听铛的一声，$n手上的"NOR""+inv[equip]->query("name")+HIW"已被劈成两半，掉在了地上！\n"NOR, me, target);                                       inv[equip]->unwield();
                                       inv[equip]->reset_action();
                                       inv[equip]->unequip();
                                       if ( !inv[equip]->is_gems() )
                                       {
                                         inv[equip]->set("name", "断掉的"+ inv[equip]->query("name") );
                                         inv[equip]->set("value", 0);
                                         inv[equip]->set("weapon_prop", 0);
                                         inv[equip]->set("long", "一把破烂武器，从中断开，破口整齐，看来是被高手一刀劈开的。\n");
                                       }
                                       inv[equip]->move(environment(target));
                                }
                       } 
                       return 1;
                }
        }else{
                if(userp(me))  me->add("neili",-100);
                message_vision( HIW"可是$n轻轻往旁边一闪,避过了$N这必杀的一刀。\n"NOR, me, target);;
                me->start_busy(3+random(2));
        }      

        return 1;
}

