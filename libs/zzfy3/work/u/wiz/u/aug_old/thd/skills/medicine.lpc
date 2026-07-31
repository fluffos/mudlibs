// medicine.c

inherit SKILL;

string name()
{
	return "medicine";
}

void create()
{
	seteuid(getuid());
	DAEMON_D->register_skill_daemon(name());
}

string type() { return "knowledge"; }

// literate is not limited by any level or skill level
void skill_improved(object me)
{
	int skill, learn;

	skill = me->query_skill("medicine", 1);
	learn = me->query_learn("medicine", 1);

	if( (skill<200) && (skill+10) * (skill+10) * (skill+10)/100 < learn ) {
		me->advance_skill("medicine", 1);
		me->gain_score("medicine", (skill+1) * 30);
	}
}
