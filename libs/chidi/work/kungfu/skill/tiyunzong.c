// tiyunzong.c 梯云纵
// written by Xiang
inherit SKILL;
string *dodge_msg = ({
    "只见$n一招「"+WHT+"白鹤冲天"+NOR+"」，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
    "$n一个「"+RED+"鹞子翻身"+NOR+"」，向后纵出数丈之远，避开了$N的凌厉攻势。\n",
    "$n使出「"+MAG+"大鹏展翅"+NOR+"」，向一旁飘然纵出，轻轻着地。\n"
});
int valid_enable(string usage) { return (usage == "dodge"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("tiyunzong", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        if (me) me->set_temp("fight/dodge",random(2*me->query_skill("tiyunzong",1)));
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练梯云纵。\n");
        me->receive_damage("qi", 30);
        return 1;
}

