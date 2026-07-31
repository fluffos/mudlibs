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
    s = me->query_skill("literate", 1);

    if (s%10==0){
	tell_object(me, HIW "由於你的勤学苦读，你的"+HIY"【后天悟性】"+NOR+"提高了。\n");
    }

}
