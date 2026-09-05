// taiji-quan.c 太极拳
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「揽雀尾」，双手划了个半圈，按向$n的$l",
	"force" : 150,
	"dodge" : 30,
	"skill_name" : "揽雀尾",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚按，右手使一招「白蛇吐信」，向$n的$l插去",
	"force" : 250,
	"dodge" : 25,
	"skill_name" : "白蛇吐信",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手握拳，向前向后划弧，一招「双风贯耳」打向$n的$l",
	"force" : 300,
	"dodge" : 20,
	"skill_name" : "双风贯耳",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚划，右手一记「指裆锤」击向$n的裆部",
	"force" : 320,
	"dodge" : 15,
	"skill_name" : "指裆锤",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N施出「伏虎式」，右手击向$n的$l，左手攻向$n的裆部",
	"force" : 370,
	"dodge" : 10,
	"skill_name" : "伏虎式",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="taiji-zhao"|| combo=="taiji-claw"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练太极拳必须空手。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("你的太极神功火候不够，无法学太极拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练太极拳。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练太极拳。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
	"$n左手轻轻推出，拍向$N的$w，然后身体向右一侧，顺势后拉，$N就象打在一团棉絮中，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

// 修改沾衣十八跌为知识类之后，激发太极拳为招架可获得原先沾衣十八跌的BUFF效果。
mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int level;
    
    if ( ob->query("family/family_name") != "武当派" )
    {
      buf=([]);
      ob->delete_temp("zhanyi-18die");
      return buf;
    }
	
	if (ob->query_skill_mapped("parry")!="taiji-quan" || mapp(ob->query_temp("zhanyi-18die")) )
      return buf;
    
    level=ob->query_skill("zhanyi-18die",1);
	if (level <=0)  return buf;
	
    buf=([]);
	if(ob->query("chushi/done") || ob->query("betrayer"))
	{
		buf["parry_factor"]=1+level/300;
		if ( buf["parry_factor"]>8 )
			buf["parry_factor"]=8;
		buf["week_injure"]=1+level/600;
		if ( buf["week_injure"]>4 )
			buf["week_injure"]=4;
	}
	else
	{
		buf["parry_factor"]=1+level/150;
		if ( buf["parry_factor"]>16 )
			buf["parry_factor"]=16;
		buf["week_injure"]=1+level/300;
		if ( buf["week_injure"]>8 )
			buf["week_injure"]=8;
	}
/*    buf["dodge_factor"]=-1-level/200;
    if ( buf["dodge_factor"]<-11 )
      buf["dodge_factor"]=-11; */
//去除门派限制。enable 武功不应该纳入 perform buff 限制
/*    if ( mapp(tbuf=ob->query_temp("active_buffer")) &&
         sizeof(tbuf)>1 &&
         stringp(tbuf["family"]) &&
         tbuf["family"]!="武当派" &&
         tbuf["family"]!="公共武学" )
    {
      buf=([]);
      ob->delete_temp("zhanyi-18die");
      return buf;
    }
*/
    ob->set_temp("zhanyi-18die", buf);
    ob->set_temp("active_buffer/family","武当派");
    ob->set_temp("active_buffer/zhanyi-18die/name", "沾衣十八跌");                       //buff名称
    ob->set_temp("active_buffer/zhanyi-18die/effect1", "招架+"+(buf["parry_factor"])+"%");     //效果描述1
//    ob->set_temp("active_buffer/zhanyi-18die/effect2", "躲闪命中"+(buf["dodge_factor"])+"%");     //效果描述2
    ob->set_temp("active_buffer/zhanyi-18die/effect2", "普通伤害抗性+"+(buf["week_injure"])+"%");     //效果描述3
    return buf;
}

mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("zhanyi-18die");
    if ( mapp(buf) && ( ob->query("family/family_name") != "武当派" || ob->query_skill_mapped("parry")!="taiji-quan"
			|| ob->query_skill("zhanyi-18die",1)<=0 ) )
	{
		buf["parry_factor"]=buf["parry_factor"]*(-1);
		buf["dodge_factor"]=buf["dodge_factor"]*(-1);
		buf["week_injure"]=buf["week_injure"]*(-1);
		ob->delete_temp("zhanyi-18die");
		ob->delete_temp("active_buffer/zhanyi-18die");
	}
    else
      buf=([]);
    return buf;
}

void check_mianlizhen(object me, object target, int pflv, int ap, int dp, int t)
{
	int damage, neili, dlv, rt=0;
	string msg;
	object *enemy;
	if (t>=3 && random(26)<=t*t)
	{
		damage = (int)me->query_temp("taiji_mianlizhen/damage");
		if (pflv<5)
			me->delete_temp("taiji_mianlizhen");
		else
		{
			me->set_temp("taiji_mianlizhen/damage", damage/10+random(damage/20));
			me->set_temp("taiji_mianlizhen/times", 0);
		}
		neili = me->query_skill("taiji-shengong",1) / 2;
		if (neili>(damage/5)) neili = damage / 5;
		if (pflv>=4)
			neili -= neili*(2*pflv-7)/6;
		msg = HIR"\n$N运转太极神功「绵里针」心法，一拒一迎，将积蓄已久的力道尽行碰了回去！\n"NOR;
		if (me->query("neili") < neili )
		{
			msg += HIY "$n急忙运劲相抵，两下里一碰，嘭的一声如击败革，各退了半步，谁也没占到便宜。\n\n" NOR;
			if (!me->is_busy()) me->start_busy(1);
			if (!target->is_busy())	target->start_busy(1);
			me->add("neili", -1*neili/10);
			message_vision(msg, me, target);
		}
		else
		{
			dlv = me->query_skill("zhanyi-18die", 1);
			if (dlv>0)
				damage += dlv + random(dlv);
			if (pflv>=4)
				damage += damage*(2*pflv-7)/20;
			if(me->query("safari_skill/wd_taiji"))
				damage += damage/5;
			if (F_KUNGFU->hit_rate(ap, dp, 10-pflv, me, target))
			{
				msg += HIR"$n大叫一声，身子犹似发石机射出的一块大石，倒飞出去三丈远！\n"NOR;
				rt = 1;
			}
			else 
			{
				damage /= 2;
				msg += HIM"$n胸口如遭重锤，闷哼了一声，噔噔噔连退了三大步！\n"NOR;
			}
			me->add("neili", -1*neili);
			if (!target->is_busy()) target->start_busy(1);
        	target->receive_damage("qi", damage, me);
        	target->receive_wound("qi", damage/2, me);
			message_vision(msg, me, target);
			COMBAT_D->report_status(target);
			if (rt && pflv>=5 && random(2))
			{
				enemy = me->query_enemy();
				enemy -= ({ target });
				if (sizeof(enemy)>1)
				{
					msg = RED "$n闪躲不及，砰的一下被飞来的$N撞个正着，摔成了两个滚地葫芦。\n" NOR;
					damage -= random(damage/2);
					rt = random(sizeof(enemy));
					if (!enemy[rt]->is_busy()) enemy[rt]->start_busy(1);
					enemy[rt]->receive_damage("qi", damage, me);
					enemy[rt]->receive_wound("qi", damage/2, me);
					message_vision(msg, target, enemy[rt]);
					COMBAT_D->report_status(enemy[rt]);
				}
			}
		}		
	}
}

int after_parry(object me, object target, string attack_skill)
{
	int ap, dp, point, pflv, last, now, t;
	string msg, martial_skill;
	mapping action;
	
	if (!objectp(me) || !objectp(target)) 
		return 0;
	if ((int)me->query("neili")<100) return 0;
	pflv = (int)me->query("purefamily/level");
	if (pflv>=3 && me->query("purefamily/family_name") == "武当派" && me->query_skill_mapped("force") == "taiji-shengong")// 入室弟子 特效
	{
		ap = (int)me->query_skill("force", "taiji-shengong");
		dp = (int)target->query_skill("force");
		if (pflv>5) pflv=5;
		if (F_KUNGFU->hit_rate(ap, dp, 10-pflv, me, target)) 
		{
			now = time();
			msg = HIC "$N松腰垂臀、沉肩坠肘，双手一圈，如抱太极，$n顿觉犹如打在了一团棉絮上，全然无处受力。\n" NOR;
			martial_skill = target->query_skill_mapped(attack_skill);
			action = SKILL_D(martial_skill)->query_action(target, target->query_temp("weapon"));
			if (mapp(action))
				point = action["damage"];
			else 
				point = 100;
			point += (int)target->query_temp("apply/damage") + target->query_str();
			last = (int)me->query_temp("taiji_mianlizhen/last_time");
			if ((now-last)<=(6+(pflv-3)*4))
			{
				me->add_temp("taiji_mianlizhen/damage", point);
				t = (int)me->query_temp("taiji_mianlizhen/times") + 1;
			}
			else
			{
				me->set_temp("taiji_mianlizhen/damage", point);
				t = 1;
			}
			me->set_temp("taiji_mianlizhen/times", t);
			me->set_temp("taiji_mianlizhen/last_time", now);
			message_vision(msg, me, target);
			check_mianlizhen(me, target, pflv, ap, dp, t);
		}
	}
	return 1;
}

mixed absorb(int ap,int pp,object attacker,object defender,int damage,object weapon)
{
	int pflv, last;
	string msg;
	if(!objectp(attacker) || !objectp(defender)) return 0;
	if ((int)defender->query("neili")<100) return -1;
	pflv = (int)defender->query("purefamily/level");
	if (living(defender) && pflv>=3 && defender->query("purefamily/family_name") == "武当派" && defender->query_skill_mapped("force") == "taiji-shengong")// 入室弟子 特效
	{
		if (pflv>5) pflv=5;
		if (F_KUNGFU->hit_rate(pp, ap, 10-pflv, defender, attacker)) 
		{
			msg = HIM "$N松腰垂臀、沉肩坠肘，双手一圈，如抱太极，$n顿觉犹如打在了一团棉絮上，全然无处受力。\n" NOR;
			last = (int)defender->query_temp("taiji_mianlizhen/last_time");
			if ((time()-last)<=(6+(pflv-3)*4))
			{
				if ((int)defender->query_temp("taiji_mianlizhen/times")>=5)
					damage /= 10;
				defender->add_temp("taiji_mianlizhen/damage", damage);
				defender->add_temp("taiji_mianlizhen/times", 1);
			}
			else
			{
				defender->set_temp("taiji_mianlizhen/damage", damage);
				defender->set_temp("taiji_mianlizhen/times", 1);
			}
			defender->set_temp("taiji_mianlizhen/last_time", time());
			message_vision(msg, defender, attacker);
//			check_mianlizhen(defender, attacker, pflv);
		}
	}
	return -1;
}
