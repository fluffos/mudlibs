#include <ansi.h>

inherit F_SSERVER;
void remove_effect(object me, int i);

int perform(object me, object target)
{
        int skill;

        if(!objectp(target)) return notify_fail("你要传功给谁？\n"); 
        if(target == me)
                return notify_fail("你要传功给谁？\n");                
        if((int)me->query("neili") < 500  ) 
                return notify_fail("你的内力不够。\n");
        if((int)target->query_temp("yinfeng") > 2) 
                return notify_fail("对方已经不能再承受更多的功力了。\n");
        if((int)me->query_temp("chuangong"))
                return notify_fail("你的已经在运用传功了。\n");
        if((int)me->query_skill("force") < 150 )
                return notify_fail("你的内功等级不够，还不能传功给别人。\n");
        if((int)me->query_skill("shenghuo-shengong", 1) < 100 )
                return notify_fail("你的圣火神功等级不够，还不能传功给别人。\n");
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力还不够强劲，不能传功给别人。\n");
        if((int)me->query("neili") < 500 )
                return notify_fail("你的真气不足了，不能传功给别人。\n");
        if((int)target->query_skill("shenghuo-shengong", 1) < 130 )
                return notify_fail("对方的圣火神功等级不够，不能接受你所传的功力。\n");
        skill = me->query_skill("force")/3;
        me->add("neili", -400);
        me->receive_damage("qi", 150);
        me->receive_damage("jing", 150);
        me->receive_damage("jing", 150);
        message_vision(HIR"\n$N将手掌贴在$n背心大穴上，脸上"RED"红光"HIR"时隐时显，将功力传给$n！\n\n"NOR, me, target);
        target->add_temp("yinfeng", 1);
        me->set_temp("chuangong", 1);
        tell_object(target, YEL+me->name()+"的功力传入了你的体内，正好可以用来加强阴风刀的威力！\n"NOR);
        me->start_call_out( (: call_other, this_object(), "remove_effect", me :), skill);
        target->start_call_out( (: call_other, this_object(), "remove_effect", target, 1 :), skill);              
        if(userp(me))
            me->start_busy(10);
        else me->start_busy(5);
        return 1;
}

void remove_effect(object me, int i)
{        
	if(i) me->delete_temp("chuangong");
	else{
            me->add_temp("yinfeng", -1);
            tell_object(me, YEL"\n你体内别人的功力已经用完，阴风刀威力又恢复正常了！\n"NOR);
            }
}
