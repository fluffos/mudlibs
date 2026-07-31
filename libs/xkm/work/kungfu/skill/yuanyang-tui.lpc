// yuanyang-tui.c 鸳鸯连环腿
// liu 2002
/*
眼见二人使出“鸳
鸯连环腿”的脚法，仍是不动声色，未加理会。但听得拍拍拍，波波波，数声响过，他胸口
多了几个灰扑扑的脚印。二道每人均是连踢六脚，足尖犹如踢在沙包之上，软软的极是舒服，

见他下盘虚浮，斜身出足，一招“风扫落叶”，往他腿上扫去。

赵志敬有师叔撑腰，胆子更加大了，提起右足，对准杨过小腹猛踢过去。这招“天山飞
渡”刚中有柔，阳劲蕴蓄阴劲，着实厉害。
*/

inherit SKILL;

mapping *action = ({
([	"action" : "$N身子疾转，右脚贴地伸出，横扫$n的下盘",
	"force" : 150,
	"dodge" : 0,
	"damage_type" : "瘀伤",
	"lvl" : 10,
]),
([	"action" : "$N左腿踢出，不待左腿落下，右脚紧跟着凌空踢出，双脚先后踢向$n的$l",
	"force" : 180,
	"dodge" : 25,
	"damage_type" : "瘀伤",
	"lvl" : 20,
]),
([	"action" : "$N左脚横踹，随即向右前方落步，右脚迅速发力踢向$n的$l",
	"force" : 200,
        "dodge" : 15,
        "damage_type" : "瘀伤",
	"lvl" : 30,
]),
([	"action" : "$N突然一个后翻，双腿晃动，向$n的$l踢去",
	"force" : 230,
        "dodge" : -5,
        "damage_type" : "瘀伤",
	"lvl" : 40,
]),
([	"action" : "$N使拔地而起，双腿连续踢出，击向$n的胸口",
	"force" : 260,
        "dodge" : 30,
        "damage_type" : "瘀伤",
	"lvl" : 50,
]),
([	"action" : "$N身子盘旋飞起，左脚连环，右腿横扫$n的$l",
	"force" : 280,
	"dodge" : 35,
	"damage_type" : "瘀伤",
	"lvl" : 70,
]),
([	"action" : "$N左手一绕，向击向$n的头部，右腿突然踢向$n的$l",
	"force" : 320,
	"dodge" : 0,
	"damage_type" : "瘀伤",
	"lvl" : 80,
]),
([	"action" : "$N使身体凌空而起，双腿连环，只见漫天腿影笼罩着$n",
	"force" : 350,
	"dodge" : 30,
	"damage_type" : "瘀伤",
	"lvl" : 90,
]),
([      "action" : "$N下盘虚浮，斜身出足，一招「风扫落叶」，往$n$l扫去",
        "force" : 400,
        "dodge" : 5,
        "lvl" : 100,
        "skill_name" : "风扫落叶",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N提起右足，对准$n$l猛踢过去，这招「天山飞渡」刚中有柔，阳劲蕴蓄阴劲，着实厉害",
        "force" : 500,
        "dodge" : 25,
        "lvl" : 110,
        "skill_name" : "天山飞渡",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="kick" || usage=="parry"; }

int valid_combine(string combo) { return combo=="sanhua-juding" || combo=="chunyang-quan"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("xiantian-gong", 1) < 20)
		return notify_fail("你的内功修为火候不够，无法学鸳鸯连环腿。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练鸳鸯连环腿。\n");
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
	level = (int) me->query_skill("yuanyang-tui",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("必须空手才能练习鸳鸯连环腿。\n");
	if ((int)me->query("jingli") < 40)
		return notify_fail("你的精力太低了。\n");
	me->receive_damage("jingli", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yuanyang-tui/" + action;
}
