//【丧魂刀法】sanghun-dao.c

/*
丧魂刀诡异绝伦，刀走偏锋，令人防不胜防，而偏又威猛无比，
下手绝不留情。
胖头陀当年持此刀法曾重创洪教主
*/

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "魂飞魄散",
                "action":
CYN"$N发出一声怒吼，手中"+"$w"+CYN+"狂风骤雨般地向$n的的全身，正是一招「魂飞魄散」"+NOR,
                "dodge":                15,
		"parry":		-10,
                "damage":               30,
                 "lvl":0,
                "damage_type":  "劈伤"
        ]),
        ([      "name":                 "怨鬼无常",
                "action":               
WHT"$N身形一转，面带戚色，一招「怨鬼无常」使出，手中"+"$w"+WHT+"好像勾魂戾鬼紧紧将$n，罩在当中"+NOR,
                "dodge":                -15,
		"parry":		-20,
                "damage":               50,
                "lvl":12,
                "damage_type":  "劈伤"
        ]),
       ([      "name":                 "寒夜磷海",
                "action":
HIM"$N舞动"+"$w"+HIM+"一声怪笑，一招「寒夜磷海」使出, 但见刀光突然大盛，夹着点点磷光刺向$n的$l"+NOR,
                "dodge":                10,
		"parry":		0,
                "damage":               60,
                 "lvl":25, 
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "荒野孤坟",
                "action":
YEL"$N面露哀怜神情，手中"+"$w"+YEL+"却轻轻一挥，刀光掩映之下更显得凄清诡异，「荒野孤坟」"+NOR,
                "dodge":                -10,
		"parry":		-10,
                "damage":               80,
                 "lvl":40,  
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "碧月阴风",
                "action":
HIG"$N身形一转，手中"+"$w"+HIG+"突然反转以刀背击出，发出青绿惨淡之光，\n一招「碧月阴风」带着森森鬼气砸向$n$l"+NOR,
                "dodge":                -5,
		"parry":		0,
                "damage":               90,
                 "lvl":55,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "阎罗索命",
                "action":
BLU"$N喉咙里发出一声嚎叫，须眉尽张，手中"+"$w"+BLU+" 舞动如风车相仿，无坚不摧的片片刀气罩住$n 全身，正是「阎罗索命」"+NOR,
                "dodge":                5,
		"parry":		-20,
                "damage":               95,
                "damage_type":  "劈伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("dulong-dafa") < 50 )
        return notify_fail("你的毒龙大法修为不够，不能学习丧魂刀法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀来才能练丧魂刀法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
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
    level   = (int) me->query_skill("sanghun-dao",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("jingli") < 50)
   return notify_fail("你的体力不够练丧魂刀法。\n");
    me->receive_damage("jingli", 35);
    return 1;
}



void skill_improved(object me)
{
    if( -(int)me->query_skill("sanghun-dao", 1)  * 100 <me->query("shen")) {
                tell_object(me,
                  RED "\n你突然觉得杀意无法遏制，一股心火直上脑海....\n\n" NOR);
          me->unconcious();
        }
      }

