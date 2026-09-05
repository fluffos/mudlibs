#include <ansi.h>
#include "/d/yingtianfu/neicheng/general_tasks.h"
string *tasks=({"运购木材","采购石料","督造军械","养护军械"});//任务数和消耗精力数必须对应，否则可能出错
int *tasks_energy=({15,18,25,20});
int *tasks_diffculty=({30,28,35,30});
int *tasks_range=({0,0,0,0});//tasks_range 1对玩家和npc开放，0仅对npc开放
int *tasks_xiang=({300,400,1000,100});
int *tasks_liang=({100,100,50,0});
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

string *junxie_id=({"arrow","blade","spear"});
string *junxie=({"铁胎弓","钢刀","长枪"});
int task_finish(object me,int taskno,int result,object npc)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int n,i;
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
            n=(renji+qinmian)*7/6;
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"工部的库房又多了一些木料的储存。\n");
            }
            ob->restore();
            ob->add("daming_overall/gongku/mu",n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"路上的耗损，一棵木料也没有被运进库房。\n");
            }
        }
    }
    if (taskno==2)
    {
        if (result==2)//成功
        {
            n=(renji+qinmian)*11/10;
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"工部的库房又多了一些石料的储存。\n");
            }
            ob->restore();
            ob->add("daming_overall/gongku/shi",n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"路上的耗损，一块石料也没有被运进库房。\n");
            }
        }
    }
    if (taskno==3)
    {
        if (result==2)//成功
        {
            n=(zhengwu*qinmian)/(15+random(10));
            if (n<1)
            {
                n=1;
            }
            i=random(sizeof(junxie));
            if (me)
            {
                tell_object(me,"工部又督造出一批共计"+chinese_number(n)+"件"+junxie[i]+"。\n");
            }
            ob->restore();
            ob->add("daming_overall/gongku/"+junxie_id[i],n);//消耗啥？
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"新研发的军械彻底失败了。\n");
            }
        }
    }
    if (taskno==4)
    {
        if (result==2)//成功
        {
            n=qinmian/(15+random(10));
            if (n<1)
            {
                n=1;
            }
            i=random(sizeof(junxie));
            if (me)
            {
                tell_object(me,"这次的保养了一批"+junxie[i]+"，将延长它们的寿命。\n");
            }
            ob->restore();
            ob->add("daming_overall/gongku/"+junxie_id[i]+"_baoyang",n);//消耗啥？
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"这次的养护成效不大。\n");
            }
        }
    }
    return 1;
}
