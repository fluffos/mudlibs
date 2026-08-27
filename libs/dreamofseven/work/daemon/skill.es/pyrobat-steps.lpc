// pyrobat-steps.c

inherit SKILL;

string *dodge_msg = ({
	"但是$n身形飄忽﹐輕輕一縱﹐早已避開。\n",
	"$n身隨意轉﹐倏地往一旁挪開了三尺﹐避過了這一招。\n",
	"可是$n側身一讓﹐$N這一招撲了個空。\n",
	"卻見$n足不點地﹐往旁竄開數尺﹐躲了開去。\n",
	"$n身形微晃﹐有驚無險地避開了$N這一招。\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的體力太差了﹐不能練火蝠身法。\n");
	me->receive_damage("kee", 30);
	return 1;
}
