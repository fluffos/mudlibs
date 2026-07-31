// 武学修养

inherit SKILL;
/*
int valid_learn(object me)
{
        return notify_fail("武学修养是你武学方面的领悟，无法"
                           "通过简单学习获得提升。\n");
}

int valid_research(object me)
{
        return notify_fail("武学修养来自你对实战体会的汲取吸"
                           "收，无法通过研究提升。\n");
}
*/

string type() { return "knowledge"; }
void skill_improved(object me)
{
    int s;
    s = me->query_skill("martial-cognize", 1);
    if (s%10==0){
        tell_object(me, HIW "由於你的勤学苦练，你的武学修养提高了。\n" NOR);
    }
}