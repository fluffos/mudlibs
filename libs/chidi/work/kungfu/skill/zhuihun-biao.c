// zhuihun-biao.c 追魂夺命镖

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w一闪，一招「无常敲门」，手腕一翻，向$n的$l打去",
	"force" : 120,
        "dodge" : -10,
        "parry" : 5,
	"damage" : 20,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N一招「小鬼闹花灯」，往地上一滚，$w悄无声息打向$n的颈部",
	"force" : 130,
        "dodge" : -10,
        "parry" : 10,
	"damage" : 25,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N斜身进步，一招「五鬼抬轿」，手中五枚$w,笔直飞向$n",
	"force" : 140,
        "dodge" : -5,
        "parry" : 5,
	"damage" : 30,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N一招「奈何不归路」，$w撒手飞出，竟以不可思议的角度，打向$n背面",
	"force" : 160,
        "dodge" : 5,
        "parry" : 5,
	"damage" : 35,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N一招「阴雨绵绵欲断魂」，一把$w劈头盖脸打向$n的胸口。",
	"force" : 180,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 40,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N身子一踉跄，好象要跌倒，却见精芒闪动，正是一招「断肠伤心无去处」，$w飞快罩向$n",
	"force" : 210,
        "dodge" : 15,
        "parry" : 15,
	"damage" : 50,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N一招「阎罗孤灯」，$w闪烁不定，时快时慢，防不胜防打$n的$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 15,
	"damage" : 60,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$N腾空跃起，一招「炼狱流火」，数枚$w脱手而出，一枚接一枚，竟然成了一根火线向$n的全身打去",
	"force" : 280,
        "dodge" : 20,
        "parry" : 10,
	"damage" : 80,
	"damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
});


int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 20)
		return notify_fail("你的碧云心法火候不够。\n");
	if ((int)me->query_skill("biye-wu", 1) < 20)
		return notify_fail("你的碧叶随风舞火候太浅。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("zhuihun-biao",1);

if (level < 60 )
zhaoshu--;
if (level < 55 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;

return action[random(zhaoshu)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练追魂夺命镖。\n");
	me->receive_damage("qi", 30);
	return 1;
}

