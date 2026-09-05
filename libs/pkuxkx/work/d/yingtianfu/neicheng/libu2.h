#include <ansi.h>
#include "/d/yingtianfu/neicheng/general_tasks.h"
string *tasks=({"国子监授课","出使列国"});//任务数和消耗精力数必须对应，否则可能出错
int *tasks_energy=({8,25,});
int *tasks_diffculty=({15,25,});
int *tasks_range=({0,0,});//tasks_range 1对玩家和npc开放，0仅对npc开放
int *tasks_xiang=({50,1200});
int *tasks_liang=({20,1200});
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
            n=(zhihui+renji)/5;
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"大明的学子听了演说，纷纷表示要报销国家。\n");
            }
            ob->restore();
            ob->add("daming_overall/hr/backup_degree",n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"大明的学子似乎并没有被演说所触动。\n");
            }
        }
    }
    if (taskno==1)
    {
        if (result==2)//成功
        {
            n=renji/15;
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"礼部官员出使周边列国后，大明的声望显著提升了。\n");
            }
            ob->restore();
            ob->add("daming_overall/daming_repute",n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"这次出使列国并未获得预期成功。\n");
            }
        }
    }
    return 1;
}
