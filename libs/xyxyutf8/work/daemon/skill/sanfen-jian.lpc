#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N面露微笑，手中$w一抖，剑光暴长，洒向$n的$l",
        "$N身形突闪，剑招陡变，手中$w从一个绝想不到的方位斜刺向$n的$l",
        "$N暴退数尺，低首抚剑，随后手中$w骤然穿上，刺向$n的$l",
        "$N身形一晃，疾掠而上，一招「神驼骏足」，手中$w龙吟一声，对准$n的$l连递数剑",
        "$N神色微变，一招「风卷长草」，剑招顿时变得凌厉无比，手中$w如匹链般洒向$n的$l",
        "$N缓缓低首，接着一招「举火燎天」，手中$w中宫直进，迅捷无比地往$n的$l刺去",
        "$N矮身侧步，一招「大漠孤烟」，手中$w反手疾挑而出，“唰”的一声往$n的$l刺去",
        "$N蓦地疾退一步，又冲前三步，一招「平沙落雁」，手中$w化为一道弧光往$n的$l刺去",
        "$N纵身跃起，一招「雪中奇莲」，不见踪影，接着却又从半空中穿下，$w直逼$n的$l",
        "$N一招「千里流沙」，手中$w遥指苍空，猛然划出一个叉字，往$n的$l刺去",
        "$N一招「冰河倒泻」，左手虚击，右手$w猛的自下方挑起，激起一股劲风反挑$n的$l",
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if ((int)me->query_maxforce() < 700)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("force") < 90)
                return notify_fail("你的内功火候太浅。\n");
        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("你的基本剑法火候不够，无法学习三分剑术。\n");
        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("sanfen-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的三分剑术。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int damage,parry,dodge,lvl;
	if( !me )
		return ([
                	"action": action_msg[random(sizeof(action_msg))],
                	"damage": 20,
                	"dodge" : 50,
                	"parry" : 50,
                	"damage_type" : random(2)?"刺伤":"割伤",
        	]);
        lvl = me->query_level();
        damage = (lvl+1)*6;
        parry = 70-lvl;
        dodge = 100-lvl;
	return ([
         	"action": action_msg[random(sizeof(action_msg))],
                "damage": damage,
		"dodge" : dodge,
		"parry" : parry,
		"damage_type" : random(2)?"刺伤":"割伤",
	]);
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力目前没有办法练习三分剑术。\n");

        if ((int)me->query("force") < 70)
                return notify_fail("你的内力不够，无法练习三分剑术。\n");
        
        me->add("kee", -50);
        me->add("force", -62);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("sword")+"/sanfen-jian/" + action;
}
