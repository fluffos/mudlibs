// wuzhan-mei.c 五展梅

#include <ansi.h>
inherit SKILL;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"tmzhuihun_poison",
"tmpili_poison",
"zm_poison",
});


mapping *action = ({
([	"action" : "$N一招“五展梅”「冬梅初吐蕊」，手中$w犹如点点淡黄色的梅蕊刺向$n的$l",
        "force" : 60,
        "dodge" : 82,
	"parry" : 10,
	"skill_name" : "冬梅初吐蕊",
	"lvl" : 0,
        "damage" : 70,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出“五展梅”「幼梅傲霜雪」，$n只觉剑气扑面而来，仿佛置身冰天雪地中，\n"
                   "$w仿佛化作傲霜的梅枝刺向$n的$l",
        "force" : 100,
        "dodge" : 80,
	"parry" : 20,
        "skill_name" : "幼梅傲霜雪",
	"lvl" : 20,
	"damage" : 90,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招“五展梅”「劲梅笑迎春」，$w连续划出几个圆圈，剑势如朵朵梅花，\n"
                   "$n眼前一花，$w已攻到面前", 
        "force" : 150,
        "dodge" : 82,
	"parry" : 30,
        "skill_name" : "劲梅笑迎春",
	"lvl" : 40,
	"damage" : 110,
	"damage_type" : "刺伤"
]),

([      "action" : "$N一腾身，$w飞舞，正是“五展梅”「腊梅暗香浮」,$n竟似闻到淡淡梅花幽香，\n"
                   "恍惚间心驰神动,剑气已直刺$n的$l",
        "force" : 200,
        "dodge" : 84,
	"parry" : 50,
        "skill_name" : "腊梅暗香浮",
	"lvl" : 60,
        "damage" : 130,
        "damage_type" : "刺伤"
]),

([	"action" : "$N向前跨上一步，手中$w使出“五展梅”「红梅展新枝」,剑光爆涨，\n"
                   "快愈闪电直刺$n的$l",
        "force" : 400,
        "dodge" : 86,
	"parry" : 70,
        "skill_name" : "红梅展新枝",
	"lvl" : 80,
	"damage" : 150,
	"damage_type" : "刺伤"
]),

([      "action" : "$N手中的$w一晃，使出“五展梅”终极招式「五梅花枝俏」,五式合作一式，\n"
                   "瞬间剑意漫天，$n只见梅花四处飞舞，隐藏其中的杀气已透骨而入",
        "force" : 600,
        "dodge" : 88,
	"parry" : 90,
        "skill_name" : "五梅花枝俏",
	"lvl" : 100,
        "damage" : 170,
        "damage_type" : "刺伤"
]),
});



int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 400)
		return notify_fail("你的内力不够。\n");
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
    level   = (int) me->query_skill("wuzhan-mei",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练五展梅。\n");
	me->receive_damage("qi", 20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wuzhan-mei/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("biyun-xinfa",1);
        level2= (int) me->query_skill("biyun-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "biyun-xinfa")
{
            victim->receive_damage("qi",20);
            victim->receive_wound("qi",15 + random(10));
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N突然收掌，然后迅速发掌! 掌中尽然有毒砂，这掌风尽然是五颜六色的！$n硬起头皮，以掌硬接！！结果身中巨毒！!\n";
}
 
}