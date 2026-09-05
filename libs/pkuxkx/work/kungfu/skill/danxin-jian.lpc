// yunlong-jian.c 云龙剑

#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action":"$N使一式"+(order[random(13)])+"「辛苦遭逢」"NOR"，手中$w如苦吟微颤，却奇快诡谲，自下而上抹向$n的$l",
	"force" : 50,
        "dodge" : 10,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "辛苦遭逢",
	"damage_type":	"刺伤"
]),
([	"action":"$N错步上前，使出"+(order[random(13)])+"「山河破碎」"NOR"，剑意若有若无，又无所不至，$w以山崩地裂之势向$n的$l急攻",
	"force" : 60,
        "dodge" : 10,
	"damage": 30,
	"lvl" : 8,
	"skill_name" : "山河破碎",
	"damage_type":	"割伤"
]),
([	"action":"$N一式"+(order[random(13)])+"「干戈寥落」"NOR"，运功跃起，一个筋斗如倒挂龙影，手中$w自上而下刺向$n的$l",
	"force" : 70,
        "dodge" : 15,
	"damage": 40,
	"lvl" : 15,
	"skill_name" : "干戈寥落",
	"damage_type":	"刺伤"
]),
([	"action":"$N纵身轻轻跃起，一式"+(order[random(13)])+"「身世浮沉」"NOR"，身形忽上忽下，让人着实捉摸不定，忽的剑光一如古水，一泻千里，向$n直直劈来",
	"force" : 80,
        "dodge" : 20,
	"damage": 50,
	"lvl" : 20,
	"skill_name" : "身世浮沉",
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w中宫直进，一式"+(order[random(13)])+"「天地正气」"NOR"，平稳中正，却变幻莫测地对准$n的$l刺出一剑",
	"force" : 90,
        "dodge" : 15,
	"damage": 60,
	"lvl" : 30,
	"skill_name" : "天地正气",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w一沉，一式"+(order[random(13)])+"「杂然流形」"NOR"，剑尖如春雨悄至，无声无息地滑向$n的$l",
	"force" : 100,
        "dodge" : 15,
	"damage": 70,
	"lvl" : 40,
	"skill_name" : "杂然流形",
	"damage_type":	"割伤"
]),
([	"action":"$N一声悲慨，手中$w斜指苍天，剑芒吞吐，一式"+(order[random(13)])+"「仰天长啸」"NOR"，对准$n的$l狠狠刺出",
	"force" : 110,
        "dodge" : 25,
	"damage": 80,
	"lvl" : 50,
	"skill_name" : "仰天长啸",
	"damage_type":	"刺伤"
]),
([	"action":"$N左指凌空虚点，右手$w划出丈许雪亮剑芒，一式"+(order[random(13)])+"「八千云月」"NOR"刺向$n的咽喉",
	"force" : 120,
        "dodge" : 15,
	"damage": 90,
	"lvl" : 60,
	"skill_name" : "八千云月",
	"damage_type":	"刺伤"
]),
([	"action":"$N合掌跌坐，一式"+(order[random(13)])+"「壮怀激烈」"NOR"，$w一声龙吟，自怀中跃出，$N手若擒龙，半空迅速执起$w，如疾电风雷般攻向$n的胸口",
	"force" : 130,
        "dodge" : 15,
	"damage": 100,
	"lvl" : 70,
	"skill_name" : "壮怀激烈",
	"damage_type":	"刺伤"
]),
([	"action":"$N呼的一声拔地而起，一式"+(order[random(13)])+"「朝天阙拜」"NOR"，$w的剑光闪了几闪，待$n看清时，$N的身形已至半空，剑尖直指$n的天灵",
	"force" : 140,
        "dodge" : 15,
	"damage": 110,
	"lvl" : 80,
	"skill_name" : "朝天阙拜",
	"damage_type":	"刺伤"
]),
([	"action":"$N随风轻轻飘落，一式"+(order[random(13)])+"「零丁之叹」"NOR"，手中$w平指，看似如春风般平缓，实则如冬风般迅捷凌厉，划向$n脸颊",
	"force" : 150,
        "dodge" : 15,
	"damage": 120,
	"lvl" : 90,
	"skill_name" : "零丁之叹",
	"damage_type":	"刺伤"
]),
([	"action" : "$N身子陡然飘起，一招"+(order[random(13)])+"「忠照汗青」"NOR"，切骨剑气如飓风般裹向$n全身",
	"force" : 160,
        "dodge" : 15,
	"damage": 130,
	"lvl" : 100,
	"skill_name" : "忠照汗青",
	"damage_type":	"刺伤"
]),
([	"action" : "$N募的使一招"+(order[random(13)])+"「留取丹心」"NOR"，顿时剑光中几朵血花洒向$n全身",
	"force" : 180,
        "dodge" : 25,
	"damage": 140,
	"lvl" : 110,
	"skill_name" : "留取丹心",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_combine(string combo) { return combo=="jiulong-bian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("cangming-gong", 1) < 20)
		return notify_fail("你的浩气苍冥功火候太浅。\n");
//	if ((int)me->query_skill("yunlong-xinfa", 1) < 20)
//		return notify_fail("你的云龙心法火候太浅。\n");
	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("你的基本内功火候太浅。\n");
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
	level   = (int) me->query_skill("danxin-jian",1);
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
	if ((int)me->query_skill("cangming-gong", 1) < 20)
		return notify_fail("你的浩气苍冥功火候太浅。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练碧血丹心剑。\n");
	me->receive_damage("qi", 25);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"danxin-jian/" + action;
}
