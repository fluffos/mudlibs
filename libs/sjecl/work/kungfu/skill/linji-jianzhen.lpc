// linji-jianzhen

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
        HIW"\n$n手忙脚乱，见到处是“幽冥”诀的剑光，不知道如何是好。\n\n"NOR,
        HIW"\n$n左闪右躲，总是逃不出峨嵋弟子的“天地”诀。\n\n"NOR,
        HIW"\n$n被峨嵋弟子的“日月”诀轮番攻击，急的满头大汗。\n\n"NOR,
        HIW"\n峨嵋弟子用“风云”诀将$n包围在阵法中，加紧攻击。\n\n"NOR,
        HIW"\n阵中弟子同时使出“之心”诀，$n登时破绽百出。\n\n"NOR,
        HIW"\n$n被阵中弟子“阴阳”诀急攻，得受不攻。\n\n"NOR,
});


string query_action()
{
        return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
        return 12;
}

void create()
{ 
        seteuid(getuid()); 
}

string type() 
{ 
        return "array"; 
}

int valid_learn(object me) 
{
        if( me->query_skill("linji-zhuang",1) < 120)
                return notify_fail("你的临济十二庄级别不够，无法学习临济剑阵。\n");
        if( me->query_skill("huifeng-jian",1) < 120)
                return notify_fail("你的回风拂柳剑级别不够，无法领悟临济剑阵。\n");
         if( me->query_int() < 30 )
                return notify_fail("你的悟性不够，无法领悟临济剑阵。\n");
         if( me->query_dex() < 30 )
                return notify_fail("你的身法不够，无法领悟临济剑阵。\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("临济剑阵只能通过学习(learn)来提高。\n");
}

