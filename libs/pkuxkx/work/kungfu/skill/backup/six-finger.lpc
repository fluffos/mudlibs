// six-fingers.c 六脉神剑
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([ "name":   "少商剑",
           "action": "$N反过手来，双手拇指同时捺出，嗤嗤两声急响，“少商剑”
有如石破天惊、风雨大至之势，分指$n膻中和$l",
           "force":  350,
           "dodge":  50,
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "商阳剑",
           "action": "$N食指连动，手腕园转，“商阳剑”一剑又一剑的刺出，轻灵
迅速，奇巧活泼，剑气纵横，$n根本无法看清来路",
           "force":  400,
           "dodge":  100,
           "damage": 400,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "中冲剑",
           "action": "$N右手中指一竖，“中冲剑”向前刺出。真气鼓荡，嗤然声响，
无形剑气直指$n的$l",
           "force":  350,
           "dodge":  40,
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "关冲剑",
           "action": "$N右手无名指伸出，“关冲剑”剑路拙滞古朴，一股雄浑的内
力鼓荡而出，如排山倒海般向$n涌去",
           "force":  350,
           "dodge":  60,
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "少泽剑",
           "action": "$N左手小指一伸，一条气流从少冲穴中激射而出，“少泽剑”
出手入风，指向$n的$l",
           "force":  350,
           "dodge":  50,                            
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "少冲剑",
           "action": "$N右手反指，小指伸出，真气自少冲穴激荡而出，“少泽剑”
横生奇变，从$n意想不到的方向刺向$n的$l",
           "force":  350,
           "dodge":  40,
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
});


int valid_enable(string usage) { return usage=="finger" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("练六脉神剑必须空手。\n");
        if ((int)me->query("max_neili") < 1200)
            return notify_fail("你的内力太弱，无法学六脉神剑。\n");
        if ((int)me->query_skill("kurong-changong",1) < 120)
            return notify_fail("你的枯荣禅功太低，无法学六脉神剑。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
        object* ob, obj;
        int i,skill,damage;

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练六脉神剑。\n");
        if( skill > 100 && me->query("shen") < 1)
                return notify_fail("这种武功当得行侠义事。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -30);
        return 1;
}
                                          
mixed hit_ob(object me, object victim, int damage_bonus)
        
{	
        if( damage_bonus > 100 ) 
{
        victim->receive_wound("qi", damage_bonus+800, me);
        return HIR "只听一声惨嚎，一股鲜血从$n的身子喷出！\n" NOR;	
}
        if( damage_bonus < 75 ) 
{
        victim->receive_wound("qi", damage_bonus*2, me);	
        return YEL "$n闷哼一声,身子晃了两晃！\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus+200, me);	
        return HIM "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;
}
}

mapping query_action(object me, object weapon)
{
	if (random(me->query_skill("six-finger",1)) > 80 &&
		me->query_skill("kurong-changong",1) > 80 &&
		me->query("neili") > 100)
	{
		me->add("neili", -100);
		return ([
	"action": HIG"$N忽然觉得剑谱中的六路剑法一一涌向心头，十指纷弹，此去彼来，
连绵无尽。剑气纵横，尘烟四起，六路剑法回转运使，$n顿时心神大乱，但
觉全身几处刺痛，几股鲜血从身上标出。忍痛抬头一看，一柱剑气迎面又到",
	"damage": 1000,
	"damage_type": "刺伤"]);
	}
	return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
    return __DIR__"six-finger/" + action;
}

