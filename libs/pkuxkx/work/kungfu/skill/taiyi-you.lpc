//taiyi-you   太乙神游
//by zoom
//2003.4.6
//Modified by iszt@pkuxkx, 2007-04-02, allowed level 100
// 2009.8.17 finished by zgbl

inherit SKILL;

string *dodge_msg = ({
		"只见$n长袖一挥，身子凌虚腾起，$N这一招堪堪落空。\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me)
{
	if ((int)me->query("family"))
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
	if (me->query_skill("hunyuan-yiqi",1) > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("betrayer") > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("chushi"))
  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法学习，纯百姓技能
        return 1; 
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if ((int)me->query("family"))
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if( (int)me->query("qi") < 60 )
        return notify_fail("你的精力太差了，不能练太乙神游。\n");
    if (me->query("betrayer") > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("chushi"))
  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
	if (me->query_skill("hunyuan-yiqi",1) > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法练习，纯百姓技能
        me->receive_damage("qi", 40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"taiyi-you/" + action;
}
