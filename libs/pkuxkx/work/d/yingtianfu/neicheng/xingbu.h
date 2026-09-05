#include <ansi.h>
#include "/d/yingtianfu/neicheng/general_tasks.h"
string *tasks=({"完善邢典",});//任务数和消耗精力数必须对应，否则可能出错
int *tasks_energy=({5,});
int *tasks_diffculty=({40,});
int *tasks_range=({0,});//tasks_range 1对玩家和npc开放，0仅对npc开放
int *tasks_xiang=({100});
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
            n=zhihui/3+zhengwu/2;
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"大明的邢典更加合理，人民更加安居乐业，盗贼显著减少了。\n");
            }
            ob->restore();
            ob->add("daming_overall/society/safety",n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"可惜并没有做出任何有益的修缮。\n");
            }
        }
    }
    return 1;
}
