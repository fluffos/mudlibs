#include <ansi.h>
#include "/d/yingtianfu/neicheng/general_tasks.h"
string *tasks=({"采编户籍","厘清田产","加编税赋","巡视地方"});//任务数和消耗精力数必须对应，否则可能出错
int *tasks_energy=({60,20,50,30});
int *tasks_diffculty=({20,25,5,35});
int *tasks_range=({0,0,0,0});//tasks_range 1对玩家和npc开放，0仅对npc开放
int *tasks_xiang=({1000,1200,0,500});
int *tasks_liang=({50,50,0,500});
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


string *extra_tax=({"人头","牲口","遗产","边饷","练饷","城门","经营"});
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
            n=zhengwu*(1+random(qinmian));
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"大明在册的人民又多"+chinese_number(n)+"个，明年的税收又将增加。\n");
            }
            ob->restore();
            ob->add("daming_overall/people_total",n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"被没有发现新的不明户籍者。\n");
            }
        }
    }
    if (taskno==2)
    {
        if (result==2)//成功
        {
            n=(zhengwu+qinmian)/2;
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"又查出大明缴税田地"+chinese_number(n)+"亩，明年的粮税又将增加。\n");
            }
            ob->restore();
            ob->add("daming_overall/rice_field_total",n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"被没有发现新的田产。\n");
            }
        }
    }
    if (taskno==3)
    {
        i=random(sizeof(extra_tax));
        n=zhengwu*100/zhihui/renji;
        if (result==2)//成功
        {
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"户部提出大明明年加编"+extra_tax[i]+"税，获得通过。\n");
            }
            ob->restore();
            ob->add("daming_overall/tax_extra",1);
            if (ob->query("daming_overall/tax_extra")>30)
            {
                ob->set("daming_overall/tax_extra",30);
            }
            ob->add("daming_overall/people_happiness",-n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"新加编的"+extra_tax[i]+"税未获通过。\n");
            }
        }
    }
    if (taskno==4)
    {
        ob->restore();
        n=(zhengwu+zhihui+renji)/(1+ob->query("daming_overall/society/safety"));
        if (result==2)//成功
        {
            if (n<1)
            {
                n=1;
            }
            if (n>3)
            {
                n=3;
            }
            if (me)
            {
                tell_object(me,"户部官员巡视地方，减免部分地区税收，获得人民称赞。\n");
            }
            ob->add("daming_overall/tax_remove",1);
            if (ob->query("daming_overall/tax_remove")>50)
            {
                ob->set("daming_overall/tax_remove",50);
            }
            ob->add("daming_overall/people_happiness",n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"巡视地方未获得任何成果。\n");
            }
        }
    }
    return 1;
}
