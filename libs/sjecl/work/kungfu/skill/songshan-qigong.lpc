// songshan-qigong.c 嵩山气功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
       if ((int)me->query_skill("force", 1) < 10)
               return notify_fail("你的基本内功火候还不够。\n");

       return 1;
}

int practice_skill(object me)
{
       if((int)me->query_skill("songshan-qigong", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("songshan-qigong", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("你现在的修为不足以提高嵩山气功了。\n");       }
        else return notify_fail("你现在的嵩山气功修为只能用学(learn)的来增加熟练度。\n");

}

string exert_function_file(string func)
{
       return __DIR__"songshan-qigong/" + func;
}
