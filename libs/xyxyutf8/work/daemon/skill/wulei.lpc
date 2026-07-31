// wulei.c

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("spells") <= (int)me->query_skill("wulei") )
		return notify_fail("你的法术修为还不够高深，无法学习五雷正法。\n");
	return 1;
}

string cast_spell_file(string spell)
	{
return CLASS_D("suburb") + "/wulei/" + spell;
	}

string type() { return "magic";}

mixed base_damage(){ return 200;}