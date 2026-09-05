// cixue.c 辟邪剑刺穴
//added by bing

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;
inherit YIZHAOYUN;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    int pp,damage,mm,tt,agile_wt,rate_level=10;
	object weapon;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) ||  !target->is_character() ||  !me->is_fighting(target) )
        return notify_fail("「刺穴」只能对战斗中的对手使用。\n");

    if (base_name(environment(me))[0..10] == "/d/changbai")
        return notify_fail("什么？\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_SEX) && 
        !present("flower shoes",me))
        return notify_fail("你没穿绣花小鞋，使不出刺穴一式。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_SEX) && 
        !present("pink cloth",me))
        return notify_fail("你没穿粉红绸衫，使不出刺穴一式。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_SEX) && 
        !present("golden ring",me))
        return notify_fail("你没戴金戒指，使不出刺穴一式。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_SEX) && 
        !present("golden necklace",me))
        return notify_fail("你没戴金项链，使不出刺穴一式。\n");

    if(me->query_skill("pixie-jian",1)<200)
        return notify_fail("你辟邪剑法不太熟练，不能刺人穴道。\n");

    if(me->query("neili")<200)
        return notify_fail("你内力不够，不能使出「刺穴」一式。\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("id") != "xiuhua zhen" )
/*    if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("id") != "xiuhua zhen") */
        return notify_fail("你右手没拿绣花针,无法刺敌人穴位！\n");

    if ( target->query("luding_monster") )
        return notify_fail(HIC"对方不吃这一招，看来要另想办法！\n"NOR);

    msg = HIR "$n只觉眼前有一团粉红色的物事一闪，似乎$N的身子动了一动。\n";
    me->start_busy(3);
    target->kill_ob(me);
	//agile对一招晕的判定影响
	if(target->query_temp("special_skill/agile")>1)
	{
		agile_wt=(int)(target->query_temp("special_skill/agile")/5);
		rate_level += agile_wt;
	}

    //命中率D+    
    if( F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), rate_level, me, target) )
    {
        msg += "听得铛的一声响，$p的眉心、左右太阳穴、鼻下人中四处大穴上，都是有一个细小红点，微微
有血渗出，显是$P用手中的绣花针所刺。$p张大了口，忽然身子向前直扑下去，俯伏在地，\n" NOR;
        // target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        // target->unconcious();
        yizhaoyun(target, me);
        return 1;
    }
    else    
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
    message_vision(msg, me, target);
    me->add("neili",-300);
    return 1;
}
