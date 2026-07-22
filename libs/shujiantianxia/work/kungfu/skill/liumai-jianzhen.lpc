// liumai-jianzhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
        HIG"\n$n连续出招挡住了攻势，却感觉无数条剑气袭来，似乎越来越快，越来越多，\n" +
                "有质无形，无影无踪，实在难以抵挡。\n\n"NOR,
        HIG"\n众僧见$n试图想逃出六脉剑阵，各自屈指一弹，随即数道无形剑气追击而上，\n" + 
                "$n挡不过这无形剑气，已然无法脱身。\n\n"NOR,
        HIG"\n却见$n周围气流纵横交错，剑气来回转折迅捷如风，$n没有丝毫的时间思索，只是被动的抵挡。\n\n"NOR,
        HIG"\n众僧各自发招，看似杂乱，却暗藏章法，或直，或曲，或后发先至，或先急而后缓，无不包含极大杀伤力。\n\n"NOR,
        HIG"\n一道无形剑气由左至右发出，紧接着着数道剑气缓缓跟上，虽缓慢无形，却是无坚不催。\n\n"NOR,
        HIG"\n只听见破空之声大响，无数条剑气交错而出，上下左右，封住了$n的所有出路。\n\n"NOR,
        HIG"\n空气气流急剧流动，暗藏着无数潜劲，无声无形，无从琢磨。\n\n"NOR,
        HIG"\n六道剑气从四面八方向$n扑到，如闪电，如暴风，破空之声大振。\n\n"NOR,
        HIG"\n突然之间，数道凌厉无比的剑气如箭射出，上下交错，无从抵挡，\n" +
                "向$n冲去，剑气没到，四周已传来空气的撕裂声。\n\n"NOR, 
});


string query_action()
{
        return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
        return 6;
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
        if( me->query_skill("yiyang-zhi",1) < 160)
                return notify_fail("你的一阳指级别不够，无法学习六脉剑阵。\n");
        if( me->query_skill("liumai-shenjian",1) < 30)
                return notify_fail("你的六脉神剑级别不够，无法领悟六脉剑阵。\n");
    if( me->query_int() < 35 )
                return notify_fail("你的悟性不够，无法领悟六脉剑阵。\n");
        if( me->query_skill("buddhism",1) < 150 )
                return notify_fail("你的禅宗心法级别不够，无法领悟六脉剑阵。\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("六脉剑阵只能通过学习(learn)来提高。\n");
}
