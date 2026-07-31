// shewu.c 蛇舞
#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me)
{
    int skill,n;
    object ob,snake,target,soldier;
    me=this_player();
    skill = me->query_skill("shedao-qigong",1);


        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me
        ||   !me->is_fighting(target))
                return notify_fail("你想对付谁呀？\n");

    if ((int)me->query("neili") < 500 )
        return notify_fail("你的内力不够充沛,无法弹出「蛇舞」。\n");
    
    if ((int)me->query("jing") < 50 )
        return notify_fail("你的精力不够,无法专心弹琴。\n");

    if (me->query_skill("shedao-qigong",1)<100)
        return notify_fail("你的蛇岛奇功不够娴熟。\n");
    
    if (skill < 100)
        return notify_fail("你的蛇岛奇功不够娴熟。\n");


        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("你刚弹过「蛇舞」\n");

    if(environment(me)->query("sleep_room"))   
        return notify_fail("在这里召唤似乎不太适合吧。\n");  

    if(environment(me)->query("no_fight"))   
        return notify_fail("在这里召唤似乎不太适合吧。\n");  

    if(me->is_busy())
        return notify_fail("你现在正忙着呢！\n");


    message_vision(HIB"$N盘膝而坐，双手拂琴，时而快疾，时而缓慢，可似乎并未弹出声音。\n"NOR,me); 
    
   
            message_vision("突然，$N感觉身边黑影闪动，只见一条四脚神龙正吐着信子，昂首随着$N双手的节奏舞动。\n",me);

        skill=(int)me->query_skill("shedao-qigong",1);
        skill=skill*0.8;
        seteuid(getuid());
        soldier = new("/d/biwu/dulong");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set_temp("nozh",1);
        soldier->set("possessed", me);
        soldier->invocation(me);
        soldier->set_skill("dodge",skill*3/4);
        soldier->set_skill("dragon",skill*3/4);
        soldier->set_skill("parry",skill*3/4);        
        soldier->set_skill("unarmed",skill*3/4);
        soldier->set_skill("force",skill*3/4);   
        me->start_busy(3);
        me->add("neili",-300); 
        me->add("jing",-200); 
        me->apply_condition("zdizi_busy",5);
        me->start_busy(3);

    return 1;    
}
