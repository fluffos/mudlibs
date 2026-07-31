// wang.c 银索金铃「天罗地网」
#include <ansi.h>
#include <combat.h> 
inherit SSERVER;
inherit F_CLEAN_UP;

int checking(object me, object target, object weapon);

string *number_msg = ({"一","二","三","四","五","六","七","八","九","十","十数","千百","无数"});
string *whip_msg = ({"反撩","斜刺","轻挥","轻抖","漫舞","直劈","后拉","前推"});

string *chan_msg = ({
CYN"$N以意御鞭，$S舞出$R个"RED"圆圈"CYN"，其千变万化，无穷无尽，要去包裹缠住$n！\n" NOR,
CYN"$N以意御鞭，$S舞出$R个"RED"圆圈"CYN"，前后排列，要将$n包裹起来！\n" NOR,
CYN"$N心中不存半点渣滓，以意御鞭，$W"CYN"每发一招，便似放出一条"RED"细丝"CYN"，要去缠住$n！\n"NOR,
CYN"$N以意御鞭，$S舞出$R个"RED"圆圈"CYN"，正反相交，要将$n缠在正中！\n" NOR,
CYN"$N手中$W"CYN"挥动，驱银索金铃散发出根根"RED"细丝"CYN"，要将$n裹起来！\n"NOR,
CYN"$N以意御鞭，$S舞出$R个"RED"圆圈"CYN"，上下包容，要将$n包裹起来！\n" NOR,
CYN"$N的一柄$W"CYN"舞着一个个"RED"圆圈"CYN"，每一招均是以弧形刺出，以弧形收回，缠住$n！\n"NOR,
CYN"$N以意御鞭，$S舞出$R个"RED"圆圈"CYN"，左右兼顾，要将$n缠在正中！\n" NOR,
});

string *dodged = ({
HIY"可是$n已然看穿了$P的招数，孤注一掷直入圈心，破了$N的绵绵鞭意！\n\n" NOR,
HIY"$n微觉$N招数涩滞，急忙变招，竭尽全身之力中宫疾进，从银丝圈中冲了出去！\n\n"NOR,
HIY"$n微觉$N招数涩滞，急忙变招，竭尽全身之力飞跃后退，远离了鞭网！\n\n"NOR,
HIY"$n看得真切，回招挡格了$N中宫一剑，接着纵身一跃，已逃出圈外。\n\n"NOR,
});

string *chaned = ({
HIW"结果$n的招数渐见涩滞，偶尔发出一招，真气运得不足，便被$W"HIW"带着连转几个圈子。\n"NOR,
HIW"结果银索金铃散发出的细丝越积越多，似是积成了一团团丝棉，将$n紧紧裹了起来！\n"NOR,
HIW"结果，银索金铃似是积成了一团团丝棉，将$n紧紧裹了起来！\n"NOR,
HIW"$n越斗越是害怕，一个疏忽，被银索金铃紧紧裹了起来！\n"NOR,
});

void remove_effect(object me)
{
	if( !me )	return;
	me->delete_temp("pfm_action");
	me->set_temp("psd_wang_end",time());
	me->delete_temp("psd_wang");
	message_vision(HIW"$N"HIW"收起了银线。\n"NOR,me);
}

varargs void wang(object me,object target,object weapon,int damage)
{
	string msg;
	int ap,dp;
        if( !me || !living(me) )
                return;
	me->add_temp("psd_wang",-1-random(10));
	if( me->query_temp("psd_wang")<=0 )
	{
		remove_effect(me);
		return;
	}
	if( !weapon || weapon!=me->query_temp("weapon") )
		weapon = me->query_temp("weapon");
	if( !weapon 
    	 || ( weapon->query("skill_type") != "whip" 
    	   && weapon->query("use_apply_skill") != "whip" ) )
	{
		remove_effect(me);
		return;
	}
	if( !target )  target = offensive_target(me);
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me 
 	 || !me->is_fighting(target) 
 	 || !living(me) )
		return; 
	if( time()<me->query_temp("last_pfm_action")+1 )
		return;
	me->set_temp("last_pfm_action",time());			
	if( me->query("force")<50 )
	{
		remove_effect(me);
		return;
	}
	msg = chan_msg[random(sizeof(chan_msg))];
        msg = replace_string(msg, "$S", whip_msg[random(sizeof(whip_msg))]);
        msg = replace_string(msg, "$R", number_msg[random(sizeof(number_msg))]);
	msg = replace_string(msg, "$W", weapon->name());
	msg = COLOR_D->clean_color(msg);
	msg = COLOR_D->replace_color(HIW+msg,2)+NOR;
	message_combatd(msg,me,target);
	ap = COMBAT_D->skill_power(me,"yinsuo-jinling",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE)*2/3;
	if( random(ap+dp)>=dp )
	{
		me->add_temp("psd_wang",-3);
		msg = chaned[random(sizeof(chaned))];
	        msg = replace_string(msg, "$S", whip_msg[random(sizeof(whip_msg))]);
        	msg = replace_string(msg, "$R", number_msg[random(sizeof(number_msg))]);
		msg = replace_string(msg, "$W", weapon->name());
		msg = COLOR_D->clean_color(msg);
		msg = COLOR_D->replace_color(HIW+msg,2)+NOR;
		message_combatd(msg,me,target);
		target->start_busy((int)target->query_busy()+1);
	}	
	else	
	{
		me->add_temp("psd_wang",-5);
		msg = dodged[random(sizeof(dodged))];
		msg = COLOR_D->clean_color(msg);
		msg = COLOR_D->replace_color(HIW+msg,2)+NOR;
		message_combatd(msg,me,target);
	}
}

int perform(object me, object target)
{
	string msg,succ_msg;
        object weapon;
        int damage,t;

	if( me->query_level()<25 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="盘丝洞")
		return notify_fail("“天罗地网”只有盘丝洞门人才可以用！\n"); 
        if( (int)me->query_skill("yinsuo-jinling", 1) <250 )
                return notify_fail("你的银索金铃极不够娴熟，不要丢人现眼了。\n");
        if( me->query("force") < 800 )
                return notify_fail("你的内力不够！\n");
        if(me->query_skill_mapped("whip") != "yinsuo-jinling")
		return notify_fail("你现在无法使用「天罗地网」。\n");
	if( (int)me->query_skill("pansi-dafa", 1) < 200 )
        	return notify_fail("你的盘丝大法修为不够，不能把手中兵器化作「天罗地网」。\n");
	if( time()<me->query_temp("psd_wang_end")+6 )
		return notify_fail("你不能频繁使用「天罗地网」。\n");        	
	if( me->query_skill_mapped("force") != "jiuyin-xinjing")
        	return notify_fail("你所用的内功与银索金铃意气相悖！\n");
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("「天罗地网」只能对战斗中的对手使用。\n");
	if(!living(target) || target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
	weapon = me->query_temp("weapon");
	if( !weapon 
    	 || ( weapon->query("skill_type") != "whip" 
    	   && weapon->query("use_apply_skill") != "whip" ) )
                return notify_fail("你手中无鞭，如何使得「天罗地网」？\n");
        if( me->query_temp("pfm_action") || me->query_temp("psd_wang") )
                return notify_fail("你正在使用「天罗地网」。\n");

	t = me->query_skill("whip");
	t = t/5+random(t/5);
        me->add("force", -200);
	msg = HIW"\n$N"HIW"默运盘丝大法,但见手中一根根银丝从$w"HIW"慢慢飘起,在空中着一圈圈卷着，绵绵不绝，便如撒出了一张大网，逐步向$n"HIW"收紧！\n"NOR;
	succ_msg = HIW"$n"HIW"一不留神被网个正着,脱身不的。\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_combatd(HIW"可是$n"HIW"看破了$n"HIW"的企图，并没有上当。\n" NOR, me, target);
		t = t/2+1;
	}
	else	target->start_busy(3);
	me->set_temp("psd_wang",t);
	me->set_temp("pfm_action", (: call_other, __FILE__, "wang" :));	
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：天罗地网
        外功所属：银索金玲
        外功效果：使自身进入天罗地网状态，该状态下攻击会附带使
        	  对方busy的效果
                  状态结束后冷却6秒
                  不支持非鞭类型的武器
                  不能对busy状态下的敌方使用
        外功条件：
                  盘丝洞弟子
        	  人物等级25级
                  内力800点，消耗200点
                  银索金铃250级并激发
                  盘丝大法200级
                  激发九阴心经
STR;
        me->start_more(str);
        return 1;
}

void remove()
{
	int i;
	object me,*usr = users();
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("psd_wang") )
			{
				me = usr[i];
				me->delete_temp("pfm_action");
				me->set_temp("psd_wang_end",time());
				me->delete_temp("psd_wang");
				message_vision(HIW"$N"HIW"收起了银线。\n"NOR,me);
			}
		}
	}
}