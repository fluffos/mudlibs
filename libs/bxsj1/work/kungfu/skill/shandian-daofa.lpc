//  shandian-daofa闪电刀法

inherit SKILL;

mapping *action = ({
([
	"action" : "$N身影变双，刀光浮动，转眼已劈出九刀，向$n的$l挥去",
	"lvl" : 0,
	"skill_name" : "闪电刀法",
	"damage_type" : "割伤"
]),
([
	"action" : "$N凌空扬刀，绕$n游走，刀法之快，匪夷所思，手中$w已割向$n的周身各处",
	"lvl" : 50,
	"skill_name" : "闪电刀法",
	"damage_type" : "割伤"
]),
([
	"action" : "$N掌中$w稍作一顿，旋及如流星划空，闪电霹雳，刷地一声自上而下向$n猛劈",
	"lvl" : 100,
	"skill_name" : "闪电刀法",
	"damage_type" : "割伤"
]),
([
	"action" : "$N右手反执刀柄，横刀一斩，$w直向$n的颈中划去",
	"lvl" : 150,
	"skill_name" : "闪电刀法",
	"damage_type" : "割伤",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("shandian-daofa",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	150+random(300),
				"dodge":	random(30),
				"parry":	random(30),
				"damage":	60 + random(100),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 40)
		return notify_fail("你的体力不够练闪电刀法。\n");
	if ( me->query("neili") < 20)
		return notify_fail("你的体力不够练闪电刀法。\n");
        me->receive_damage("jingli", 30);
	me->add("neili", -10);
        return 1;
}

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}
