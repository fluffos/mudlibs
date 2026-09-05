inherit SKILL;
mapping *action = ({
        ([      "action":               "$N挥剑向天，一股淡淡的蓝烟从$w上缓缓升起,将$n浑身上下笼罩起来，\n
$n只觉得一股强大无匹的力量向自己袭来！",
                "force":                120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N手中的$w微微一振，看似轻灵，却蕴涵着无穷的杀机，袭向$n的$l",
                "force":                100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N手中的$w幻成一片绿澜，忽聚忽散地飘向$n的$l",
                "force":                100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":    "$N晃动手中的$w，剑光忽隐忽现，象秋风中的落叶，将$n的身体笼罩在无穷无尽的剑茫之中\n",
                "force":                90,
                "damage_type":  " 刺伤"
        ]),
       ([      "action":               "$N，手中的$w吐出一线金光，$n立刻感到胸口上似有千斤的巨石，喘不过气来。\n",
             "damage_type":  "刺伤"
        ]),
});

int valid_enable(string usage)
{
        return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}


string *parry_msg = ({
        "$n慢慢地将手中的$v立于身前，刚猛的剑气将$N逼得连退几步。\n",
});

string *unarmed_parry_msg = ({
        "$n手中的$v慢慢地挥出，剧烈颤动的剑锋封向$N。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
 else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_learn(object me)
{
        if(me->query("gender")!="男性"||(int)me->query("shen")<10000)
notify_fail("你不能练英雄剑法。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        return 1;
}

int practice_skill(object me)
{
        object weapon;
      if (!objectp(weapon = me->query_temp("weapon"))||(string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if(me->query("gender")!="男性"||(int)me->query("shen")<10000)
                return notify_fail("你不能练英雄剑法\n");
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力不够练英雄剑法。\n");
        me->receive_damage("qi", 30);
        return 1;
}
string perform_action_file(string action)
{
  return __DIR__"hero-jianfa/" + action;
}
