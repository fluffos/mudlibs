// baguabu.c 奇门八卦阵
// written by lysh

inherit SKILL;

string *dodge_msg = ({
	"$n身形飘忽，足蹋乾位，恰好躲过$N一击。\n",
	"$n心念微动，甩$N一步走向坤位，使$N攻击落空。\n",
	"$n身体突缩，从$N腋下绕到$N身后，跺到坎位。\n",
    "$n腰一扭，跃向离位，$N攻击擦腰而过。\n",
	"$n身形微晃，退后一步，蹋至震位，刚好避开$N的攻击。\n",
	"$n身形一晃，倏忽之间已欺近丈余，脚蹋艮位，使$N的招数迟滞。\n",
    "$n身轻力足，宛如御风而行，身体已至巽位，使$N攻击尽数落空。\n",
	"$n身板一缩，诡异非常，却是退入了巽，避开了一招。\n"

});

int valid_enable(string usage) 
	{ 
		return usage=="dodge"; 
	}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
/*        if( (int)me->query("qi") < 100 )
            return notify_fail("你的体力太差了，不能练习奇门八卦阵。\n");
        if( (int)me->query("jing") < 100 )
            return notify_fail("你的精力不济，不能练习奇门八卦阵。\n");
		if ((int)me->query("neili") < 100)
		    return notify_fail("你的内力太低，无法练习奇门八卦阵。\n");
		me->receive_damage("qi", 50);
		me->add("jing",-30);
		me->add("neili",-30);*/
        return notify_fail("这么功夫不能通过练习来提升。\n");;
}

string perform_action_file(string action)
   {     return __DIR__"qimen-baguazhen/" + action;
 }

/*string query_parry_msg(object weapon)
{
      return parry_msg[random(sizeof(parry_msg))];
    
}*/