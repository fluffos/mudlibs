// Nianhua-zhi.c 拈花指法
// Cracked by 凌惊雪 5-12-2003

inherit SKILL;

mapping *action = ({
([      "action" : "$N侧身抬臂，右指划了个半圈，一式「瓶花落砚」击向$n的$l",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
//1
([      "action" : "$N侧身抬臂，右指划了个半圈，一式「瓶花落砚」击向$n的$l",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
//2
([      "action" : "$N左掌虚托，一式「寒梅吐蕊」，右指穿腋疾出，指向$n的胸前",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
//3
([      "action" : "$N俯身斜倚，左手半推，右手一式「初杏问酒」，向$n的$l划过",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
//4
([      "action" : "$N双目微睁，一式「露草斜阳」，双手幻化出千百个指影，拂向$n的$l",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
//5
([      "action" : "$N一式「仰月承霖」，左掌护住丹田，右手斜指苍天，蓄势点向$n的$l",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
//6
([      "action" : "$N双掌平托胸前，十指叉开，一式「叶底留莲」，指向$n的周身大穴",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
//7
([      "action" : "$N双掌翻飞，一式「清风拂桂」，指端迸出无数道劲气，射向$n的全身",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
//8
([      "action" : "$N一式「菊圃秋霜」，并指如刃，一束束锐利无俦的刀气，凌虚向$n的$l砍去",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
//9
([      "action" : "$N一式「伽叶微笑」，双手食指交叉，指端射出一缕罡气，穿过$n的$l",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
//10
([      "action" : "$N左掌竖立胸前，一式「佛祖拈花」，右手食指扣住拇指，轻轻对着$n一弹",
        "dodge":               	-40,
        "parry":                -40,
        "force":                180,
        "damage_type":  	"刺伤",
        "weapon":               "右手食指",
]),
});

int valid_enable(string usage) 
	{ 
		return (usage == "unarmed") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if (me->query("chushi/chushi_putuo") != "yes" )
                return notify_fail("你没有领悟「拈花指法」的窍门。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「拈花指法」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-nianhua");
	if( !me->query_temp("pfm-nianhua") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if (me->query("chushi/chushi_putuo") != "yes" )
                return notify_fail("你没有领悟「拈花指法」的窍门。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「拈花指法」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「拈花指法」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("chushi") + "/nianhua-zhi/" + func;
}
