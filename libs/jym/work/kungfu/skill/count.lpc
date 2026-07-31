
// count.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "桃花岛"|| myfam["master_id"] != "huang yaoshi")
                return notify_fail("只有黄药师的弟子才能学阴阳八卦。\n");
        if( (int)me->query_skill("literate",1) < 50 )
                return notify_fail("你的读书写字太低，没有办法学阴阳八卦。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("阴阳八卦只能用学(learn)的来增加熟练度。\n");
}
