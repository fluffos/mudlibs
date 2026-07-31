// huagong-dafa.c 化功大法
// By yucao
// Modified by cleansword
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i = (int)me->query_skill("huagong-dafa", 1);
    int t = 1, j;
    if(i <= 100)
        for (j = 1; j < i / 10; j++)
            t*= 2;
    if ( me->query("gender") == "无性" && i > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的化功大法。\n");
    if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("你的基本内功火候不足，不能学化功大法。\n");
    if(i<=100)
    {
        if (i > 10 && -(int)me->query("shen") < t * 60) 
            return notify_fail("学化功大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
    }
    else
    {
        if (-(int)me->query("shen") < (51200 + (i - 100) * 500)) 
            return notify_fail("学化功大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
    }
    if (me->query_skill("force",1)<i)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="huagong-dafa") continue;
        if (sname[i]=="taixuan-gong") continue;
       if (sname[i]=="jiuyin-xinjing") continue;
        if (sname[i]=="beiming-shengong") continue;
        if (sname[i]=="yijing-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学化功大法？！\n");
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("化功大法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"huagong-dafa/" + func;
}
