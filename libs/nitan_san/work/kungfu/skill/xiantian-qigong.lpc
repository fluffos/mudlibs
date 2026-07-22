// xiantian-gong.c 先天气功
// by Lonely

inherit FORCE;

int valid_force(string force) { return 1; }       

int query_neili_improve(object me)  
{
        int lvl; 
        lvl = (int)me->query_skill("xiantian-qigong", 1); 
        return lvl * lvl * 22 * 15 / 100 / 200; 
}

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("xiantian-qigong", 1);

        if (me->query("gender") == "无性")
                return notify_fail("你无根无性，阴阳不调，难以修行玄门正宗的先天气功。\n");

        if (me->query("class") == "bonze")
                return notify_fail(RANK_D->query_respect(me)+"欲修我道家玄门气功，怎又去入了佛门？\n");

        if (lvl <= 100)
        {
                if (lvl > 10 && (int)me->query("shen") < lvl * 100)
                        return notify_fail("你的侠义正气太低了。\n");
        }
        else
        {
                if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000))
                        return notify_fail("你的侠义正气太低了。\n");
        }

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("先天气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"xiantian-qigong/" + func;
}


