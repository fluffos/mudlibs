// feilong.c 华山剑法「天外飞龙」

#include <ansi.h>
inherit F_SSERVER;
inherit YIZHAOYUN;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me,object target)
{
    string msg;
    int ap,dp,bt,damage,agile_wt,pflv,rate=9-random(2);
	object weapon;

    if ( !me->query("huashan_newskills/jianzong") ||
         me->query("family/family_name")!="华山派" ) 
			{
				if (!me->query("safari_skill/hs_jq"))
				{
					return notify_fail("这是华山剑宗的秘传绝学，你无法在实战中运用「天外飞龙」。\n");
				}
			}
    if ( !me->query("feilong")) return notify_fail("你的外功中没有这项技能。\n");

    if ( !target ) target = offensive_target(me);

    if ( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「天外飞龙」只能对战斗中的对手使用。\n");
    
	weapon = me->query_temp("weapon");
    if ( !objectp(weapon) || weapon->query("skill_type") != "sword" )
        return notify_fail("你手中无剑怎能使用天外飞龙？！\n");

    if ( (int)me->query_skill("huashan-jianfa",1) < 100 )
        return notify_fail("你的华山剑法不够娴熟，不会使用「天外飞龙」。\n");

    if ( (int)me->query_skill("huashan-neigong",1) < 100 )
        return notify_fail("你的华山内功等级不够，无法使用「天外飞龙」这招。\n");

    if( (int)me->query("neili",1) < 300 )
        return notify_fail("你的内力不够，不能使用「天外飞龙」。\n");

    if ( target->query("luding_monster"))
        return notify_fail(HIC"对方不吃这一招，看来要另想办法！\n"NOR);
    
    if( me->query_temp("no_feilong") > time() )
			return notify_fail("你不能连续使用「天外飞龙」！\n");
    
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "华山派")	pflv = 0;
	if (pflv>=5) rate -= 2;

    me->set_temp("no_feilong", time()+6);
	//舞到酣处，剑气如虹，势若雷霆，真有气吞河岳之概，两仪剑法六十四招使完，只听他一声断喝，双剑脱手飞出，插入屋顶巨梁，直没剑柄。这一//记“天外飞龙”，却是华山派穆人清的绝招。
    msg = HIC "$N"+HIC+"剑气如虹，势若雷霆，真有气吞河岳之概，只听一声断喝，" + weapon->query("name") + HIC "如电般脱手飞出！\n\n"NOR;
/*	if (me->query("huashan_newskills/jianzong"))
	rate-=random(2);//剑宗有可能命中提升。*/
    bt = me->query("betrayer");
    if ( bt<0 )
    	bt=0;
    me->start_busy(1);
    me->add("neili",-300);
    ap=me->query_skill("sword", "huashan-jianfa");
    ap=ap/10;
    ap=ap*ap*ap*5/6;
    ap=ap+me->query("combat_exp")/100;
    
    dp=target->query_skill("parry")+target->query_skill("dodge");
    dp=dp/20;
    dp=dp*dp*dp*5/6;
    dp=dp+target->query("combat_exp")/100;
    if(target->query_temp("special_skill/agile")>1)
	{
		agile_wt=(int)(target->query_temp("special_skill/agile")/5);
		rate += agile_wt;
	}
	rate += 6*bt;
/*	if (rate>18)
	{
		rate=18;
	}//似乎不用判定，在kungfu.c里面有判断
*/
    if( F_KUNGFU->hit_rate( ap+dp, 2*dp, rate, me, target ) && 
    	  random(4) && me->query("level") >= target->query("level")*2/3 ) 
    {
        msg += HIR+"$p"+HIR+"已被这天马行空的一剑震慑得目瞪口呆，三尺青锋竟透胸而过直没至柄。\n"+HIR +"这一记“天外飞龙”，却是华山派穆人清的绝招。\n\n" NOR;
        message_vision(msg, me, target);
        if (!target->query("boss"))//不许对boss使用飞龙
        {
			if (!me->query("env/no_feilong_annex"))
			{
				damage=me->query_skill("huashan-jianfa",1)+me->query_skill("huashan-neigong",1);
				damage=damage+random(damage);
				if ( damage>6000 )
				damage=6000;
				F_KUNGFU->hit_wound("qi", damage, damage, me, target);
				COMBAT_D->report_status(target);
			}
            yizhaoyun(target, me);
        }
    } 
    else 
    {
        if ( F_KUNGFU->hit_rate( ap+dp, 2*dp, 9+6*bt, me, target ) && !me->query("env/no_feilong_annex"))
        { 
            damage=me->query_skill("huashan-jianfa",1)+me->query_skill("huashan-neigong",1);
            damage=damage/2+random(damage);
            if ( damage>4000 )
              damage=4000;
            F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
            msg += HIC"$p不惶多想，凭借身经百战的本能身形疾转，生生让开了来势，\n冰冷的剑锋划裂衣衫砭肤而过，只消少许迟缓便是开膛破肚之祸。\n$p不禁出了一身冷汗，心中暗道：莫非这就是传说中穆人清老爷子的天外飞龙？不想竟然霸道至斯！\n\n" NOR;
            message_vision(msg, me, target);
            COMBAT_D->report_status(target);
        }
        else
        { 
          msg += HIC"危急中$p已经想不起任何一招能够低挡，只得横心闭眼全力上格。\n“当”的一声，火花四溅，$p双臂发麻，全身乏力只想躺倒睡去。\n这一挡却也保住了自己性命，$p不由得暗自想到“侥幸侥幸”！\n\n"NOR;
          message_vision(msg, me, target);
        }
        me->start_busy(2+random(3));
    }
	message_vision(HIC "$N" HIC "身形紧随而上，探手在剑锷上一拨一提，在$n" 
		+ HIC "反应过来之前，将" + weapon->query("name") + HIC "握回掌中。\n"NOR, me, target);
    return 1;
}

