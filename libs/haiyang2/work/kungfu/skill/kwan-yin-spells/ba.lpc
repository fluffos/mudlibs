 //mimicat@fy4
#include <ansi.h> 
inherit F_SSERVER;
int perform(object me, object target)
{
        int extra;
        

        
        extra=me->query_skill("kwan-yin-spells",1);
                        
        if(extra<60)
                return notify_fail("你观音六字明咒的等级不够高。\n");
                
        if(target&& me!=target)
                return notify_fail("这个真言法术只能用在自己身上。\n"); 
        if( (int)me->query("neili") < 100 )
                return notify_fail("你的法力不够。\n");
        
        if (me->query_temp("shield_force"))
                return notify_fail("你已经在运法之中了。\n");    
        message_vision(
        HIW "$N右手摆在胸前，中指微曲，拇指搭在中指侧，其余三指展开如莲花初放，念道：“叭” \n"
        CYN "$N浑身上下渐渐泛出一圈圣洁的光华，令人难以正视。\n"NOR     ,
                        me, target ); 
        me->add("neili", -100);
        me->start_busy(2);
if (extra> 200) extra=200;        
        me->add_temp("apply/armor",  1000);
        me->add_temp("apply/defense",  100);
        me->set_temp("shield_force/msg",
                CYN"$n身上的光华消融了$N的攻势。\n"NOR);
        extra=extra+random(extra);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/3);     
        // 60/3 =20 sec .. too powerful
        return 1;
}  
void remove_effect(object me)
{
        me->add_temp("apply/armor",-1000);
         me->add_temp("apply/defense",-100);
        me->delete_temp("shield_force");
        message_vision(HIW"$N身上的光华渐渐消失了。\n"NOR,me);
}       
