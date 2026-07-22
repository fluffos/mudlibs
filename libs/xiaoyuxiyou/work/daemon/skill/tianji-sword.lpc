#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N使一式"HIM"「海天一线」"NOR"，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
        "damage": 30,
        "skill_name" : "海天一线",
        "damage_type":  "割伤"
]),
([      "action":"$N手中剑锵啷啷长吟一声，一式"HIM"「咫尺天涯」"NOR"，一道剑光飞向$n的$l",
        "damage": 20,
        "skill_name" : "咫尺天涯",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"HIM"「怒剑狂花」"NOR"，手中$w舞出无数剑花，使$n难断虚实，无可躲避",
        "damage": 30,
        "skill_name" : "怒剑狂花",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"HIM"「漫天风雪」"NOR"，手腕急抖，挥洒出万点金光，刺向$n的$l",
        "damage": 35,
        "skill_name" : "漫天风雪",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"HIM"「天河倒泻」"NOR"，$w飞斩盘旋，如疾电般射向$n的胸口",
        "damage": 40,
        "skill_name" : "天河倒泻",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"HIM"「天外飞仙」"NOR"，$w突然从天而降，一片金光围掠$n全身",
        "damage": 30,
        "skill_name" : "天外飞仙",
        "damage_type":  "刺伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        object ob;

          if( me->query("gender") != "女性" )  

                return notify_fail("天击剑只有女子能学。\n");
//       if (me->query("betray/count")) 
//            return notify_fail("你求学之心不专，无缘学天击剑。\n"); 
       if(me->query("family/family_name") != "娥眉")
            return notify_fail("这是仙家绝学,你是从什么地方偷学的呢?\n"); 
        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练天击剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习天击剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍天击剑法。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string perform_action_file( string action) 
{ 
     return CLASS_D("emei") + "/tianji-sword/" + action; 
} 
