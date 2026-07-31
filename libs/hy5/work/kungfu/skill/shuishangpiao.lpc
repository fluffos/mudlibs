// shuishangpiao.c based on zhaixinggong.c
// by zqb

inherit SKILL;

string *dodge_msg = ({
	"$n足跟一支，全身后仰，一招「鲤鱼倒穿波」，反窜出丈余，躲过了$N的攻击。\n",
	"$n身体忽然柔若无骨，左右摇摆，使出一招「雨打漂萍」，避过了$N的攻击。\n",
	"$n使出「物换星移」，滴溜溜一个转身，从$N身旁擦身而过，反而到了$N身后。\n",
        "$n一招「落叶随风」，身体如一片落叶一般飘了出去，身行之潇洒，迅速到了极处。\n"
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jing") < 40 )
                return notify_fail("你的体力太差了，不能练水上漂。\n");
	if (me->query_skill("shuishangpiao", 1) < 30)
	        me->receive_damage("jing", 10);
	else if (me->query_skill("shuishangpiao", 1) < 60)
		me->receive_damage("jing", 20);
	else 
		me->receive_damage("jing", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shuishangpiao/" + action;
}