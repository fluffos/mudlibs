// jinyan-gong.c 金雁功
// By Lgg,1998.10

inherit SKILL;

string *dodge_msg = ({
	"$n足尖在地面一点，身形拔地而起，躲开了这一招。\n",
	"却不料$n身形一转，突然转到了$N的身后。\n",
	"$n随着$N攻来的招式飘了起来，就如一片微风中的柳絮一般。\n",
	"$n身形左一晃、右一闪，不知怎么的，从攻击的间隙中钻了出来。\n",
	"$n足不点地地围绕$N连绕三个大圈，把$N这一招避了开去。\n",
	"$n连旋数个大圈，跟着又是一个大圈，身形高高地拔了起来。\n",
});

int valid_enable(string usage)
{
	return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
  { 
     if (me->query_skill("dodge",1) <= me->query_skill("jinyan-gong",1) )
	return notify_fail("你的基本轻功基础不够，无法领会更高深的金雁功。\n");
    else    return 1;
  }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 )
		return notify_fail("你的体力太差了，不能练习金雁功。\n");

	me->receive_damage("qi", 40);
	return 1;
}
