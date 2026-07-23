/* 
   jimie-zhua.c 寂灭爪
   和大金刚神掌(jingang-zhang)互备
   截至佛经中人生八苦。
   2/3/98 by snowman
*/

inherit SKILL;

mapping *action = ({
([	"action" : "$N全身拔地而起，一式「生」字诀，双爪相扣，迅猛地抓向$n，却又不带任何霸气",
	"force" : 100,
	"dodge" : 30,
	"lvl" : 0,
	"skills_name" : "生",
	"damage_type" : "抓伤"
]),
([	"action" : "$N一式「老」字诀，双爪中宫直进，却不变招，待其用老之际，$n已避无可避",
	"force" : 120,
	"dodge" : 20,
	"lvl" : 10,
	"skills_name" : "老",
        "damage_type" : "抓伤"
]),
([	"action" : "$N脚步蹒跚，有如「病」态，左手曲抓随意一挥，竟然能带起数到劲风直袭$n$l",
	"force" : 150,
	"dodge" : 25,
	"lvl" : 20,
	"skills_name" : "病",
        "damage_type" : "抓伤"
]),
([	"action" : "$N双爪交错，一式「死」字诀，身随抓动，追着$n如影附骨，誓要击杀$p去爪下",
	"force" : 180,
        "dodge" : 10,
	"lvl" : 30,
	"skills_name" : "死",
        "damage_type" : "抓伤"
]),
([	"action" : "$N一式「求不得」，右爪突出，左爪跟进，接着右抓又出，双爪相叠，抓向$n的胸口",
	"force" : 210,
	"dodge" : 15,
        "limb" : "胸口",
	"lvl" : 40,
	"skills_name" : "求不得",
        "damage_type" : "抓伤"
]),
([	"action" : "$N原地不动，一式「爱别离」，只待$n袭来，双手猛然变爪而出，直插$n的两处大穴",
	"force" : 240,
	"dodge" : 10,
	"lvl" : 60,
	"skills_name" : "爱别离",
        "damage_type" : "抓伤"
]),
([	"action" : "$N翻身一挥，双爪无数道劲气破空而出，一式「怨憎会」，迅疾无比地飞刺向$n",
        "force" : 270,
        "dodge" : 5,
        "weapon" : "手爪",
	"lvl" : 80,
	"skills_name" : "怨憎会",
        "damage_type" : "刺伤"
]),
([  	"action" : "$N腾空高飞数丈，打出一式「五阴炽盛」，一时间空中出现无数$N的身影，层层抓影罩向$n",
        "force" : 300,
        "dodge" : 5,
	"lvl" : 100,
	"skills_name" : "五阴炽盛",
        "damage_type" : "抓伤"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo){
        if(this_player()->query_skill("jimie-zhua", 1) > 100)
   	         return combo=="jingang-zhang";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练寂灭爪必须空手。\n");
        if ((int)me->query_skill("yijinjing", 1) < 100)
		return notify_fail("你的易筋经内功火候不够，无法学寂灭爪。\n");
        if ((int)me->query("max_neili") < 1200)
		return notify_fail("你的内力太弱，无法练习寂灭爪。\n");

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
	level   = (int) me->query_skill("jimie-zhua",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练寂灭爪。\n");
	me->receive_damage("jing", 40);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
         return __DIR__"jimie-zhua/" + action;
}

