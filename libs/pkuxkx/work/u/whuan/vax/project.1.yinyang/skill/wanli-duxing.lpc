inherit SKILL;
string *dodge_msg = ({
        "$n向后滑出，人影一晃之间，躲过了$N这一招。\n",
       "$n身形飘忽，转眼跃出数迟，躲了$N这一招。\n",
        "$N眼睛一花，定神一看，$n已没了踪影。。\n",
       
});
int valid_enable(string usage) { return (usage == "dodge"); }
int valid_learn(object me) { return 1; }
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练万里独行。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string query_yinyang()
{
	return "少阳";
}