// xuehai-mogong.c 血海魔功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int query_neili_improve(object me)   
{
        int lvl;  
        lvl = (int)me->query_skill("longxiang-banruo", 1);  
        return lvl * lvl * 21 * 15 / 100 / 200;  
}

int valid_force(string force) { return 1; }        

int practice_skill(object me)
{
        return notify_fail("血海魔功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"xuehai-mogong/" + func;
}

int valid_learn(object me)
{
        int i = (int)me->query_skill("xuehai-mogong", 1);
        int t = (int)me->query_skill("lamaism", 1);

        if ((string)me->query("class") != "bonze")
                return notify_fail("你不是喇嘛，学不了高深的血海魔功。\n");

        if ( me->query("gender") == "无性" )
                return notify_fail("你无根无性，阴阳不调，难以领会高深的血海魔功。\n");
          
        if (i < 200 && t <= i)
                return notify_fail("你的密宗心法修为不够，无法领会更高深的血海魔功。\n");

        return ::valid_learn(me); 

}


