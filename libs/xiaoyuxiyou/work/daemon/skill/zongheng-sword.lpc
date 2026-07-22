// Zongheng-sword.c 纵横剑法
// Cracked by 凌惊雪 5-4-2003

#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "name":         "纵横",
                "action":       "$N手中$w正正刺向$n，正是纵横剑法的起手式，"+HIG"「纵横」"NOR+"。",
                "dodge":        -10,
                "parry" :       -10,
	        "damage" :      50,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "风云天下",
                "action":       "$N手中$w突然间剑光一吐，化作一道白虹，气势大开大阂，正是纵横剑法的精要所在，一招"+HIG"「风云天下」"NOR+"向$n$l直刺过来",
                 "dodge":        -15,
                 "parry" :       -15,
	        "damage" :      55,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "日月同辉",
                "action":       "$N使出纵横剑法中的"+HIG"「日月同辉」"NOR+"，不慌不忙，$N横手一提，又拿住剑柄，剑光一盎，又罩向$n",
           "dodge":        -20,
           "parry" :       -20,
	        "damage" :      60,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "横扫六合",
                "action":       "$N只觉真似天河一般壮丽的气势，使出纵横剑法中的"+HIG"「横扫六合」"NOR+"，攻向$n",
               "dodge":        -20,
                "parry" :       -20,
	        "damage" :      70,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "纵横四海",
                "action":       "$n感觉到剑势,铺天盖地的涌压而来，正是纵横剑法中的"+HIG"「纵横四海」"NOR+"",
                "dodge":        -25,
           	"parry" :       -25,
	        "damage" :      80,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "纵字诀",
                "action":       HIR"$N身形突然向外直飞，陡然间剑光一吐，纵横剑法之"+HIG"「纵字诀」"HIR+"已如闪电惊虹般刺出，\n$N手中$w"HIR"化成一道血光，气壮雄浑，一股无匹的力量直向$n"HIR"$l直刺过来。"NOR,
                "dodge":        -30,
                "parry" :       -30,
	        "damage" :      90,
	        "force" :      150,
                "damage_type":  "刺伤"
        ]),
        ([      "name":         "横字诀",
                "action":       HIR"$N剑意若有若无，手中$w"HIR"突然消失，剑光一盎，$w"HIR"缓缓划出，剑气如浪，此招正是纵横剑法之"+HIG"「横字诀」"HIR+"，\n白茫茫一片光芒随着$N横划的$w"HIR"澎湃涌出，犹如海天一线，无懈可击，直逼$n"HIR"。"NOR,
                "dodge":        -50,
                "parry" :       -50,
	        "damage" :      80,
	        "force" :      180,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

    
        if( (int)me->query("max_force") < 2000 )
                return notify_fail("你的内力不够，没有办法练纵横剑法。\n");

        if( (string)me->query_skill_mapped("force")!= "brightjade-force")
                return notify_fail("纵横剑法必须配合明玉神功才能练。\n");

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
	int i = me->query_temp("ZHJ");
	if( !me->query_temp("ZHJ") ) {
        return action[random(5)];
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
        if ((int)me->query("kee") < 100)
                return notify_fail("你的体力不够练「纵横剑法」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「纵横剑法」。\n");
        me->receive_damage("kee", 30);
        me->add("force", -30);
        return 1;
}
string perform_action_file(string func)
{
	return CLASS_D("baihuagu") + "/zongheng-sword/" + func;
}
