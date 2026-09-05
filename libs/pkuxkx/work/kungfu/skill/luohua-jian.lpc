//落花十三剑，红花会剑法
// by whuan
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([	"action" : "$N凌空飞起，挽了一个剑花，一招"GRN"「水面风回聚落花」"NOR"，剑光四射就如同千万点寒星，向$n当头洒下",
	"force" : 120,
	"dodge" : 20,
	"damage" : 30,
  "lvl" : 0,
  "skill_name"  : "水面风回聚落花",        	
	"damage_type" : "刺伤"
]),
([	"action" : "$N蓦的向前一纵身，左手单掌护胸，右手手腕一沉，$w向上反撩，一式"HIY"「闲敲棋子落灯花」"NOR"划向$n的$l",
	"skill_name"  : "闲敲棋子落灯花",
	"force" : 140,
	"dodge" : 15,
	"damage" : 40,
  "lvl" : 20,
	"damage_type" : "刺伤"
]),
([	"action" : "$N口中轻叱一声，手中$w向下一点，身形向上拔起丈余，一招"BLU"「骏马行桥踏落花」"NOR"$w居高临下如闪电般刺向$n的$l",
	"skill_name"  : "骏马行桥踏落花",
	"force" : 170,
	"dodge" : 15,
	"damage" : 50,
  "lvl" : 50,
	"damage_type" : "刺伤"
]),
([	"action" : "$N双脚不丁不八，身形稳如泰山，左手微屈捏成剑决，右手$w轻颤，一式"MAG"「江城五月落梅花」"NOR"，只见满天银光纷纷点点罩向$n的$l",
	"skill_name"  : "江城五月落梅花",
	"force" : 190,
	"dodge" : 10,
	"damage" : 60,
  "lvl" : 70,
	"damage_type" : "刺伤"
]),
([	"action" : "$N长吸一口真气，一招"RED"「银烛光摇半夜花」"NOR"，右手$w摇曳不定，似有似无地刺向$n",
	"lvl"    : 80,
	"skill_name"  : "银烛光摇半夜花",
	"force" : 240,
	"dodge" : 10,
	"damage" : 75,
	"damage_type" : "刺伤"
]),
([	"action" : "$N双目直视$n，左手疾伸，与右手同时握住$w，剑随意动，一招"HIC"「犹为离人照落花」"NOR"，$w大开大阖，向$n的$l直劈过去",
	"lvl"    : 90,
	"skill_name"  : "犹为离人照落花",
	"force" : 280,
	"dodge" : 5,
	"damage" : 85,
	"damage_type" : "刺伤"
]),
([	"action" : "只见$N左穿右插，剑光闪烁不定，一招"HIM"「更持红烛赏残花」"NOR"，$w极快地划出一个光圈，“呜..呜..”作响，奔向$n的$l",
	"lvl"    : 100,
	"skill_name"  : "更持红烛赏残花",
	"force" : 300,
	"dodge" : 5,
	"damage" : 95,
	"damage_type" : "刺伤"
]),
([  "action" : "$N身形稍挫，一招"HIG"「春城无处不飞花」"NOR"反手击出，只听“嗤”的一声，一道青光射向$n的$l",
	"lvl"    : 110,
	"skill_name"  : "春城无处不飞花",
	"force" : 380,
	"dodge" : -5,
	"damage" : 135,
	"damage_type" : "刺伤"
]),
([  "action" : "$N一声清叱，剑光暴长，一招"HIW"「光摇银海眩生花」"NOR"，攻势突发，手中$w有如长江大河，滚滚而上，涌向$n的$l",
	"lvl"    : 130,
	"skill_name"  : "光摇银海眩生花",
	"force" : 380,
	"dodge" : -5,
	"damage" : 140,
	"damage_type" : "刺伤"
]),
([  "action" : "$N一声长啸，右臂一振，一招"HIR"「长日临池看落花」"NOR"，手中$w作龙吟之声脱手而出，$n只觉一道凌厉的剑气扑面而来",
	"lvl"    : 150,
	"skill_name"  : "长日临池看落花",
	"force" : 380,
	"dodge" : -5,
	"damage" : 150,
	"damage_type" : "刺伤"
]),
([  "action" : "$N身躯一转，一招"HIW"「月明残雪映梅花」"NOR"，内力急吐，$w上突地涨出尺余长的剑芒呼呼作响,划向$n的$l",
	"lvl"    : 160,
	"skill_name"  : "月明残雪映梅花",
	"force" : 380,
	"dodge" : -5,
	"damage" : 160,
	"damage_type" : "刺伤"
]),
([  "action" : "$N双眉一扬，眼中杀气大盛，一招"HIM"「化作春泥更护花」"NOR"，左脚脚尖点地，右脚迅速向前踏出一步，只见$N与手中$w合而为一，直奔$n而去",     
	"lvl"    : 170,
	"skill_name"  : "化作春泥更护花",
	"force" : 380,
	"dodge" : -5,
	"damage" : 165,
	"damage_type" : "刺伤"
]),
([  "action" : "$N抱元守一，运力于臂，一招"HIR"「人间处处有红花」"NOR"，只见剑光闪闪，四下里剑气纵横，$n几乎要透不过气来",
	"lvl"    : 180,
	"skill_name"  : "人间处处有红花",
	"force" : 380,
	"dodge" : -5,
	"damage" : 180,
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("bingchuan-xinfa", 1) < 20)
		return notify_fail("你的冰川心法火候太浅。\n");
		return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
  level  = (int)me->query_skill("luohua-jian",1);
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
	if ((int)me->query("qi") < 35)
		return notify_fail("你的体力不够练。\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"luohua-jian/" + action;
}

string *parry_msg = ({
        "只见$n双手横劈，将手中$v舞得飕飕风响，顿时格开了$N的$w。\n",
        "$n使出「卸」字诀，$v轻轻一点，$N的$w好象打在棉絮中，对$n毫无伤害。\n",
        "$n侧身闪避，双足急点，跃在半空，手中$v立时回撤，迅即挑出，$N的$w一下就偏了出去。\n",
        "$n左手往右手贯劲，左手随发之际，右手往回带撤，用手中$v架开。\n",
        "但是$n身子稍侧，左臂反过来就是一剑，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，忽的后跃，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n向后跃开，然后蹑足上前，顺势后拉，$N就象打在一团棉絮中，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                  return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
