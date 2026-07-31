// literate.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
	return 1;
}


void skill_improved(object me)
{
    int s;
    s = me->query_skill("lifeskill", 1);

    if (s%30==0){
	tell_object(me, HIW "由於你的生活勤奋工作，综合素质得到了锻炼，你的"+HIY"【后天四维】"+NOR+"提高了。\n");
    }

}
