// Qinglian-jian.c 青莲神剑
// Cracked by 凌惊雪 2-7-2003

#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "name":         "花间一壶酒",
                "action":       "$N使出青莲神剑中的"+HIG"「花间一壶酒」"NOR+"$N已仿佛与天地在一起。",
                "dodge":        -5,
                "parry" :       -10,
	        "damage" :      20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "白首卧松云",
                "action":       "$N使出青莲神剑中的"+HIG"「白首卧松云」"NOR+"，$N立时乘机而入",
                "dodge":        -5,
                "parry" :       -10,
	        "damage" :      20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "玲珑望秋月",
                "action":       "$N举剑过头，剑意若有若无，$w剑尖遥指$n。使出青莲神剑中的"+HIG"「玲珑望秋月」"NOR,
                "dodge":        -5,
                "parry" :       -10,
	        "damage" :      20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "吹度玉门关",
                "action":       "$N使出青莲神剑中的"+HIG"「吹度玉门关」"NOR+"，不慌不忙，$N横手一提，又拿住剑柄，剑光一盎，又罩向$n",
                "dodge":        -15,
                "parry" :       -20,
	        "damage" :      20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "落叶秋风早",
                "action":       "$n感觉到剑势,铺天盖地的涌压而来，正是青莲神剑中的"+HIG"「落叶秋风早」"NOR+"",
                "dodge":        -25,
                "parry" :       -20,
	        "damage" :      20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "床前明月光",
                "action":       "$N使出青莲神剑中的"+HIG"「床前明月光」"NOR+"，以声音、吸引住$n，使$n坠入了沉睡之中",
                "dodge":        -45,
                "parry" :       -30,
	        "damage" :      20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "苍茫云海间",
                "action":       HIW"\n$N只觉真似天河一般壮丽的气势，剑意若有若无，剑光一盎，\n"+
"$N使出青莲神剑中的"+HIG"「苍茫云海间」"HIW+"，攻向$n，\n"HIW+"$n被壮丽的气势所吸引，沉浸在$N的剑意之中。"NOR,
                "dodge":        -70,
                "parry" :       -70,
	        "damage" :      150,
	        "damage" :      150,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "床前明月光",
                "action":       HIW"$N使出青莲神剑中的"+HIG"「床前明月光」"NOR+HIW"，以声音、吸引住$n，使$n坠入了沉睡之中"NOR,
                "dodge":        -30,
                "parry" :       -30,
				"damage" :      80,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "落叶秋风早",
                "action":       HIW"$n感觉到剑势,铺天盖地的涌压而来，正是青莲神剑中的"+HIG"「落叶秋风早」"NOR+HIW""NOR,
                "dodge":        -25,
                "parry" :       -20,
	        "damage" :      100,
                "damage_type":  "刺伤"
        ]),


});
int valid_learn(object me)
{
        object ob;

    
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练青莲神剑。\n");

        if( (string)me->query_skill_mapped("force")!= "wuzheng-force")
                return notify_fail("青莲神剑必须配合无争心法才能练。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}


mapping query_action(object me, object weapon)
{
	int i = me->query_temp("QLJ");
	if( !me->query_temp("QLJ") ) {
        return action[random(6)];
	}
	else
	{
	return action[i];
	}
}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 10)
                return notify_fail("你的体力不够练「青莲神剑」。\n");
        if ((int)me->query("force") < 10)
                return notify_fail("你的内力不够练「青莲神剑」。\n");
        me->receive_damage("kee", 10);
        me->add("force", -10);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("sanxian") + "/qinglian-jian/" + func;
}
