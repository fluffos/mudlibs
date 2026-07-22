// 五毒神功

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	mapping skl;
	string *sname;

	if ( (int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候还不够，无法领会五毒神功。\n");
        skl = me->query_skills();
        sname = keys(skl);
        
	 for (int i=0;i<sizeof(skl);i++){
	    if(sname[i] == "wudu-shengong") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
             return notify_fail("你不先散了别派内功，怎能学五毒神功？！\n");
    }

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("五毒神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"wudu-shengong/" + func;
}
