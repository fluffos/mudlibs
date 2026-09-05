// chuanxin.c 抽髓掌穿心诀
// By Zine Nov 6 2010 //配合10分钟才能要到一次的一种暗器，穿心钉，此pfm本身没有太大威力，配合穿心钉后限制使用pfm。

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

void cooldown(object me)
{
    if (!objectp(me)) return;
    me->delete_temp("chuanxin"); 
}

int perform(object me, object target)
{
	string msg;
    int i=1;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("穿心诀只能对战斗中的对手使用。。\n");

	if( me->query_temp("chuanxin"))
		return notify_fail("你刚刚使用过穿心诀，消耗甚巨，暂时无法再次使用。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( (int)target->query("combat_exp") < (int)me->query("combat_exp")/4 )
		return notify_fail("穿心诀星宿神技，杀鸡岂用牛刀？\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 100 )
		return notify_fail("你的化功大法不够娴熟，施展不了穿心诀。\n");

	if( (int)me->query_skill("xingxiu-duzhang", 1) < 100 )
		return notify_fail("你的星宿毒掌不够娴熟，施展不了穿心诀。\n");

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
         (int)me->query_skill("xingxiu-duzhang", 1) > 199 && (me->query("newbiediaoyu") || me->query("newbie_hongdou")) )
        return notify_fail("因为你早年不听从师门教诲，师门没有传授你穿心诀的秘密。\n");

	msg = HIR "只听得$N默念心法，瞬时，$N的掌心变成血红色，一掌拍向$n胸前七处大穴。\n";

	me->start_busy(1);

    //命中率级别是B/2+B-/2
    if ( me->query_skill("xingxiu-duzhang",1)>400 && target->query_condition("chuanxin") && 
         F_KUNGFU->hit_rate((int)me->query_skill("xingxiu-duzhang",1), target->query_skill("dodge",1), 5+random(2), me, target ) )
    {
        target->apply_condition("chuanxin", 0);
        target->apply_condition("pfmnotallow", me->query_skill("xingxiu-duzhang",1)/20);
        tell_object(me,HIW"放胆进攻吧，被你的穿心诀打入体内，他已经无法施展特殊攻击。\n"NOR);
        i=2;
        if (random(100)>49 && me->query_skill("poison",1)>400)
        {
			F_POISON->poison_attack(me,target,"xx-poison-palsy2",me->query_skill("xingxiu-duzhang",1)/30+1);
            tell_object(me,HIW"你的穿心诀打入他体内，在他经脉中不停游走。\n"NOR);
        }
        target->set_temp("pfmnotallow",1);
        tell_object(target,HIC"你惊喜地发现体内穿心钉的创伤竟不药而愈了！\n"NOR);
    }

    //命中率级别是B-/2+C+/2
	if( F_KUNGFU->hit_rate((int)me->query_skill("xingxiu-duzhang",1), target->query_skill("dodge",1), 6+random(2), me, target ) ) 
    {
		    msg += CYN " 结果$p猝不及防，被$P双掌印了个正着！\n" NOR;
		    F_KUNGFU->hit_wound("qi", random(me->query_skill("xingxiu-duzhang",1)), random(me->query_skill("xingxiu-duzhang",1))+random(me->query_skill("poison",1)), me, target);
    		message_combatd(msg, me,target);
		    COMBAT_D->report_status(target);
  	}
    else 
    {
		msg += "可是$p急提内力奋力一震，将$N的手震了开去。\n" NOR;
		me->start_busy(random(3));
		message_combatd(msg, me,target);
	}
    me->set_temp("chuanxin",1);
    if (i==2)
    {
        call_out("cooldown", (me->query("str"))/3, me);
    }
    if (i==1)
    {
        call_out("cooldown", (50-(me->query("con")))/4, me);
    }
	return 1;
}
