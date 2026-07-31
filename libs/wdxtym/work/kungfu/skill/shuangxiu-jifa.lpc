// chuancai-jiyi.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "loveing" ||  usage == "parry"; }

int valid_learn(object me)
{
    return 1;
}



int practice_skill(object me)
{
	object cailiao;

	
	me->receive_damage("qi", 40);
	me->receive_jing("jing", 40);
	cailiao->add_amount(-1);

	return 1;
}

