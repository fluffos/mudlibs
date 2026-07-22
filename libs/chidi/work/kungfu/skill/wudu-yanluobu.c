// wudu-yanluobu 五毒烟萝步
// inherit F_CLEAN_UP;
inherit SKILL;
string *dodge_msg = ({
"$n不慌不忙，一式「"+GRN"江水横流"NOR"」，身行倏的向一旁平移数尺,堪堪躲过了$N的功势。\n",
"$n身行如鬼魅般一晃，刹那间已远去数丈之外，$N顿时扑了个空。\n",
"$n身行忽的加快，如一缕青烟般绕着$N飞快旋转，看得$N一阵头晕眼花，\n急忙收招跳开。\n",
"只见$n身子向后一翻，一招「"+RED+"缥渺孤鸿影"+NOR+"」，后荡而起，掠向一旁。\n" ,
"$n怪异的一笑，身行忽的变得朦胧不清，$N的凌厉招式竟然透体而过，原来竟是一具幻影。\n",
"$n的身行顿时变得如蛇一般柔软，随着$N的招式左右摆动，竟使得$N招招落空。\n",
});

int practice_level(){   return 150;  }
int valid_enable(string usage) { return (usage == "dodge"); }
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("wudu-yanluobu", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("wudu-yanluobu",1)/2);
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力太差了，不能练五毒烟萝步。\n");
	me->receive_damage("qi", 20);
	return 1;
}
int valid_effect(object me, object weapon, string action_name, int skill)
{
	message_vision("你的体力太差了，不能练五毒烟萝步。\n",me);
}
string perform_action_file(string action)
{
	return __DIR__"wudu-yanluobu/" + action;
}
