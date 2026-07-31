inherit SKILL;
string *dodge_msg = ({
    "$n身子一晃，脚踏无常方位，轻轻巧巧的躲开了$N凌厉无比的攻击。\n",
    "$n对$N的攻击视而不见，直到$N的招式近身才不慌不忙的向左迈出一步，竟然毫发无伤。\n",
    "只见$n左踏五行位置，右踩太白虚浮，身形潇洒如园中散步般躲开了$N一招又一招。\n"
});
int valid_enable(string usage) { return (usage == "dodge"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("lingyunbu", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
     if (me) me->set_temp("fight/dodge",me->query_skill("lingyunbu",1)+random(me->query_skill("lingyunbu",1)));
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练习凌云步法。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
    return __DIR__"lingyunbu/" + action;
}


