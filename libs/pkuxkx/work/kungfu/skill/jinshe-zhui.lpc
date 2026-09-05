// jinshe-zhui.c

inherit SKILL;

mapping *action = ({
        ([      "name":		"千变万化",
                "action":"$N双手一晃，一招「千变万化」，手中的$w幻出万道金光，
如一条金龙般飞向$n的$l",
                "dodge":	-20,
                "force":	200,
                "damage":	300,
		"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "name":		"奇诡莫测",
                "action":"$N右手一抖，一道金光冒出，只一刹那间，左手$w迅雷般越
过右手的$w，正是一招「奇诡莫测」，抢先飞向$n的$l",
                "dodge":	-40,
                "force":	300,
                "damage":	400,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够，没有办法练金蛇锥法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("你必须先找一些暗器才能练金蛇锥法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if (me->query("family")) return 0;
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 500 )
                return 
notify_fail("你的内力或气不够，没有办法练习金蛇锥法。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -30);
//       write("你按著所学练了一遍金蛇锥法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-zhui/" + action;
}
 
