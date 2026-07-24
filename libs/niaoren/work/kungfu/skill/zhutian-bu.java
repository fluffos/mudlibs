// zhutian-bu.c 諸天化身步

inherit SKILL;

mapping *action = ({
([      "action" : "$n一式「天地鉤」，拔地而起，忽的一個空翻，飄然落在几丈遠的地方。\n",
        "dodge"  : 10
]),
([      "action" : "$n一式「鳳點頭」，兩臂鵬舉如翼，如一陣清風，從$N頭頂橫躍而過。\n",
        "dodge"  : 20
]),
([      "action" : "$n一式「鷹爪松」，身體如一只蒼鷹般騰空而起，舒緩地閃過了$N的凌厲攻勢。\n",
        "dodge"  : 30
]),
([      "action" : "$n一式「風擺\柳」，身體曼妙的輕輕擺\動，橫著飄出近一丈遠\n",
        "dodge"  : 50
]),
([      "action" : "$n一式「陰陽箭」，雙腳點地，全身化為一道白影，倏的拔地而起，令$N不敢仰視。\n",
        "dodge"  : 80
]),
([      "action" : "$n一式「日月扣」，身形陡地變得飄忽不定，流水般地滑出丈余。\n",
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
                return notify_fail("練「諸天化身步」必須要以「臨濟十二庄」為基礎。\n");


        if( (int)me->query("qi") < 40 )
                return notify_fail("你的體力太差了，不能練「諸天化身步」。\n");
        me->receive_damage("qi", 30);
        return 1;
}

