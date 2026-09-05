//Cracked by Roath
// bt_poison.c
// 白驼蛇毒
// Modified by iszt@pkuxkx, 2007-04-14

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    int damage = 1;

    if (me->query_condition("bt_poison")>(5+me->query_skill("poison",1)/20))
    {
        me->apply_condition("bt_poison", duration - 5 - me->query_skill("poison",1)/20);
    }
    else
    {
        me->delete_temp("death_cond_origin/bt_poison");
        return 0;
    }

    if( !living(me) ) 
    {
        message("vision", me->name() + "浑身溃烂，发出熏天的臭气，引来不少苍蝇。\n", environment(me), ({me}));
    }
    else 
    {
        if(me->query("eff_jing") > me->query("max_jing")*2/3) 
        {
            tell_object(me, HIR "你的伤口发麻，全身僵直，不听使唤，这不是普通的蛇毒！\n" NOR );
            message("vision", me->name() + "四肢扭曲，脚步踉跄。\n", environment(me), ({me}));
        }
        else if(me->query("eff_jing") > me->query("max_jing")/3) 
        {
            tell_object(me, HIR "你全身麻木，但神志却异常清醒，你中了白驼蛇毒了！\n" NOR );
            message("vision", me->name() + "身子慢慢垂下，口中发出僵硬的荷荷之声。\n", environment(me), ({me}));
        }
        else 
        {
            tell_object(me, HIR "你开始感到全身上下麻痒难当，偏偏又动弹不得！\n" NOR );
            message("vision", me->name() + "忽然满面堆欢裂嘴嘻笑，显得诡异无伦。\n", environment(me), ({me}));
        }
    }
//	if (duration > 0) damage = duration;
//	else damage = 10;
	damage = 100 + random(100);
	
    me->set_temp("death_cond_id", "bt_poison");
//	F_POISON->poison_eff(me,"bt_poison",(["jing":({1,damage/2}),]),1); 
	F_POISON->poison_eff(me,"bt_poison",(["qi":({1,damage}),"jing":({1,damage/2}),]), 1+random(2)); 


    return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}