// File		: linhai.c
// Created By	: iszt@pkuxkx, 2007-03-21

#include <ansi.h>
#include <combat.h>
#define PFM_NAME HIG"林海剑法"NOR
#define Menpai "雪山派"
inherit F_SSERVER;

string perform_name(){ return PFM_NAME; }

int perform(object me, object target);
int perform2(object me, object target);
int perform3(object me, object target);
int remove_effect(object me);
int help(object me);

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
	object weapon;
	string msg;
	mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "xueshan-jianfa" ]),//高级技能名称
            ]);

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) 
	|| !living(target))
		return notify_fail("「"+PFM_NAME+"」只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("xueshan-jianfa", 1) < 120 )
		return notify_fail("你的雪山剑法功力太浅。\n");

	if( (int)me->query_skill("xueshan-jianfa", 1) < 200 )
		return notify_fail("你的雪山剑法功力不够，使不出「"+PFM_NAME+"」。\n");

	if( (int)me->query_skill("sword", 1) < 180 )
		return notify_fail("你的基本剑法还要多加练习才是！\n");
	if( (int)me->query_skill("xueshan-neigong", 1) < 180 )
		return notify_fail("你的雪山内功功力太浅，使不出「"+PFM_NAME+"」。\n");
		
	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("你的内力修为太浅，使不出「"+PFM_NAME+"」。\n");
	if( (int)me->query("neili") < 800 )
		return notify_fail("你的真气不够，使不出「"+PFM_NAME+"」。\n");
    	if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        	&& !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        	&& me->query_skill_mapped("force") != "xueshan-neigong" )
		return notify_fail("你真气运转方式不对，使不出「"+PFM_NAME+"」。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| weapon->query("skill_type") != "sword")
//		|| me->query_skill_mapped("sword") != "xueshan-jianfa")
		return notify_fail("你不装备一把剑，使不出「"+PFM_NAME+"」。\n");

        // comment this for sometime fight broken, the temp is not deleted. jpei
        //if( me->query_temp("linhai") )
                //return notify_fail("你正在使用「"+PFM_NAME+"」！\n");
        if(time()-me->query_temp("last_linhai") < 20)
              return notify_fail("你刚用过「"+PFM_NAME+"」，连续出招极易露出破绽！\n");

	me->set_temp("linhai",1);
	me->set_temp("last_linhai", time());
	me->start_perform(20, "「"+PFM_NAME+"」");

	me->add("neili", -me->query_skill("xueshan-jianfa", 1));
	msg = HIY"\n$N一声清啸，剑法一变，正是「"+PFM_NAME+HIY"」，令$n"
		HIY"仿佛身陷茫茫林海，手足无措！\n"NOR;
    me->set_temp("attack_val", attack_val);
	COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL, 0);
	me->add_temp("apply/sword", me->query_skill("xueshan-jianfa", 1)/2);
	if(!target->is_busy())
		target->start_busy(2);
	message_vision(msg, me, target);

	call_out("perform2", 1 , me, target);
	return 1;
}

int perform2(object me, object target)
{
	object weapon;
	string msg;
	mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "xueshan-jianfa" ]),//高级技能名称
            ]);

	if((!me && target) || (me && me->is_busy() && target))
	{
		message_vision(HIC"\n$N"HIC"不再受「"+PFM_NAME+HIC"」的影响，只觉压力顿失，轻松多了。\n"NOR, target);
		if(me)
			remove_effect(me);
		return 1;
	}
	if((me && !target) || (me && target && !me->is_fighting(target)) || (target && !living(target)))
	{
		message_vision(HIC"\n$N"HIC"「"+PFM_NAME+HIC"」使毕，剑法又回到了原先的路子上。\n"NOR, me);
		remove_effect(me);
		return 1;
	}
	if(!me && !target)
		return 1;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| weapon->query("skill_type") != "sword")
//		|| me->query_skill_mapped("sword") != "xueshan-jianfa")
	{
		message_vision(HIC"\n$N"HIC"「"+PFM_NAME+HIC"」使毕，剑法又回到了原先的路子上。\n"NOR, me);
		remove_effect(me);
		return 1;
	}

	msg =HIB "\n$N"HIB"飞快的在$n"HIB"身边旋转，圈子越转越大，可是攻势却越来越急！\n\n"NOR;
	message_vision(msg, me, target);
    me->set_temp("attack_val", attack_val);
	COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL, 0);
	if(!target->is_busy())
		target->start_busy(1);

	me->add_temp("linhai",1);
	if(me->query_temp("linhai") <= random(me->query_skill("xueshan-jianfa", 1)/100+1)+2)
		call_out("perform2", 1, me, target);
	else
		call_out("perform3", 1, me, target);
	return 1;
}

int perform3(object me, object target)
{
	object weapon;
	string msg;
	int ratio, ap, dp, damage, p;
	mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "xueshan-jianfa" ]),//高级技能名称
            ]);

	if((!me && target) || (me && me->is_busy() && target))
	{
		message_vision(HIC"\n$N"HIC"不再受「"+PFM_NAME+HIC"」的影响，只觉压力顿失，轻松多了。\n"NOR, target);
		if(me)
			remove_effect(me);
		return 1;
	}
	if((me && !target) || (me && target && !me->is_fighting(target)) || (target && !living(target)))
	{
		message_vision(HIC"\n$N"HIC"「"+PFM_NAME+HIC"」使毕，剑法又回到了原先的路子上。\n"NOR, me);
		remove_effect(me);
		return 1;
	}
	if(!me && !target)
		return 1;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| weapon->query("skill_type") != "sword")
//		|| me->query_skill_mapped("sword") != "xueshan-jianfa")
	{
		message_vision(HIC"\n$N"HIC"「"+PFM_NAME+HIC"」使毕，剑法又回到了原先的路子上。\n"NOR, me);
		remove_effect(me);
		return 1;
	}

	ratio = target->query("neili") * 100 / (target->query("max_neili")+1);
	if(ratio < 20)
	{
		msg = HIY"\n$N"HIY"看出$n"HIY"内力即将耗尽，抓住时机，刷刷刷向$n"HIY"连攻三剑！\n"NOR;
		ap = pow(me->query("neili")/150, 3)*10; //~exp/10
		dp = pow(target->query("neili")/150, 3)*10; //~exp/10
		damage = me->query_skill("force") + me->query_str()*10 - target->query_con()*10;
		if(ap < dp)
		{
			msg += MAG"不想$N"NOR+MAG"自己却也内力不继，尚且不如$n"HIG"真气充盈"NOR+MAG"，剑招颇有些软弱无力。\n"NOR;
			damage /= 2;
		}
		ap += me->query("combat_exp")/10;
		ap += pow(me->query_int()/100, 3)*10;
		ap += pow(to_float(me->query_skill("sword","xueshan-jianfa")), 3)*10;
		ap *= 2+(target->is_busy()+1);
		ap /= 2;
		dp += target->query("combat_exp")/10;
		dp += pow(target->query_dex()/100, 3)*10;
		dp += pow(to_float(target->query_skill("dodge")), 3)*10;
//C-
		if( F_KUNGFU->hit_rate( ap+dp, dp*2, 9, me, target) )
		{
			msg += RED"只听$n"NOR+RED"一声惨嚎，"HIR"三剑在$n"HIR"身上对穿而出，$n"HIR"的身上，赫然出现三个透明窟窿！\n"NOR;
			damage -= random(damage)/3*2;
			F_KUNGFU->hit_wound("qi", damage, damage, me, target);
		}
		else
		{
			msg += HIG"$n"HIG"早已看清$N"HIG"的路数，轻巧的一个转身，避开了$N"HIG"的锋芒。\n";
			if (me->query_temp("active_buffer/xueshan-jianfa.yuejian"))
			{
				me->add("neili", -200);
				me->start_busy(1);
			}
			else
			{
				me->start_busy(2);
			}
		}
		if(target->query("qi") * 100 / target->query("max_qi") < 40)
		{
			msg += HIB"此时$n"HIB"伤痕累累，「扑通」一声，双膝跪到了地上！\n"NOR;
			if(!target->is_busy())
				target->start_busy(4);
		}
		message_vision(msg, me, target);
        COMBAT_D->report_status(target);
		remove_effect(me);
		return 1;
	}
	ratio = target->query("eff_qi") * 100 / (target->query("max_qi")+1);
	if(ratio < 40)
	{
		msg = RED"\n$N"NOR+RED"见$n"NOR+RED"早露衰竭之象，更是招招进逼，每一剑都是狠辣异常！\n"NOR;
		ap = me->query_skill("sword","xueshan-jianfa")*2;
		ap /= 10;
		ap = pow(ap, 3)/10 + me->query("combat_exp");
		dp = target->query_skill("dodge") + target->query_skill("parry");
		dp /= 10;
		dp = pow(dp, 3)/10 + target->query("combat_exp");
//B-
		if( F_KUNGFU->hit_rate( ap, dp, 6, me, target) )
		{
			msg += YEL"只是$n"NOR+YEL"虽已伤痕累累，却仍沉着应对，丝毫不落下风。\n"NOR;
			me->add_temp("linhai", 1);
			message_vision(msg, me, target);
			me->set_temp("attack_val", attack_val);
			COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL, 0);
			if(me->query_temp("linhai") < random(me->query_skill("xueshan-jianfa", 1)/100+1)+4)
				call_out("perform3", 1, me, target);
			else
			{
				message_vision(HIW"\n$N"HIW"一套「"+PFM_NAME+HIW"」使毕，$n"HIW"长舒了一口气，抓住机会开始反击！\n"NOR, me, target);
				if (me->query_temp("active_buffer/xueshan-jianfa.yuejian"))
				{
					me->add("neili", -200);
					me->start_busy(1);
				}
				else
				{
					me->start_busy(2);
				}

				remove_effect(me);
			}
			return 1;
		}
		msg += HIB"$N"HIB"再也支持不住，扑通一声，双膝已经跪到了地上！\n"NOR;
		if(!target->is_busy())
			target->start_busy(4);
		message_vision(msg, me, target);
		remove_effect(me);
		return 1;
	}
	msg = HIW"$N"HIW"一套「"+PFM_NAME+HIW"」使完，$n"HIW"仍是内息悠长，见招拆招，反而渐渐占了上风！\n";
	message_vision(msg, me, target);
	if (me->query_temp("active_buffer/xueshan-jianfa.yuejian"))
	{
			me->add("neili", -200);

			if (random(7)==0)
			{
				me->start_busy(0);
				me->add("neili", -100);
			}
			else
			{
				me->start_busy(1);
			}
	}
	else
	{
		me->start_busy(1+random(4));
	}
	remove_effect(me);
	return 1;
}

int remove_effect(object me)
{
	me->add_temp("apply/sword", -me->query_skill("xueshan-jianfa", 1)/2);
	me->delete_temp("linhai");
	return 1;
}

int help(object me)
{
	write(WHT"\n雪山剑法之「"+PFM_NAME+WHT"」："NOR"\n");
	write(@HELP
	雪山之上，林海莽莽，凌霄城前人有感于林海之终年常青、茫茫无边，创制
	了这套「林海剑法」。在与人争斗之时，使出「林海剑法」之人往往将对手
	在数招之内制住，一方面说明这套剑法效用之大，另一方面也是因为它通常
	适用于对手接近精疲力尽之时。雪山弟子须切记这点。

	要求：  内力 900 以上；
		最大内力 1500 以上；
		基本剑法等级 130 以上；
		雪山剑法等级 130 以上；
		冰雪心法等级 100 以上；
		且使用雪山剑法。
HELP
        );
        return 1;
}
