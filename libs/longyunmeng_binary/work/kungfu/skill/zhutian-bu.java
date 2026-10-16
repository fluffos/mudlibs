// zhutian-bu.c 诸天化身步

inherit SKILL;

mapping *action = ({
([      "action" : "$n一式「天地钩」，拔地而起，忽的一个空翻，飘然落在几丈远的地方。\n",
        "dodge"  : 10
]),
([      "action" : "$n一式「凤点头」，两臂鹏举如翼，如一阵清风，从$N头顶横跃而过。\n",
        "dodge"  : 20
]),
([      "action" : "$n一式「鹰爪松」，身体如一只苍鹰般腾空而起，舒缓地闪过了$N的凌厉攻势。\n",
        "dodge"  : 30
]),
([      "action" : "$n一式「风摆柳」，身体曼妙的轻轻摆动，横着飘出近一丈远\n",
        "dodge"  : 50
]),
([      "action" : "$n一式「阴阳箭」，双脚点地，全身化为一道白影，倏的拔地而起，令$N不敢仰视。\n",
        "dodge"  : 80
]),
([      "action" : "$n一式「日月扣」，身形陡地变得飘忽不定，流水般地滑出丈余。\n",
        "dodge"  : 110
]),
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("zhutian-bu");

        if (level < 80 )
                zhaoshu--;

        if (level < 60 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);

        return action["action"];
}

int practice_skill(object me)
{
        if( !me->query_skill("linji-zhuang",1))
                return notify_fail("练「诸天化身步」必须要以「临济十二庄」为基础。\n");


        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练「诸天化身步」。\n");
        me->receive_damage("qi", 30);
        return 1;
}

