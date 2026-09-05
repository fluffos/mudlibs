
// jobscore.c
//created by boost 9/19/2008

#include <ansi.h>


inherit F_CLEAN_UP;

string bar_string = "■■■■■■■■■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□□□□□□□□□";
                                        //容易度（难=5）        完成时间（长=5）        手动程度 （高=5）  多人受益 (多=1)            total
#define XIAOFENG_WEIGHT 1.6             //4                                 3                       4                   5               16      
#define HUSONG_WEIGHT   1.3             //3                                 4                       5                   1               13
#define HUBIAO_WEIGHT   1.1             //1                                 4                       1                   5               11
#define TASK_WEIGHT     1.0             //2                                 1                       2                   5               10
#define HUYIDAO_WEIGHT  2.0             //5                                 5                       5                   5               20

int show_score(object user);
int show_all_score();

void create() { seteuid(ROOT_UID); }


int main(object me, string arg)
{
    object ob;

    if(!arg)
        ob = me;
    else if (wizardp(me)) 
    {
        if (arg == "all")
            return show_all_score();

        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob || !me->visible(ob)) return notify_fail("你要察看谁的状态？\n");
    }
    else
        return notify_fail("只有巫师能察看别人的状态。\n");

    return show_score(ob);

}

int show_all_score()
{
    //待写。。。
    return 1;
}

int cal_score(object user)      
{
    int xiaofeng    = user->query("jobs/completed/xiaofeng") * XIAOFENG_WEIGHT;
    int husong      = user->query("jobs/completed/husong") * HUSONG_WEIGHT;
    int hubiao      = user->query("jobs/completed/hubiao") * HUBIAO_WEIGHT;
    int task        = user->query("jobs/completed/task") * TASK_WEIGHT;
    int huyidao     = user->query("jobs/completed/huyidao") * HUYIDAO_WEIGHT;


    int score = xiaofeng + husong + hubiao + task + huyidao;
    //      int score_cost = user->query("jobs/score_cost");                                //已经花掉的score
    int average = score / 5;
    int s = (average - xiaofeng) * (average - xiaofeng) + (average - husong) * (average - husong) + (average - hubiao) * (average - hubiao) +
        (average - task) * (average - task) + (average - huyidao) * (average - huyidao);
    int max_s = 1000;
    s = sqrt(s);

    if (s > max_s)
        s = max_s;
    score = score * (max_s - s * 4 / 5) / max_s;    //偏差越大，对socre的系数越小，最小为 1/5，最大为 1
    return score;
}


string tribar_graph(int val, int eff, int max, string color)
{
    return color + bar_string[0..(val*25/max)*2-1]
    + ((eff > val) ? blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}
int show_score(object user)
{
    string line;
    int xiaofeng    = user->query("jobs/completed/xiaofeng") * XIAOFENG_WEIGHT;
    int husong      = user->query("jobs/completed/husong") * HUSONG_WEIGHT;
    int hubiao      = user->query("jobs/completed/hubiao") * HUBIAO_WEIGHT;
    int task        = user->query("jobs/completed/task") * TASK_WEIGHT;
    int huyidao     = user->query("jobs/completed/huyidao") * HUYIDAO_WEIGHT;

    int max_score = 1;


    int score = cal_score(user);

    if (max_score < xiaofeng) max_score = xiaofeng;
    if (max_score < husong) max_score = husong;
    if (max_score < hubiao) max_score = hubiao;
    if (max_score < task) max_score = task;
    if (max_score < huyidao) max_score = huyidao;




    line = HIG"≡━◎综合评价◎━━━━━━━━━━━━━━━━━━━━━━━━≡\n\n"NOR;

    line += "你的任务综合评价为：" + score + "\n";
    line += "你的各项任务对综合评价的贡献为：\n";

    line += " < TASK >  " + tribar_graph(task, max_score, max_score, YEL) + "\n";
    line += " < 护镖 >  " + tribar_graph(hubiao, max_score, max_score, BLU) + "\n";
    line += " < 萧峰 >  " + tribar_graph(xiaofeng, max_score, max_score, MAG) + "\n";
    line += " < 护送 >  " + tribar_graph(husong, max_score, max_score, CYN) + "\n";
    line += " <胡一刀>  " + tribar_graph(huyidao, max_score, max_score, RED) + "\n";

    line += sprintf(HIG"≡━━━━━━━━━━━━━━━━━━━━━━◎北大侠客行◎━━≡\n"NOR);
    write(line);
    return 1;
}


int help(object me)
{
    write(@HELP
指令格式 : jobscore
jobscore <对象名称>                   (巫师专用)

这个指令可以显示你或指定对象的综合任务评价资料。
HELP
       );
    return 1;
}

