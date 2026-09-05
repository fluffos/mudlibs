// datengnuo-bufa.c 大腾挪步法
inherit SKILL;
mapping *action = ({
([      "action" : "$n身形微晃已窜出，左足一点，身子平平飞渡，身法如鬼如魅，如风
如影，倏忽欺身到$N的身后。\n",
        "dodge"  : 10
]),
([      "action" : "$n足尖使劲，拔身而起，斜飞而上，如穿花蝴蝶般迅速飞舞，穿梭来
去，如行云流水，潇洒无比。\n",
        "dodge"  : 20
]),
([      "action" : "$n展开轻功，如一溜烟般绕到$N的身后，不待$N回身，左一向，又一
趋，正绕一圈，反转一圈，令$N无从下手。\n",
        "dodge"  : 30
]),
([      "action" : "$n双手作火焰飞腾之状，放在胸前，倒退后跃，在空中连翻几个空心
筋斗，气定神闲地落在$N的前面。\n",
        "dodge"  : 40
]),
([      "action" : "$n陡然身形拔起，在空中急速盘旋，连转四个圈子，愈转愈高，又是个
转折，轻轻巧巧地落在数丈之外。\n",
        "dodge"  : 50
]),
([      "action" : "$n踉踉跄跄地奔出数步，眼看就要跌倒，但就在这数步中，$n已经腾出
$N的招式攻击范围之外。\n",
        "dodge"  : 60
]),
([      "action" : "$n腾空一跃，待身形下落时，再用手一点地面，身形再度跃起，这几下
兔起鹘落，迅速无伦，令人神眩目弛。\n",
        "dodge"  : 70
]),
([      "action" : "$n足不抬，膝不屈，身体倏地后移，巧妙绝伦地躲开了$N的攻势，$n站在
$N数丈之外如渊停狱峙。\n",
        "dodge"  : 80
])
});
mapping query_action(object me)
{
        int zhaoshu, level;
        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("datengnuo-bufa",1);
        if (level < 60 )
                zhaoshu--;
        if (level < 50 )
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
/*
        object me, ob;
        mapping action;
        me = this_player();
        action = query_action(me);
        return action["action"];
*/
        return action[random(sizeof(action))]["action"];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练大腾挪步法。\n");
        if (me->query("family/family_name") != "明教")
        	return notify_fail("非明教弟子不能练大腾挪步法！\n");
        me->receive_damage("qi", 30);
        return 1;
}

   string perform_action_file(string action)
   {     return __DIR__"datengnuo-bufa/" + action;
 }

string query_yinyang()
{
	return "纯阳";
}