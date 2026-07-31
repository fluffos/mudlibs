// By Jungu

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
         if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够，无法领会神元功。\n");
        if ( me->query_skill("bibo-shengong",1)
        || me->query_skill("beiming-shengong",1)
        || me->query_skill("bahuang-gong",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("longxiang",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("jiuyang-force",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("zixia-shengong",1) 
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("wuji-shengong",1)
        || me->query_skill("guiyuan-dafa",1)
        || me->query_skill("xiantian-wuji",1)
        || me->query_skill("yunu-xinjing",1)
          || me->query_skill("tiangang-zhangqi",1))
                return notify_fail("你不先散了别派内功，怎能学神元功？！\n");
                
        return 1;
}

int practice_skill(object me)
{
    return notify_fail("神元功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
    return __DIR__"shenyuan-gong/" + func;
}

