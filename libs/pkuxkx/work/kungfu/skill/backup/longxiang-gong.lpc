// longxiang-gong.c 雪山 龙象般若功

inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
        int i, nb, nf, nh, ns, ts;
        nb = (int)me->query_skill("buddhism", 1);
        nf = (int)me->query_skill("force", 1);
        nh = (int)me->query_skill("longxiang-gong", 1);
        ns = (int)me->query("guilty");

        if ( me->query("gender") != "男性" )
                return notify_fail("你非纯阳体质，不能练习龙象般若功。\n");

        if (!undefinedp(me->query("marry")) && me->query_skill("longxiang-gong",1) >79 )
                return notify_fail("你非童男之身，不能继续修习龙象般若功。\n");

        if ( nb < 100 && nb <= nh )
                return notify_fail("你的密宗心法修为不够，无法领会更高深的龙象般若功。\n");

        if ( nf < 10)
                return notify_fail("你的基本内功火候还不够，无法领会龙象般若功。\n");

        //if ( ns > 0 ) 
        //        return notify_fail("你屡犯僧家数戒，无法领会更高深的龙象般若功。\n");

        return 1;
}


int practice_skill(object me)
{
        return notify_fail("龙象般若功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"longxiang-gong/" + func;
}
