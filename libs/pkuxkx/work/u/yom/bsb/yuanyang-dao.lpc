inherit SKILL;

mapping *action = ({
([      "action":HIB"$N面带微笑，双肩微低，身形一晃，一招“一见钟情”，$w直指$n心窝。"NOR,
        "force" : 120,
        "dodge" : 10,
        "damage": 150,
        "lvl" : 0,
        "weapon" : "左手手掌",
        "damage_type":  "割伤"
]),
([      "action":HIR"$N口中喝到“地久天长”，手中$w化做一团寒气笼罩了$n全身."NOR,
        "force" : 140,
        "dodge" : 0,
        "damage": 180,
        "lvl" : 40,
	"weapon" : "右手",
        "damage_type":  "割伤"
]),
([      "action":HIR"$N将$w掷向天空，又纵身跃起，抓住$w，一招“海誓山盟”，$n感到周身充满无形压力."NOR,
        "force" : 140,
        "dodge" : 0,
        "damage": 200,
        "lvl" : 40,
	"weapon" : "右手",
        "damage_type":  "割伤"
]),
([      "action":HIR"$N脸上笑容突现，好象想起来跟爱人的“花前月下”，似乎根本没在意$n."NOR,
        "force" : 140,
        "dodge" : 0,
        "damage": 230,
        "lvl" : 40,
	"weapon" : "右手",
        "damage_type":  "割伤"
]),
([      "action":HIR"$N口中默默着“此情可待”，眼中浮现坚定的决心，$n手上不禁一松..."NOR,
        "force" : 140,
        "dodge" : 0,
        "damage": 260,
        "lvl" : 40,
	"weapon" : "右手",
        "damage_type":  "割伤"
]),
([      "action":HIR"$N骄傲地大声说道：“看好了，这就是‘双宿双栖’！！”，$w直似从两侧向$n太阳穴点去."NOR,
        "force" : 140,
        "dodge" : 0,
        "damage": 280,
        "lvl" : 40,
	"weapon" : "右手",
        "damage_type":  "割伤"
]),

([      "action":HIG"$N想起了自己的爱人，心中“惆怅莫名”，手中$w随意挥舞，陡然，眼中一缕精光直射$n。"NOR,
        "force" : 160,
        "dodge" : 5,
        "damage": 300,
        "lvl" : 80,
	"weapon" : "右手手掌",
        "damage_type":  "割伤"
]),
([      "action":HIW"突然间$N身形纵起，口中大喝：“我心依旧”，四下里直起一阵共鸣。"NOR,
        "force" : 400,
        "dodge" : 10,
        "damage": 350,
        "lvl" : 100,
	"weapon" : "右手",
        "damage_type":  "割伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "blade" || usage == "parry"; 
}  

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力不够。\n");
	return 1;
}

             int valid_combine(string combo) { return combo=="yanshuangfei"; }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   ~= (int) me->query_skill("yuanyang-dao",1)
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"yuanyang-dao/" + action
}
string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后脚下一滑，身体向右一侧，避过了攻击。\n",
});

int practice_skill(object me)
{
return notify_fail("鸳鸯刀法只能用学(learn)的来增加熟练度。\n");
}

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


