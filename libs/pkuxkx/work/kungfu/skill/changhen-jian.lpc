// changhen-jian,长恨剑法
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$N使一招"+HIB"「回头一笑百媚生」"NOR+"，手中$w化为一道疾光刺向$n的$l",
	"force" : 120,
        "dodge" : 0,
	"damage": 30,
	"lvl" : 0,
	"skill_name" : "回头一笑百媚生",
	"damage_type":	"割伤"
]),
([	"action":"只见$N半个急转，使出"+HIG"「六宫粉黛无颜色」"NOR+"，一声娇喝中剑光冲天而起，扫向$n的$l",
	"force" : 140,
        "dodge" : 10,
	"damage": 40,
	"lvl" : 9,
	"skill_name" : "六宫粉黛无颜色",
	"damage_type":	"割伤"
]),
([	"action":"只见$N半个急转，使出"+HIG"「风吹仙袂飘飘举」"NOR+"，一声娇喝中剑光冲天而起，扫向$n的$l",
	"force" : 160,
           "dodge" : 5,
	"damage": 50,
	"lvl" : 18,
	"skill_name" : "风吹仙袂飘飘举",
	"damage_type":	"割伤"
]),
([	"action":"$N淡淡一笑，一式"+HIY"「犹似霓裳羽衣舞」"NOR+"舞出无数幻影，$n只觉得阵阵幽香四面袭来，却不知该如何闪躲",
	"force" : 180,
        "dodge" : 10,
	"damage": 100,
	"lvl" : 27,
	"skill_name" : "犹似霓裳羽衣舞",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w轻轻一抖，一式"+HIW"「在天愿作比翼鸟」"NOR+"幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
	"force" : 220,
        "dodge" : 15,
	"damage": 100,
	"lvl" : 36,
	"skill_name" : "在天愿作比翼鸟",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w再一抖，只见寒光点点，飘浮不定。\n这一招"+HIR"「在地愿为连理枝」"NOR+"只看得$n眼花缭乱，哪里还能招架",
	"force" : 260,
        "dodge" : 5,
	"damage": 120,
	"lvl" : 44,
	"skill_name" : "在地愿为连理枝",
	"damage_type":	"刺伤"
]),
([	"action":"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，剑心直指$n的后胸，正是一式"+MAG"「天长地久有时尽」"NOR,  
      	"force" : 320,
        "dodge" : 5,
	"damage": 125,
	"lvl" : 52,
	"skill_name" : "天长地久有时尽",
	"damage_type":	"刺伤"
]),
([	"action":"$N不闪不避，一式"+HIC"「此恨绵绵无绝期」"NOR+"，神色娴雅，蓄势待发，一道澄如秋水、寒似玄冰的剑光直指$n破绽所在",
	"force" : 380,
        "dodge" : 5,
	"damage": 140,
	"lvl" : 60,
	"skill_name" : "此恨绵绵无绝期",
	"damage_type":	"刺伤"
]),

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me) { return 1; }

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
	level   = (int) me->query_skill("changhen-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
        return action[0];
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练长恨剑法\n");
	me->receive_damage("qi", 25);
	return 1;
}
/* 去掉perform
string perform_action_file(string action)
{
	return __DIR__"changhen-jian/" + action;
}
*/
