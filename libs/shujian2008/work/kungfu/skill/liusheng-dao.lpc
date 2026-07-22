// liushen-dao.c 柳生流忍刀
// By snowman@SJ 25/01/2000

inherit SKILL;

string *action = ({
"$N使一式「春风」，将手中$w化为流风一般，看似轻飘飘地抚向$n的$l",
"$N使一式「夏风」，手中$w化为狂风暴雨一般，猛然砍向$n的$l",
"$N使一式「秋风」，将$w运劲一抖，化出片片刀光，如落叶般飘向$n的$l",
"$N使一式「冬风」，将$w一转，猛地一下直劈$n的$l，快绝无比，避无可避",
"$N使一式「朝风」，凝神聚力，$w出招点向$n，如同中原武功一般，讲究稳，轻，灵，快",
"$N使一式「夕风」，在$w递出招完将尽时伸指一弹刀刃，哗的一声转向$n的$l",
"$N使一式「疾风」，手中$w中宫向$n的$l一点，实在快如流风，令$n无从躲避",
"$N使一式「神风」，快速舞动手中$w化为无形，大喝一声：“Kamikaze！”冲向$n",
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 100)
               return notify_fail("你的内力不够。\n");
       if (! me->query("wizard_agree") )
               return notify_fail("你不能学习该武术。\n");
       if ((int)me->query_skill("force", 1) < 20)
               return notify_fail("你的忍术火候太浅。\n");
       return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":action[random(sizeof(action))],
                "damage": me->query_skill("blade")/4+random(100),
                "damage_type": "割伤",
                "dodge": random(25),
                "parry": 10,
                "force": me->query_skill("force")/2+random(me->query_skill("force")/2),
        ]);
}

int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "blade")
               return notify_fail("你使用的武器不对。\n");
       if ((int)me->query("jingli") < 30)
               return notify_fail("你的精力不够练柳生流忍刀。\n");
       me->receive_damage("jingli", 20);
       return 1;
}
string perform_action_file(string action)
{
        return __DIR__"renshu/" + action;
}
