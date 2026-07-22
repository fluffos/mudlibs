// qimen-baguazhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
        HIR"\n$n看著奇门八卦阵中人影忽东忽西，来回飞跃，看得眼花缭乱，\n" +
                "突然从旁边一块石头後跳出一个弟子，一剑刺来！\n\n"NOR,
        HIG"\n$n连闪数招，却是越来越慌乱，一不小心，被地上一段树枝绊倒，\n" +
              "剑光闪闪，一片光网围了过来，你死命的爬开，已经伤痕累累！\n\n"NOR,
        HIY"\n$n想要跳出阵法，却突然飞来一块大石！你转身闪避，不料已经有 \n" +
              "人挡在你退路上，剑掌齐施向你攻来！\n\n"NOR,
        HIB"\n$n奋力向阵中一名弟子攻去，但见那弟子倏地消失，$n大惊之下连 \n" +
               "忙後退，结果发现那名弟子居然你身後偷袭！\n\n"NOR,
        HIM"\n$n以守为攻，采取守势，但阵中却静了下来。$n突然感到劲风袭来 \n" +
               "连忙转身迎击。\n\n"NOR,
        HIC"\n$n不顾及自身安全，拼命想冲出阵去，结果破绽大开，在阵中连连 \n" +
              "受挫，又退到阵法中心。\n\n"NOR,
        HIW"\n$n突然见到阵出现开口，不知是计，向出口急冲而去，结果中了埋伏 \n" +
               "情况狼狈不堪！\n\n"NOR,
});


string query_action()
{
        return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
        return 8;
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
        if( me->query_skill("bihai-chaosheng",1) < 150)
                return notify_fail("你的碧海潮生功级别不够，无法学习奇门八卦阵。\n");
        if( me->query_skill("yuxiao-jian",1) < 150)
                return notify_fail("你的玉箫剑法级别不够，无法领悟奇门八卦阵。\n");
        if( me->query_skill("qimen-bagua",1) < 150)
                return notify_fail("你的奇门八卦级别不够，无法领悟奇门八卦阵。\n");
        if( me->query_skill("suibo-zhuliu",1) < 150)
                return notify_fail("你的随波逐流级别不够，无法领悟奇门八卦阵。\n");
 if( me->query_int() < 35 )
                return notify_fail("你的悟性不够，无法领悟奇门八卦阵。\n");
if( me->query_dex() < 35 )
                return notify_fail("你的身法不够，无法领悟奇门八卦阵。\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("奇门八卦阵只能通过学习(learn)来提高。\n");
}

