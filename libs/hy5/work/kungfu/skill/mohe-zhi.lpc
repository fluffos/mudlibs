/* 
   mohe-zhi.c 摩诃指
   和波罗蜜手(boluomi-shou)互备
   截至佛经中“以慈度心，摩诃无量”一句。
   2/3/98 by snowman
*/


inherit SKILL;

mapping *action = ({
([	"action" : "$N左掌一摆，护在胸前，接着右手食指画出一个「以」字，轻轻点向$n$l",
	"force" : 100,
        "dodge" : 25,
	"lvl" : 0,
	"skill_name" : "以",
	"damage_type" : "刺伤"
]),
([	"action" : "$N左手食指缓缓画了个「慈」字，跟着手指微曲，以字为中心，对着$n一弹",
	"force" : 130,
        "dodge" : 20,
        "weapon" : "指力",
	"lvl" : 20,
	"skill_name" : "慈",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双掌合十，身体微欠，双指画一「度」字，那撇捺两画有如两条柳枝般，抚向$n$l",
	"force" : 150,
        "dodge" : 15,
        "weapon" : "指劲",
	"lvl" : 30,   
        "skill_name" : "度",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双手小指向$n挥动，连点三点，接着双指并拢，一招斜划，拼成了一个「心」字",
	"force" : 180,
        "dodge" : 20,
        "weapon" : "双指",
	"lvl" : 50,
	"skill_name" : "心",
        "damage_type" : "割伤"
]),
([	"action" : "$N连连出招，幻出漫天指影，仿佛间竟然形成了一个「摩」字，照着$n激射而去，越来越快",
	"force" : 210,
        "dodge" : 5,
	"lvl" : 60,
	"skill_name" : "摩",
        "damage_type" : "震伤"
]),
([	"action" : "$N右手食指伸出，在空中写出个「诃」字来，形如狂草，向着$n最后一提时竟飞射出一道青气",
	"force" : 240,
        "dodge" : 10,
        "weapon" : "指力",
	"lvl" : 70,
	"skill_name" : "诃",
        "damage_type" : "刺伤"
]),
([	"action" : "只见$N手指横竖连划，将指力在空中凝结不散，形成一个「无」字，对着$n当胸压下",
	"force" : 270,
        "dodge" : 0,
	"lvl" : 80,
	"skill_name" : "无",
        "damage_type" : "震伤"
]),
([	"action" : "$N双拳并拢，夹出一个「量」字来，合力击向$n，突然下半招一变，右手一指破空击出",
	"force" : 300,
        "dodge" : 5,
	"lvl" : 100,
	"skill_name" : "量",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo){
        if(this_player()->query_skill("mohe-zhi", 1) > 100
	   && this_player()->query_int() > 20)
   	         return combo=="boluomi-shou";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练摩诃指必须空手。\n");
        if ((int)me->query_skill("yijinjing", 1) < 100)
		return notify_fail("你的易筋经内功火候不够，无法学摩诃指。\n");
        if ((int)me->query("max_neili") < 1200)
		return notify_fail("你的内力太弱，无法练摩诃指。\n");

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
	level   = (int) me->query_skill("mohe-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 40)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练摩诃指。\n");
	me->receive_damage("jing", 40);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
         return __DIR__"mohe-zhi/" + action;
}
