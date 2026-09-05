//mintian-jiushi.c 冥天九式
//edit by fast
//1997 11/4

inherit SKILL;

mapping *action = ({
   ([      "action" : "$N身子微微一侧，$w从一个不可思仪的角度刺了出来，只奔$n的$l",
          "force" : 140,
          "dodge" : 15,
          "damage" : 35,
          "lvl" : 0,
          "damage_type" : "刺伤",
   ]),      
 ([      "action" : "$N右手闪电似的一抽一抖，$w宛似一条从洞中窜出的毒蛇，向$n的$l刺去",
          "force" : 150,
	"dodge" : 20,
          "damage" : 40,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
 ([      "action" : "$N身形暴起，斜飞上半空，双臂一振，身子一个转折，头下脚上，手中的$w直朝$n的$l刺去",
          "force" : 180,
	"dodge" : 15,
          "damage" : 50,
          "lvl" : 10,
	"damage_type" : "刺伤"
]),
 ([      "action" : "$N身子在空中一拧，疾逾闪电，手中的$w如同千百道从天而降的雷火，发出撕裂人心的锐啸，迎头向$n罩下",
          "force" : 200,
	"dodge" : 15,
          "damage" : 100,
          "lvl" : 20,
	"damage_type" : "刺伤"
]),
 ([      "action" : "$N一声长啸，身形骤展，手中$w幻闪起一片耀目光芒，夹着刺人心魄的嘶风锐响，恍若一张绵密无际的天罗，眨眼工夫将$n罩在剑网中",
          "force" : 300,
	"dodge" : 10,
          "damage" : 200,
          "lvl" : 50,
	"damage_type" : "刺伤"
]),
   ([      "action" : "$N一振$w,抖起一蓬光雨,包卷了全身形成一道光体,'咝'的一声划空而过,向$n射去",
          "force" : 350,
          "damage" : 150,
          "dodge" : 50,
          "lvl" : 60,
          "damage_type" : "刺伤",
   ]),
   ([      "action" : "$N突然向后一纵，脚一点地，连翻几个跟头，身形一展，$w向$n的$l刺去",
          "force" : 300,
          "damage" : 150,
          "dodge" : 70,
          "lvl" : 40,
          "damage_type" : "刺伤",
   ]),
   ([      "action" : "$N手中的$w一阵急舞，荡起重重剑影，就想一座座剑山，向$n推去",
          "force" : 400,
          "damage" : 200,
          "lvl" : 80,
          "damage_type" : "刺伤",
   ]),
   ([      "action" : "$N运起真气，$w抡的大开大阂，气势磅礴，空中划出无数光影，向$n砍去，",
          "force" : 420,
          "damage" : 240,
          "lvl" : 100,
          "damage_type" : "刺伤",
   ]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
           level   = (int) me->query_skill("mintian-jiushi",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
          if ((int)me->query("qi") < 35)
return notify_fail("你的体力不够练冥天九式。\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
          return __DIR__"mintian-jiushi/" + action;
}

string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
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
