//leiting.c -雷霆降龙

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
    int rate_level;
	int agile_wt;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「雷霆降龙」只能对战斗中的对手使用。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        !me->query("leiting") )
        return notify_fail("你的外功中没有这种功能。\n");

    if ( base_name(environment(me))[0..10] == "/d/changbai" )
        return notify_fail("什么？\n");

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
         me->query_skill_mapped("force") != "huntian-qigong" )
            return notify_fail("你所使用的内功不对。\n");

    if ( me->query_skill("force",1)/2 + me->query_skill("huntian-qigong",1) < 135 )
        return notify_fail("你的内功等级不够，无法施展「雷霆降龙」。");

    if ( me->query_skill("strike",1)/2 + me->query_skill("xianglong-zhang", 1) < 135 )
        return notify_fail("你的降龙十八掌等级不够，施展不出「雷霆降龙」。\n");

    if ( me->query("neili")<200 || me->query("max_neili")<200 )
        return notify_fail("你的内力不够，无法施展「雷霆降龙」。");

    if ( target->query("luding_monster"))
        return notify_fail(HIC"对方不吃这一招，看来要另想办法！\n"NOR);

    msg = HIC+"$N默运混天气功，施展出「" + HIW + "雷" + HIC + "霆" + HIR + "降龙」" 
        + HIC + "，全身急速转动起来，越来越快，就犹如一股旋风\n骤然间，已卷向正看得发呆的$n。\n"+NOR;
    me->start_busy(3);
   
   if ( me->query("combat_exp")<1000000 && target->query("combat_exp")<1500000 )
     rate_level=12+random(4);
   else if ( me->query("combat_exp")<3000000 && target->query("combat_exp")<5000000 )
     rate_level=15+random(3);
   else
     rate_level=17;
//player_special_contribute/gb是alucar获得的提供丐帮任务素材的特殊奖励，by Zine 2011/07/23 
	if (me->query("player_special_contribute/gb"))
	{
    if ( me->query("family/family_name")=="丐帮" && !me->query("chushi/done"))
     rate_level-=6;
	}
	else
	{
		rate_level-=4;
	}
   //纯丐帮提升加强，命中为5
   if(target->query_temp("special_skill/agile")>1)
	{
		agile_wt=(int)(target->query_temp("special_skill/agile")/5);
		rate_level += agile_wt;
	}
	//agile特技修正
   if ( rate_level< 11 )
     rate_level=11;

//低经验环境下雷霆有较高命中率，从D-到F级演化，F级为最低命中率级别   
   if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), rate_level, me, target) ) 
       {
        msg += HIR + "$n只见一阵旋风影中陡然现出$N的双掌，根本来不及躲避，\n" + 
            "被重重击中，五脏六腑翻腾不休，口中鲜血如箭般喷出！！！\n" NOR;
        message_vision(msg, me, target);
        // target->set_temp("last_damage_from", me);
        // target->unconcious();
        yizhaoyun(target, me);
    } else {
        msg += HIG"可是$p还是躲过了$P的最后一击！！\n" NOR;
        message_vision(msg, me, target);
        me->set("neili",(me->query("neili")-200));
    }
    return 1;
}
