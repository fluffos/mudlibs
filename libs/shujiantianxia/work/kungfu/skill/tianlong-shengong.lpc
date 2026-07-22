inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{       
        
        int i, l;             
        i = (int)me->query_skill("qiantian-yiyang", 1);       
        l = (int)me->query_skill("buddhism", 1);       

   if (!me->query("tls"))
        if ((i >= 10 && (int)me->query("shen") < i * 5) ||
            (i >= 50 && (int)me->query("shen") < i * 8) ||
            (i >= 100 && (int)me->query("shen") < i * 10))
        return notify_fail("大理乃是明门正派，看来你的侠义正气还不够啊！\n");

        if (i > 10 && i < 150 && l < i - 10)
        return notify_fail("你的佛学修为看来不能抑止你的心中的好胜之心了！\n");

        if (me->query_skill("force", 1) < 20)
                 return notify_fail("你的基本内功火候还不够，无法领会乾天一阳功。\n");

        if (i > 99 && (string)me->query("gender") != "男性")
                 return notify_fail("你不是纯阳之身，无法领会更高层的乾天一阳功。\n");

        if ( 
           me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("guiyuan-tunafa",1)
        || me->query_skill("xixing-dafa",1)
        )
        return notify_fail("乾天一阳功怎可和邪派内功混为一体？\n");

        return 1;
}


int practice_skill(object me)
{
            return notify_fail("乾天一阳功只能用学(learn)来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"qiantian-yiyang/" + func;
}
