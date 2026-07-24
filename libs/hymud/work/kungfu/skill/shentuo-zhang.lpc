// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shentuo-zhang 神驼雪山掌

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N双臂一舒，使出一招「明驼西来」，身形旋转，掌势飘忽，击向$n的$l",
        "$N身形向后一错，左掌阴势，右掌阳型，使出一式「大漠冰扬」，拍向$n的$l",
        "$N弹腿飞身，步法阴阳互易，若有若无的踢向$n的$l，正是一招「灵驼骏足」",
        "$N身形飞旋，一式「万里飞霜」，掌影纷飞，掌上内劲已把$n的上盘统统罩住",
        "$N身形急转，半空中一招「神驼冲霄」，头下脚上，刹那间手脚齐攻，击向$n的$l",
        "$N掌势一缓，使出一式「雪锁千山」，掌上阴劲如怒涛汹涌，缓缓推向$n的$l",
"$N一式「灵蛇出洞」，右手虚晃，左手扬起，突然拍向$n的背后二穴",
"$N侧身一晃，一式「虎头蛇尾」，左手拿向$n的肩头，右拳打向$n的胸口",
"$N一式「画蛇添足」，右手环拢成爪，一出手就向扣$n的咽喉要害",
"$N左手虚招，右掌直立，一式「杯弓蛇影」，错步飘出，疾拍$n的面门",
"$N使一式「蛇行鼠窜」，左拳上格，右手探底突出，抓向$n的裆部",
"$N一式「蛇磐青竹」，十指伸缩，虚虚实实地袭向$n的全身要穴",
"$N双手抱拳，一式「万蛇汹涌」，掌影翻飞，同时向$n施出九九八十一招",
"$N一式「白蛇吐信」，拳招若隐若现，若有若无，急急地拍向$n的丹田",
});


int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }

 int valid_combine(string combo) { return combo == "shexing-diaoshou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练神驼雪山掌必须空手。\n");

        if ((int)me->query_skill("hamagong",1) < 15)
                return notify_fail("你的蛤蟆功火候不够，无法学神驼雪山掌。\n");

        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力太弱，无法练神驼雪山掌。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(60), 
                "attack": 50 + random(10), 
                "dodge" : 50 + random(10), 
                "parry" : 50 + random(10), 
                	"damage" : 150 + random(150), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练神驼雪山掌。\n");
        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shentuo-zhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;
target=victim;
        level = (int) me->query_skill("hamagong",1);
        level2= (int) me->query_skill("hamagong",1);
damage2= (int) victim->query("neili",1)/8;





        if(  me->query("jiali") > me->query_skill("force") 
          && me->query_skill_mapped("force") == "hamagong") 

if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("shentuo-zhang",1)) > 150  || random(8)==0) 
{
	  victim->receive_wound("qi", damage_bonus/2+30);
        return HIR "$N掌上阴劲如怒涛汹涌，缓缓推向$n，$n的胸口肋骨竟然断了几根！\n" NOR;
}


if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "hamagong")
{
	target->apply_condition("snake_poison",5);
	target->apply_condition("chanchu_poison",5);
	target->apply_condition("qx_snake_poison",3);
if (!target->is_busy()) target->start_busy(2);
	
 return HIR "$N倒转经脉，身形一变，一口毒气对着$n吐出!$n头一昏，不知所措 ！\n";
}
	if( damage_bonus < 100 ) return 0;



if (me->query_temp("hmg_dzjm") && random(4)>2 )
{
        victim->receive_damage("qi", damage_bonus/2);
        victim->receive_wound("qi", damage_bonus/2);
 return HIR "$N倒转经脉对着$n张口一咬!$n伤口一凉，鲜血喷出！\n";
}
	if( damage_bonus/2 > victim->query_str() || random(5)==0 ) {
if(me->query_skill("hamagong", 1)>100)
{
if (me->query_skill_mapped("force") == "hamagong"
&& !me->query_temp("weapon"))
{
		victim->receive_wound("qi", (damage_bonus ) / 2 );
		return HIM " "+ victim->name()+"喘息未定，又觉一股劲风扑面而来,吐出了一大口鲜血！\n" NOR;
}
}
	}
}

