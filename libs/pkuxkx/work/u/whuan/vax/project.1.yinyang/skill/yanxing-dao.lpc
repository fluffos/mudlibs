// yanxing-dao.c 雁行刀
inherit SKILL;
mapping *action = ({
([	"action" : "$N使出「让字诀」，身子一侧，让过$n，跟着挥刀斩向$n的$l",
	"force" : 180,
        "dodge" : -10,
        "parry" : 5,
	"damage": 40,
	"lvl" : 0,
	"skill_name" : "让字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N一式「打字诀」，左掌虚托右肘，手中$w刷地一声自上而下向$n猛劈",
	"force" : 200,
        "dodge" : -10,
        "parry" : 10,
	"damage": 50,
	"lvl" : 10,
	"skill_name" : "打字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N一式「顶字诀」，两脚点地，双手握$w，猛力向$n的$l刺去?,
	"force" : 220,
        "dodge" : -5,
        "parry" : 5,
	"damage": 60,
	"lvl" : 20,
	"skill_name" : "顶字诀",
	"damage_type" : "刺伤"
]),
([	"action" : "$N使一式「印字诀」，脚步后滑，手中$w慢慢收回，突然反手一刀斩向$n的$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 5,
	"damage": 70,
	"lvl" : 30,
	"skill_name" : "引字诀",
	"damage_type" : "割伤",
]),
([	"action" : "$N手中$w挑起，一式「套字诀」，$w划出无数光圈，漫天刀气，套向$n的$l",
	"force" : 280,
        "dodge" : 10,
        "parry" : 5,
	"damage": 80,
	"lvl" : 40,
	"skill_name" : "套字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N身形一矮，双手合执$w，一式「沉字诀」，手中$w直刺向$n的双眼",
	"force" : 320,
        "dodge" : 15,
        "parry" : 15,
	"damage": 90,
	"lvl" : 50,
	"skill_name" : "沉字诀",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「探字诀」，手中$w微颤，如蜻蜓点水般快速点向$n的$l",
	"force" : 360,
        "dodge" : 15,
        "parry" : 15,
	"damage": 100,
	"lvl" : 60,
	"skill_name" : "探字诀",
	"damage_type" : "刺伤"
]),
([	"action" : "$N跨上一步，双手握刀，一式「逼字诀」，横削直砍激起阵阵刀风向$n逼去",
	"force" : 400,
        "dodge" : 20,
        "parry" : 10,
	"damage": 110,
	"lvl" : 70,
	"skill_name" : "逼字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N一式「藏字诀」，藏刀身后，猛一旋身，摔出一道刀光，划向$n的$l",
	"force" : 450,
        "dodge" : 10,
        "parry" : 20,
	"damage": 120,
	"lvl" : 80,
	"skill_name" : "藏字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N使出一式「错字诀」，将手中$w向绝无可能的方向刺去，刀尖一转，却斩向$n的$l",
	"force" : 500,
        "dodge" : 5,
        "parry" : 25,
	"damage": 130,
	"lvl" : 90,
	"skill_name" : "错字诀",
	"damage_type" : "割伤"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_combine(string combo) { return combo=="fuliu-jian";}
int valid_learn(object me)
{       
        if (me->query("class")!="bonze" && (int)me->query_skill("yanxing-dao",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候太浅。\n");
        if ((int)me->query_skill("jinding-mianzhang",1) < 20)
                return notify_fail("你的金顶绵掌火候太浅。\n");
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
	level   = (int) me->query_skill("yanxing-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	object weapon;
        if (me->query("class")!="bonze" && (int)me->query_skill("yanxing-dao",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练雁行刀。\n");
	me->receive_damage("qi", 35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yanxing-dao/" + action;
}

string query_yinyang()
{
	return "太阳";
}