// xiyu-zhang 西域掌
//written by cool

inherit SKILL;

mapping *action = ({
([
	"action" : "$N右腿向左前方排踢，两手掌心斜向前，一式「排踢双按掌」，按向$n的$l",
	"damage_type" : "瘀伤",
	"lvl" : 0,
	"skill_name" : "排踢双按掌"
]),
([
	"action" : "$N左腿半蹲成弓步，身向前倾，一式「弓步砍掌」，右手直臂向前横砍",
	"damage_type" : "瘀伤",
	"lvl" : 20,
	"skill_name" : "弓步砍掌"
]),
([
	"action" : "$N一式「左穿掌」，左脚向右前方落步，左手变拳为掌，向外绕环发力穿出",
	"damage_type" : "劈伤",
	"lvl" : 40,
	"skill_name" : "左穿掌"
]),
([
	"action" : "$N左掌翻上撑架于前上方，掌心斜向上，一式「上托掌」，右掌向前上方推出",
	"damage_type" : "震伤",
	"lvl" : 60,
	"skill_name" : "上托掌"
]),
([
	"action" : "$N使一式「弓步架按掌」，立个左弓步，左掌外旋，掌心斜向下，向$n的前下方猛按",
	"damage_type" : "瘀伤",
	"lvl" : 80,
	"skill_name" : "弓步架按掌"
]),
([
	"action" : "$N身子不动，一式「连环双击」，右手化掌为拳，向前冲出，左手立掌紧跟着向$n砍去",
	"damage_type" : "内伤",
	"lvl" : 90,
	"skill_name" : "连环双击"
]),
([
	"action" : "$N右脚绕过左脚向东方落步，一式「绕步上插掌」，右手举起向$n插掌",
	"damage_type" : "瘀伤",
	"lvl" : 100,
	"skill_name" : "绕步上插掌"
]),
([
	"action" : "$N使一式「横推掌」，左手向上抬起，右手从体侧伸出，成立掌向$n横推",
	"damage_type" : "瘀伤",
	"lvl" : 140,
	"skill_name" : "横推掌"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练西域掌必须空手。\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的内功火候不够，无法学西域掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练西域掌。\n");
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
	int i, level, j;
	level = (int)me->query_skill("xiyu-zhang", 1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	150 + random(300),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("xiyu-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练西域掌。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}
