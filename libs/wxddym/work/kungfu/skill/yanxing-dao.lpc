// yanxing-dao.c 雁行刀法
// modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "skill_name" : "让字诀",
	"action": "$N使出「让字诀」，上身侧过，手中刀斜斜砍出，一道白光劈向$n的$l",
	"force" : 60,
	"attack": 10,
	"dodge" : 30,
	"damage": 15,
	"lvl"   : 0,
	"damage_type" : "砍伤",
]),
([      "skill_name" : "打字诀",
	"action": "$N使出「打字诀」，左手护顶，大喝一声，右手刀当头直劈，化作一"
		  "道白芒直向$n的$l砍落",
	"force" : 80,
	"attack": 15,
	"dodge" : 15,
	"damage": 21,
	"lvl"   : 10,
	"damage_type" : "砍伤",
]),
([      "skill_name" : "顶字诀",
	"action": "$N使出「顶字诀」，左手后撤，刀斜上招架，顺势下剁，左手自腋下"
		  "穿出，托住对方手腕，刀光不停指向$n的$l",
	"force" : 100,
	"dodge" : 5,
	"damage": 25,
	"lvl"   : 20,
	"damage_type" : "砍伤",
]),
([      "skill_name" : "引字诀",
	"action": "$N使出「引字诀」，侧身而上，身形突闪，左手带过对方$n兵刃，右"
		  "手刀猛地弹出，把$n绞在刀光中",
	"force" : 120,
	"attack": 25,
	"dodge" : -5,
	"damage": 32,
	"lvl"   : 30,
	"damage_type" : "砍伤",
]),
([      "skill_name" : "套字诀",
	"action": "$N使出「套字诀」，身形向后乍然一闪，左手急速缠住$n左手，手中"
		  "刀一阵乱披风，刀光罩住$n的$l",
	"force" : 140,
	"attack": 25,
	"dodge" : 20,
	"damage": 37,
	"lvl"   : 40,
	"damage_type" : "砍伤",
]),
([      "skill_name" : "陈字诀",
	"action": "$N使出「陈字诀」，身法陡变，轻灵飘忽，捉摸不透，乘$n眼花耳鸣"
		  "之际，右手刀光反卷向$n的$l",
	"force" : 160,
	"attack": 25,
	"dodge" : 15,
	"damage": 43,
	"lvl"   : 50,
	"damage_type" : "砍伤",
]),
([      "skill_name" : "探字诀",
	"action": "$N使出「探字诀」，轻盈地一个急转身，两脚撤步，右手刀尽力向前"
		  "，直抵$n的$l",
	"force" : 180,
	"attack": 25,
	"dodge" : 20,
	"damage": 57,
	"lvl" : 60,
	"damage_type" : "砍伤",
]),
([      "skill_name" : "逼字诀",
	"action": "$N凝神使出「逼字诀」，身随意转，手随心动，绕着$n疾转，手中刀"
		  "光漫卷，将$n的全身笼罩在自己布下的刀网中，无从逃脱",
	"force" : 200,
	"attack": 28,
	"dodge" : 25,
	"damage": 60,
	"lvl" : 70,
	"damage_type" : "砍伤",
]),
([      "skill_name" : "藏字诀",
	"action": "$N凝神使出「藏字诀」，侧身藏刀，引诱$n前进了一步，刀光陡现，"
		  "势如千军万马，奔腾而出",
	"force" : 230,
	"attack": 33,
	"dodge" : 25,
	"damage": 62,
	"lvl" : 80,
	"damage_type" : "砍伤",
]),
([      "skill_name" : "错字诀",
	"action": "$N凝神使出「错字诀」，双手交叉，刀光批攉，$n实在看不清刀光来"
		  "向，退后欲避，只觉一阵寒气直逼过来",
	"force" : 250,
	"attack": 38,
	"dodge" : 25,
	"damage": 70,
	"lvl" : 90,
	"damage_type" : "砍伤",
]),
});

int valid_enable(string usage) { return usage == "blade" ||  usage=="parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force") < 50)
		return notify_fail("你的内功火候不够。\n");

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

	level = (int)me->query_skill("yanxing-dao", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
		return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力不够练雁行刀。\n");

	if ((int)me->query("neili") < 60)
		return notify_fail("你的内力不够练雁行刀。\n");

	me->receive_damage("qi", 53);
	me->add("neili", -51);
	return 1;
}

string perform_action_file(string action)
{
    return __DIR__"yanxing-dao/" + action;
}
