// hannbing-mianzhang.c 寒冰绵掌
// pal 1997.05.26
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「大江东去」，双掌大开大合，直向$n的$l击去",
	"force" : 180,
        "dodge" : 5,
        "parry" : 20,
	"damage": 200,
	"lvl" : 0,
	"skill_name" : "大江东去",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形一变，一式「黄河九曲」，双掌似曲似直，拍向$n的$l",
	"force" : 220,
        "dodge" : 10,
        "parry" : 15,
	"damage": 220,
	"lvl" : 10,
	"skill_name" : "黄河九曲",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「湖光山色」，左掌如微风拂面，右掌似细雨缠身，直取$n的$l",
	"force" : 260,
        "dodge" : 15,
        "parry" : 20,
	"damage": 230,
	"lvl" : 20,
	"skill_name" : "湖光山色",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N两掌一分，一式「曾经沧海」，隐隐发出潮声，向$n横击过去",
	"force" : 300,
        "dodge" : 20,
        "parry" : 30,
	"damage": 240,
	"lvl" : 30,
	"skill_name" : "曾经沧海",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形一转，使出一式「水光潋滟」，只见漫天掌影罩住了$n的全身",
	"force" : 340,
        "dodge" : 25,
        "parry" : 20,
	"damage": 250,
	"lvl" : 40,
	"skill_name" : "水光潋滟",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N突然身形一缓，使出一式「小雨初晴」，左掌凝重，右掌轻盈，击往$n的$l",
	"force" : 380,
        "dodge" : 25,
        "parry" : 25,
	"damage": 260,
	"lvl" : 50,
	"skill_name" : "小雨初晴",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「风雪江山」，双掌挟狂风暴雪之势，猛地劈向$n的$l",
	"force" : 420,
        "dodge" : 30,
        "parry" : 30,
	"damage": 270,
	"lvl" : 260,
	"skill_name" : "风雪江山",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「霜华满地」，双掌带着萧瑟的秋气，拍向$n的$l",
	"force" : 460,
        "dodge" : 30,
        "parry" : 235,
	"damage": 280,
	"lvl" : 270,
	"skill_name" : "霜华满地",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身法陡然一变，使出一式「仙乡冰舸」，掌影千变万幻，令$n无法躲闪",
	"force" : 500,
        "dodge" : 40,
        "parry" : 45,
	"damage": 290,
	"lvl" : 80,
	"skill_name" : "冰清玉洁",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N清啸一声，一式「冰霜雪雨」，双掌挥舞，如同雪花随风而转，击向$n的$l",
	"force" : 540,
        "dodge" : 45,
        "parry" : 50,
	"damage": 310,
	"lvl" : 90,
	"skill_name" : "仙乡冰舸",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage)
{
	return usage=="strike" || usage=="parry" ;
}
int valid_combine(string combo) { return combo=="sougu"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练寒冰绵掌必须空手。\n");
//	if ((int)me->query_skill("huagong-dafa", 1) < 20)
//		return notify_fail("你的化功大法火候不够，无法学寒冰绵掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练寒冰绵掌。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("hanbing-mianzhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练寒冰绵掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if( random(me->query_skill("hanbing-mianzhang",1)) > 10 )
	victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 6 + victim->query_condition("ice_poison"));
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jiuyang-shengong",1);
        skill = me->query_skill("jiuyang-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenghuo-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "jiuyang-shengong" || me->query_skill_mapped("force") == "shenghuo-shengong"))
{
j = -damage/2; 
j = 0;
if (damage2> 5000)	damage2=5000;
msg = HIC+"$N运起九阳神功 全身内力爆发，浮现出一层刚猛的劲气! !" +NOR;
           message_vision(msg, me, ob);
if ( me->is_busy())
{
me->start_busy(1);
ob->start_busy(2);
}
if (me->query("neili") > me->query("max_neili")*2)
{
		
		me->add("neili", damage2);
}

}


           return j;
}      
string perform_action_file(string action)
{
	return __DIR__"hanbing-mianzhang/" + action;
}
