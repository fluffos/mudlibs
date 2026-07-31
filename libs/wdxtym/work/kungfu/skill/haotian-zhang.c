// haotian-zhang 昊天掌
// By Lgg,1998.10

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「"+HIM+"春江潮水"+NOR+"」，双手划了个半圈，按向$n的$l",
	"force" : 60,
	"attack": 30,
	"dodge" : 20,
	"parry" : 31,
	"damage": 5,
	"skill_name" : HIM"春江潮水"NOR,
	"lvl" : 0,
	"damage_type" : "内伤"
]),
([      "action" : "$N使一招「"+BLU+"海上明月"+NOR+"」，左手轻轻一挥，劈向$n的$l",
	"force" : 65,
	"attack": 35,
	"dodge" : 38,
	"parry" : 33,
	"damage": 10,
	"skill_name" : BLU"海上明月"NOR,
	"lvl" : 5,
	"damage_type" : "内伤"
]),
([      "action" : "$N右手掌心向外，由右向左，使一招「"+MAG+"滟滟随波"+NOR+"」，向$n的$l打去",
	"force" : 70,
	"attack": 38,
	"dodge" : 36,
	"parry" : 35,
	"damage": 15,
	"skill_name" : MAG"滟滟随波"NOR,
	"lvl" : 10,
	"damage_type" : "内伤"
]),
([      "action" : "$N使一招「"+CYN+"江流宛转"+NOR+"」，分击$n的胸口和$l",
	"force" : 76,
	"attack": 42,
	"dodge" : 44,
	"parry" : 36,
	"damage": 20,
	"skill_name" : CYN"江流宛转"NOR,
	"lvl" : 15,
	"damage_type" : "内伤"
]),
([      "action" : "$N使一招「"+GRN+"月照花林"+NOR+"」，左右掌同时击出，在空中突然左右掌方向互变",
	"force" : 85,
	"attack": 45,
	"dodge" : 42,
	"parry" : 41,
	"damage": 25,
	"skill_name" : GRN"月照花林"NOR,
	"lvl" : 20,
	"damage_type" : "内伤"
]),
([      "action" : "$N左手不住晃动，右掌一招「"+YEL+"空中流霜"+NOR+"」，向$n的$l打去",
	"force" : 96,
	"attack": 49,
	"dodge" : 50,
	"parry" : 42,
	"damage": 20,
	"skill_name" : YEL"空中流霜"NOR,
	"lvl" : 25,
	"damage_type" : "内伤"
]),
([      "action" : "$N左手变掌为啄，右掌立掌如刀，一招「"+WHT+"汀上白沙"+NOR+"」，劈向$n的$l",
	"force" : 98,
	"attack": 55,
	"dodge" : 58,
	"parry" : 44,
	"damage": 15,
	"skill_name" : WHT"汀上白沙"NOR,
	"lvl" : 30,
	"damage_type" : "内伤"
]),
([      "action" : "$N左脚退后半步，右掌使一招「"+HIC+"江天一色"+NOR+"」，横挥向$n",
	"force" : 105,
	"attack": 59,
	"dodge" : 63,
	"parry" : 48,
	"damage": 14,
	"skill_name" : HIC"江天一色"NOR,
	"lvl" : 35,
	"damage_type" : "内伤"
]),
([      "action" : "$N一招「"+HIW+"皎皎孤月"+NOR+"」，左掌先发而后至，右掌后发而先至",
	"force" : 110,
	"attack": 62,
	"dodge" : 54,
	"parry" : 49,
	"damage": 14,
	"skill_name" : HIW"皎皎孤月"NOR,
	"lvl" : 40,
	"damage_type" : "内伤"
]),
([      "action" : "$N双掌缩入袖中，双袖飞起扫向$n的$l，却是一招「"+HIY+"长江流水"+NOR+"」，仪态潇洒",
	"force" : 120,
	"attack": 66,
	"dodge" : 62,
	"parry" : 52,
	"damage": 12,
	"skill_name" : HIY"长江流水"NOR,
	"lvl" : 45,
	"damage_type" : "内伤"
]),
([      "action" : "$N左手虚按，右手划道弧线使一招「"+WHT+"白云悠悠"+NOR+"」，向$n的$l插去",
	"force" : 130,
	"attack": 75,
	"dodge" : 60,
	"parry" : 54,
	"damage": 16,
	"skill_name" : WHT"白云悠悠"NOR,
	"lvl" : 50,
	"damage_type" : "内伤"
]),
([      "action" : "$N双手变掌做拳，向前向后划弧，一招「"+BLU+"青枫浦上"+NOR+"」击向$n的$l",
	"force" : 150,
	"attack": 81,
	"dodge" : 68,
	"parry" : 55,
	"damage": 12,
	"skill_name" : BLU"青枫浦上"NOR,
	"lvl" : 55,
	"damage_type" : "内伤"
]),
([      "action" : "$N左手虚划，右手变掌为钩一记「"+RED+"楼月蜚回"+NOR+"」击向$n的$l",
	"force" : 170,
	"attack": 85,
	"dodge" : 76,
	"parry" : 58,
	"damage": 28,
	"skill_name" : RED"楼月蜚回"NOR,
	"lvl" : 60,
	"damage_type" : "内伤"
]),
([      "action" : "$N施出「"+HIG+"玉户帘中"+NOR+"」，右掌向外挥出，左掌同时攻向$n",
	"force" : 200,
	"attack": 88,
	"dodge" : 54,
	"parry" : 61,
	"damage": 24,
	"skill_name" : HIG"玉户帘中"NOR,
	"lvl" : 80,
	"damage_type" : "内伤"
]),
([      "action" : "$N由臂带手，在面前缓缓划过，使一招「"+HIB+"鸿雁长飞"+NOR+"」，挥向$n的$l",
	"force" : 220,
	"attack": 92,
	"dodge" : 72,
	"parry" : 62,
	"damage": 15,
	"skill_name" : HIB"鸿雁长飞"NOR,
	"lvl" : 100,
	"damage_type" : "内伤"
]),
([      "action" : "$N负身就地，右掌使一招「"+HIR+"鱼龙潜跃"+NOR+"」，自下而上向$n的$l击去",
	"force" : 250,
	"attack": 94,
	"dodge" : 67,
	"parry" : 64,
	"damage": 18,
	"skill_name" : HIR"鱼龙潜跃"NOR,
	"lvl" : 110,
	"damage_type" : "内伤"
]),
([      "action" : "$N右手由钩变掌，双手掌心向上，右掌向前推出一招「"+HIM+"月华流照"+NOR+"」",
	"force" : 280,
	"attack": 96,
	"dodge" : 81,
	"parry" : 66,
	"damage": 28,
	"skill_name" : HIM"月华流照"NOR,
	"lvl" : 120,
	"damage_type" : "内伤"
]),
([      "action" : "$N右掌不住向外扫出，是一式「"+CYN+"闲潭落花"+NOR+"」，左掌旋转着向$n攻去",
	"force" : 310,
	"attack": 99,
	"dodge" : 66,
	"parry" : 69,
	"damage": 21,
	"skill_name" : CYN"闲潭落花"NOR,
	"lvl" : 130,
	"damage_type" : "内伤"
]),
([      "action" : "$N右手经腹前经左肋向前撇出，使一招「"+HIC+"江水流春"+NOR+"」，向$n的$l锤去",
	"force" : 330,
	"attack": 100,
	"dodge" : 64,
	"parry" : 74,
	"damage": 32,
	"skill_name" : HIC"江水流春"NOR,
	"lvl" : 140,
	"damage_type" : "内伤"
]),
([      "action" : "$N使一招「"+GRN+"斜月沉沉"+NOR+"」，左掌连划三个大圈，右掌从圈中穿出击向$n",
	"force" : 370,
	"attack": 102,
	"dodge" : 72,
	"parry" : 73,
	"damage": 35,
	"skill_name" : GRN"斜月沉沉"NOR,
	"lvl" : 150,
	"damage_type" : "内伤"
]),
([      "action" : "$N左手向上划弧拦出，右手使一招「"+HIY+"碣石潇湘"+NOR+"」，手掌不住晃动，不"
		   "离$n头顶方寸之间",
	"force" : 400,
	"attack": 105,
	"dodge" : 65,
	"parry" : 79,
	"damage": 50,
	"skill_name" : HIY"碣石潇湘"NOR,
	"lvl" : 160,
	"damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }

int valid_combine(string combo)
{
	return combo == "sun-finger" ||
	       combo == "zhongnan-zhi";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练昊天掌必须空手。\n");

	if ((int)me->query("neili") < 900)
		return notify_fail("你的内力不够，无法学昊天掌。\n");

	if ((int)me->query_skill("force") < 110)
		return notify_fail("你的内功火候不够，无法学昊天掌。\n");
	if (me->query_skill("strike",1) <= me->query_skill("haotian-zhang",1) )
	      return notify_fail("你的基本掌法基础不够，无法领会更高深的昊天掌。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("haotian-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 80)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("你的内力不够练昊天掌。\n");

	me->receive_damage("qi", 68);
	me->add("neili", -66);
	return 1;
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

string perform_action_file(string action)
{
	return __DIR__"haotian-zhang/" + action;
}
