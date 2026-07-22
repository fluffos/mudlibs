// guimei-shanfa 鬼魅身法（五毒教）

inherit SKILL;

string *dodge_msg = ({
	"只见$n身影飘忽，闪烁不定，使$N的攻击全部落空。\n",
	"却见$n身形微晃，忽地飘开三尺，躲过了$N的攻击。\n",
	"$n收提气收力，身行急转，轻飘飘的让开了$N的这一招。\n"
        "$n身形如同鬼魅一般，变幻不定，眼花缭乱，让$N无法下手。\n",
    
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
                return notify_fail("你的体力太差了，不能练鬼魅身法。\n");
        me->receive_damage("qi", 30);
        return 1;
}