// xiaoyaoyou.c 逍遥游
// modified by Venus Oct.1997
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
    "$n一个「蜻蜓点水」，躲过了$N这一招。\n",
    "$n身形向后一纵，使出一招「细胸巧翻云」，避过了$N的攻击。\n",
    "$n使出「虚怀若谷」，恰好躲过了$N的攻势。\n"
});

int valid_enable(string usage)
{
    return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 40 )
   return notify_fail("你的体力太差了，不能练逍遥游。\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"xiaoyaoyou/" + action;
}

