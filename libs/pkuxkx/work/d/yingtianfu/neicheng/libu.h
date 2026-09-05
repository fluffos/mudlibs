#include <ansi.h>
#include "/d/yingtianfu/neicheng/general_tasks.h"
string *tasks=({"整编官员档案",});//任务数和消耗精力数必须对应，否则可能出错
int *tasks_energy=({5,});
int *tasks_diffculty=({20,});
int *tasks_range=({0,});//tasks_range 1对玩家和npc开放，0仅对npc开放
int *tasks_xiang=({50});
int *tasks_liang=({0});
int get_depart_tasks()
{
    set("tasks",tasks);
    set("tasks_energy",tasks_energy);
    set("tasks_diffculty",tasks_diffculty);
    set("tasks_range",tasks_range);
    set("tasks_xiang",tasks_xiang);
    set("tasks_liang",tasks_liang);
    return 1;
}

int task_finish(object me,int taskno,int result,object npc)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int n;
    int tongyu=npc->query("ming/ability/tongyu");
    int zhengwu=npc->query("ming/ability/zhengwu");
    int lianbing=npc->query("ming/ability/lianbing");
    int renji=npc->query("ming/ability/renji");
    int zhihui=npc->query("ming/ability/zhihui");
    int qinmian=npc->query("ming/ability/qinmian");
    if (taskno==1)
    {
        if (result==2)//成功
        {
            n=qinmian/10;
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"大明的人事记录更加细致，官员优劣，一目了然。\n");
            }
            ob->restore();
            ob->add("daming_overall/hr/clear_degree",n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"大明的人事记录做了一些更改，似乎还是有些差强人意。\n");
            }
        }
    }
    return 1;
}
