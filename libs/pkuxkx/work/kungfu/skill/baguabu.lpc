// baguabu.c 八卦步
// written by lysh

inherit SKILL;

string *dodge_msg = ({
	"$n使出“天字决”，身形飘忽，足蹋乾位，恰好躲过$N一击。\n",
	"$n心念微动，一招“地字决”，猛然使出，甩$N一步走向坤位，使$N攻击落空。\n",
	"$n身体突缩，一招“水字决”，从$N腋下绕到$N身后，跺到坎位。\n",
        "$n一招“火字决”，腰一扭，跃向离位，$N攻击擦腰而过。\n",
	"$n身形微晃，退后一步，蹋至震位，一招“震字决”，刚好避开$N的攻击。\n",
	"$n一招“山字决”，身形一晃，倏忽之间已欺近丈余，脚蹋艮位，使$N的招数迟滞。\n",
        "$n身轻力足，宛如御风而行，一招“风字决”，身体已至巽位，使$N攻击尽数落空。\n"

});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("你的体力太差了，不能练八卦步。\n");
        me->receive_damage("qi", 20);
        return 1;
}

