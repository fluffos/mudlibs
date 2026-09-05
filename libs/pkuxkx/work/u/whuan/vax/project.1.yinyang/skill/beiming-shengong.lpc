// beiming-shengong.c 北冥神功.c
// by paladin

// inherit SKILL;
inherit FORCE;

int valid_enable(string usage) { return usage == "force" ||(usage == "parry");}
int valid_learn(object me)
{
        mapping fam;
            if (!(fam = this_player()->query("family"))|| fam["family_name"] != "天龙寺")
             return notify_fail("你不是天龙寺的弟子，不能学习北冥神功。\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("你的基本内功火候不足，不能学北冥神功。\n");
        if ( me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("huntian-qigong",1)
          || me->query_skill("taiji-shengong",1)
            || me->query_skill("bihai-shengong",1)
            || me->query_skill("huashan-neigong",1)
            || me->query_skill("jiuyang-shengong",1)
            || me->query_skill("kurong-shengong",1)
            || me->query_skill("myingzhua-gong",1)
            || me->query_skill("xiantian-gong",1)
            || me->query_skill("zixia-shengong",1)
          || me->query_skill("huagong-dafa",1)
          || me->query_skill("linji-zhuang",1) )
                return notify_fail("北冥神功举世无双，你必须先放弃别派的内功\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("北冥神功只能用学(learn)的来增加熟练度。\n");
}
string *parry_msg = ({
       "只见$n将手中$v左一带，右一带，轻轻的将$N的$w各了开去。\n",
       "$n用手中$v在$N的$w上轻轻一搭，\n$N的$w就如着了魔法一般，荡了开去。\n",
});

string *unarmed_parry_msg = ({
       "但是$n用左手轻轻一推$N的$w，\n$N的$w就如着了魔法一般，荡了开去。\n",
       "$n左手轻轻推出，拍向$N的$w，$N的攻击被移的无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}



string exert_function_file(string func)
{
        return __DIR__"beiming-shengong/" + func;
}

string query_yinyang()
{
	return "少阴";
}