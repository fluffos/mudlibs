// shenghuolin.c
// Writed by yuer

inherit SKILL;

mapping *action = ({
([      "action":"$N身形一晃，“啪”的一声，抓住$n的后领，远远掷了出去.",
        "force" : 120,
        "dodge" : -10,
        "damage": 35,
        "lvl" : 0,
               "weapon" : "左手手掌",
        "damage_type":  "淤伤"
]),
([      "action":"$N$w向$n咽喉点去，$w忽然尾端一弹，急点$n手腕",
        "force" : 140,
        "dodge" : -10,
        "damage": 50,
        "lvl" : 10,
		"weapon" : "右手",
        "damage_type":  "刺伤"
]),
([      "action":"$N突然连翻三个筋斗，白影一闪,有如一条白链，$w向$n重重击去。",
        "force" : 160,
        "dodge" : 5,
        "damage": 75,
        "lvl" : 25,
		"weapon" : "右手手掌",
        "damage_type":  "刺伤"
]),
([      "action":"突然间$N向后摔出，$w从一个不可思议的角度电般急射向$n。",
        "force" : 200,
       "dodge" : 5,
        "damage": 100,
        "lvl" : 40,
	"weapon" : "手指",
        "damage_type":  "刺伤"
]),
([      "action":"$N身体急转，旋风般飞起两脚，$w乘虚刺向$n的小腹，端的是神妙无伦，不可思议",
        "force" : 260,
       "dodge" : 5,
        "damage": 115,
        "lvl" : 55,
		"weapon" : "手指",
        "damage_type":  "刺伤"
]),
([      "action":"$n攻向$N的$l，$N不退反进，忽然低头向$n撞来，攻了$n一个措手不及",
        "force" : 270,
       "dodge" : 5,
        "damage": 150,
        "lvl" : 80,
		"weapon" : "左手",
        "damage_type":  "刺伤"
]),
([      "action":"$N跃身半空，忽然向$n头顶坐了下来，甚是怪异，竟以臀部攻人。",
        "force" : 370,
       "dodge" : 5,
        "damage": 200,
        "lvl" : 105,
		"weapon" : "",
        "damage_type":  "淤伤"
]),
});


int valid_enable(string usage) 
{ 
     return usage == "sword" || usage == "parry"; 
}  

int valid_combine(string combo) { return combo=="lieyan-dao"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
		return notify_fail("你的九阳神功火候太浅。\n");
        if ((string)me->query("family/family_name")!="明教")
		return notify_fail("圣火神功外派的人不能练。\n");
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
        level   = (int) me->query_skill("shenghuo-shengong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

if (!objectp(weapon = me->query_temp("weapon"))
      || (string)weapon->query("skill_type") !="sword")
  return notify_fail("你使用的武器不对。\n");

 if ((int)me->query("qi") < 30)
 return notify_fail("你的体力不够练圣火神功。\n");
me->receive_damage("qi", 30);
return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenghuo-shengong/" + action;
}
string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后脚下一滑，身体向右一侧，避过了攻击。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


