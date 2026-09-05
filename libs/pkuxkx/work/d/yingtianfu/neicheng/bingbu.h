#include <ansi.h>
#include "/d/yingtianfu/neicheng/general_tasks.h"
string *tasks=({"选任军官","招募士兵","操练新兵","巡查军纪","调运军械","保养军械"});//任务数和消耗精力数必须对应，否则可能出错
int *tasks_energy=({10,40,20,50,10,20});
int *tasks_diffculty=({45,25,15,50,10,30});
int *tasks_range=({0,0,0,0,0,0});//tasks_range 1对玩家和npc开放，0仅对npc开放
int *tasks_xiang=({200,400,100,50,200,100});
int *tasks_liang=({0,400,100,0,0,0});
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

int lianbing_accident(object me,object ob)
{
    int deaths;
    if (random(1000)>960)
    {
        deaths=ob->query("daming_overall/army/backup_fighters")/500;
        if (deaths<1)
        {
            deaths=1;
        }
        if (deaths>50)
        {
            deaths=50;
        }
        ob->add("daming_overall/army/backup_fighters",-deaths);
        ob->save();
        tell_object(me,"这次练兵中出现事故，士兵伤亡"+chinese_number(deaths)+"名。\n");
    }
    return 1;
}

int task_finish(object me,int taskno,int result,object npc)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int n,assist,i;
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
            n=to_int(sqrt(to_float(renji+zhihui+qinmian)));
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"大明可用的低层军官又多了"+chinese_number(n)+"名，出征可以更加好地指挥部队了。\n");
            }
            ob->restore();
            ob->add("daming_overall/army/low_rank_officer",n);
            ob->add("daming_overall/army/backup_fighters",-n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"可惜这次并没有从士卒中发现什么合适的人选。\n");
            }
        }
    }
    if (taskno==2)
    {
        if (result==2)//成功
        {
            n=renji*tongyu*qinmian/250;
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"大明可用的士兵又多了"+chinese_number(n)+"名。\n");
            }
            ob->restore();
            assist=ob->query("daming_overall/army/backup_fighters")*ob->query("daming_overall/army/backup_fighters_train")+(40+random(10))*n;
            ob->add("daming_overall/people_total",-n);
            ob->add("daming_overall/army/backup_fighters",n);
            assist=assist/ob->query("daming_overall/army/backup_fighters");
            ob->set("daming_overall/army/backup_fighters_train",assist);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"可惜这次未能募得任何一名勇士。\n");
            }
        }
    }
    if (taskno==3)
    {
        if (result==2)//成功
        {
            n=tongyu*lianbing/ob->query("daming_overall/army/backup_fighters");
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"大明新兵的训练度增加了"+chinese_number(n)+"点。\n");
            }
            ob->restore();
            ob->add("daming_overall/army/backup_fighters_train",n);
            lianbing_accident(me,ob);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"可惜这次训练似乎未有任何成效。\n");
                lianbing_accident(me,ob);
            }
        }
    }
    if (taskno==4)
    {
        if (result==2)//成功
        {
            n=(renji+zhihui)*qinmian/1000;
            if (n<1)
            {
                n=1;
            }
            if (n>10)
            {
                n=10;
            }
            ob->restore();
            if (me)
            {
                tell_object(me,"这次巡查中，共查处不法军官"+chinese_number(n)+"名，克扣粮饷，已枭首。\n");
            }
            ob->add("daming_overall/army/low_rank_officer",-n);
            n=n*(1+random(10));
            ob->add("daming_overall/army/backup_fighters",-n);
            if (me)
            {
                tell_object(me,"这次巡查中，共查处士兵欺凌百姓事件"+chinese_number(n)+"起，已革除军籍。\n");
            }
            n=zhihui*qinmian/6400;
            if (n>2)
            {
                n=2;
            }
            if (n<1)
            {
                n=1;
            }
            ob->add("daming_overall/army/backup_fighters_junji",n);
            if (me)
            {
                tell_object(me,"这次巡查后，军纪好了很多。\n");
            }
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"这次巡查并未发现什么不当之处。\n");
            }
        }
    }
    if (taskno==5)
    {
        if (result==2)//成功
        {
            n=(zhengwu*qinmian)/(10+random(10));
            ob->restore();
            i=random(sizeof(junxie));
            if (me&&ob->query("daming_overall/gongku/"+junxie_id[i])<10)
            {
                tell_object(me,"工部现在的库存也不足了。\n");
                return 1;
            }
            if (n>ob->query("daming_overall/gongku/"+junxie_id[i])-10)
            {
                n=ob->query("daming_overall/gongku/"+junxie_id[i])-10;
            }
            if (n<1)
            {
                n=1;
            }
            if (me)
            {
                tell_object(me,"从工部运送了一批共计"+chinese_number(n)+"件"+junxie[i]+"到兵部的仓库。\n");
            }
            ob->add("daming_overall/bingku/"+junxie_id[i],n);
            ob->add("daming_overall/gongku/"+junxie_id[i],-n);
            ob->save();
        }
        else//失败
        {
            if (me)
            {
                tell_object(me,"工部的官员并未同意运送一批军械过来。\n");
            }
        }
    }
    if (taskno==6)
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
            ob->add("daming_overall/bingku/"+junxie_id[i]+"_baoyang",n);//消耗啥？
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
