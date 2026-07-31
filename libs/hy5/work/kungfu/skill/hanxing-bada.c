//hanxing-bada.c 寒星八打
inherit SKILL;

mapping *action = ({
        ([      "action":"$N使一招「陨星乍现」，手中$w疾射$n的$l",
                "force": 120,
                "dodge": 20,
                "damage":390,
                "lvl" : 0,
                "skill_name" : "陨星乍现",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N使出「玉隼击空」，双手下沉$w陡的向上飞出直袭$n的$l",
                "force": 125,
                "dodge":  20,
                "damage": 350,
                "lvl" : 10,
                "skill_name": "玉隼击空",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N一招「暮霭沉沉」，长袖一挥，手中$w从腋下激射$n的$l",
                "force":135,
                "dodge": 30,
                "damage":340,
                "lvl" : 20,
                "skill_name": "暮霭沉沉",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N手中$w一式「长电裂空」，$w幻作一道白光直奔$n的$l",
                "force":140,
                "dodge": 40,
                "damage":360,
                "lvl" : 30,
                "skill_name": "长电裂空",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N纵身一跃，手中$w一招「苍龙入海」射向$n的$l",
                "force":150,
                "dodge": 40,
                "damage": 370,
                "lvl" : 40,
                "skill_name":"苍龙入海",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N手扣$w,凭空一指，一招「巴山夜雨」洒向$n的$l",
                "force":160,
                "dodge": 20,
                "damage":350,
                "lvl" : 50,
                "skill_name": "巴山夜雨",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N身形一晃，使一招「彗星横空」$w脱手而出，袭向$n的$l",
                "force":220,
                "dodge": 120,
                "damage":360,
                "lvl" : 60,
                "skill_name": "彗星横空",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
        ([      "action":"$N身形一转手中$w使一招「后弈射日」画出一道光弧袭向$n的$l",
                "force":270,
                "dodge": 130,
                "damage":360,
                "lvl" : 100,
                "skill_name": "后羿射日",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 100 )
                return notify_fail("你的内力不够，没有办法练寒星八打。\n");
       if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("你必须先找一些飞镖之类的东西才能练暗器。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" || usage=="parry";
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
        level = (int) me->query_skill("hanxing-bada",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 ||(int)me->query("neili") < 3 )
                return notify_fail("你的内力或气不够，没有办法练习寒星八打。\n")
;
        me->receive_damage("qi", 30);
        me->add("neili", -3);
        //write("你按著所学练了一遍寒星八打。\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hanxing-bada/" + action;
}

