inherit SKILL;

string *dodge_msg = ({
	"$n一个「似水流云」，躲过了$N这一招。\n",
	"$n身形突然平地拔起，一招「飘然若絮」，从容避过$N的攻击。\n",
	"$n微微一挫，一个「风起荷塘」，将$N的攻势化为乌有。\n",
        "$n以想象不到的角度，掠过$N身侧,衣诀飘飘，正是[大风起兮],$N顿时失去了你的方位!\n",
        "$n大袖一挥，蓦的退出三丈之外，然后又突然直欺上来，原来$n使了个[飘忽如柳]\n",
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
        if( (int)me->query("qi") < 60 )
                return notify_fail("你现在真气不够，练不了[流云飞步]\n");
        me->receive_damage("qi", 30);
        return 1;
}

