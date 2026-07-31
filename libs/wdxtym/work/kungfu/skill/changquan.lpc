//太祖长拳 changquan.c

inherit SKILL;

mapping *action = ({
([      "action": "只见$N身形一矮，大喝声中一个「"+HIC+"冲天炮"+NOR+"」对准$n的鼻子呼！地砸了过去",
	"dodge": 5,
	"parry": 5,
	"force": 90,
	"skill_name" : HIC"冲天炮"NOR,
	"damage_type":  "砸伤"
]),
([      "action": "$N左手一分，右拳运气，一招「"+GRN+"拔草寻蛇"+NOR+"」便往$n的$l招呼过去",
	"dodge": 5,
	"parry": 5,
	"force": 60,
	"skill_name" : GRN"拔草寻蛇"NOR,
	"damage_type":  "瘀伤"
]),
([      "action": "$N右拳在$n面门一晃，左掌使了个「"+RED+"叶底偷桃"+NOR+"」往$n的$l狠命一抓",
	"dodge": 5,
	"parry": 5,
	"force": 60,
	"skill_name" : RED"叶底偷桃"NOR,
	"damage_type":  "抓伤"
]),
([      "action": "$N步履一沉，左拳拉开，右拳带风，一招「"+HIR+"黑虎掏心"+NOR+"」势不可挡地击向$n$l",
	"dodge": 5,
	"parry": 5,
	"force": 80,
	"skill_name" : HIR"黑虎掏心"NOR,
	"damage_type":  "瘀伤"
]),
([      "action": "只见$N拉开架式，一招「"+HIB+"双风贯耳"+NOR+"」使得虎虎有风。底下却飞起一脚踢向$n$l",
	"dodge": 5,
	"parry": 5,
	"force": 70,
	"skill_name" : HIB"双风贯耳"NOR,
	"damage_type":  "瘀伤"
]),
([      "action": "$N打得兴起，大喝一声：看我这招「"+HIM+"龙虎相交"+NOR+"」！左手往$n身后一抄，右拳便往$n面门砸了过去",
	"dodge": 5,
	"parry": 5,
	"force": 120,
	"skill_name" : HIM"龙虎相交"NOR,
	"damage_type":  "砸伤"
]),
([      "action": "$N拉开后弓步，双掌使了个「"+HIR+"如封似闭"+NOR+"」往$n的$l一推",
	"dodge": 5,
	"parry": 5,
	"force": 50,
	"skill_name" : HIR"如封似闭"NOR,
	"damage_type":  "瘀伤"
]),
([      "action": "只见$N运足气力，一连三拳击向$n$l，力道一拳高过一拳！，叫作「"+HIY+"阳关三叠"+NOR+"」",
	"dodge": 5,
	"parry": 5,
	"force": 80,
	"skill_name" : HIY"阳关三叠"NOR,
	"damage_type":  "瘀伤"
]),
([      "action": "$N往后一纵，就势使了个「"+MAG+"老树盘根"+NOR+"」，右腿扫向$n的$l",
	"dodge": 5,
	"parry": 5,
	"force": 50,
	"skill_name" : MAG"老树盘根"NOR,
	"damage_type":  "砸伤"
]),
([      "action": "$N一个转身，左掌护胸，右掌反手使了个「"+HIR+"独劈华山"+NOR+"」往$n当头一劈",
	"dodge": 5,
	"parry": 5,
	"force": 90,
	"skill_name" : HIR"独劈华山"NOR,
	"damage_type":  "砸伤"
]),
([      "action": "$N飞身跃起，正是一招「"+RED+"苍鹰捕鼠"+NOR+"」，半空中一脚踢向$n面门，只见$N一个倒翻，双掌已到了$n的$l",
	"dodge": 5,
	"parry": 5,
	"force": 100,
	"skill_name" : RED"苍鹰捕鼠"NOR,
	"damage_type":  "瘀伤"
]),
});

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练长拳必须空手。\n");
	if (me->query_skill("unarmed",1) <= me->query_skill("changquan",1))
		return notify_fail("你的基本拳脚不够，无法领会更高深的太祖长拳。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "parry";
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
//等级提升，是否学会新的招式
string query_skill_up(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	 {
		if(level == action[i]["lvl"])
		 {
		     return action[i]["skill_name"];
		 }
	 }
	  return "no";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");

	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("qi", 35);
	me->add("neili", -1);

	return 1;
}
