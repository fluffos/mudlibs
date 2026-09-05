//大明官员

#include <ansi.h>
inherit NPC;

void create()
{
    string name,*tmp,*pinying;
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("title", HIW"大明官员"NOR);
    set("gender", "男性");
    set("age", 30+random(30));
    set("long", "他就是一位大明官员。\n");
    set("attitude","heroism");
    set("generation",0);
    set("random_npc",1);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("mingpin",3+random(4));
    set("combat_exp",2000000);

    
	

    setup();
    
}

int accept(object me)
{
    string name;
    command("bow");
    if (name=me->query("name"))
    {
        command("say "+name+"大人，下官定不辱命！");
    }
    return 1;
}

int improve()
{
    object npc=this_object();
    if (npc->query("pot_improve")>0)
    {
        npc->add("pot_improve",-1);
        npc->add("working_force",random(2));
    }
    return 1;
}
int decrese()
{
    object npc=this_object();
    if (npc->query("pot_improve")>0)
    {
        npc->add("pot_improve",-random(2));
    }
    return 1;
}
int finish(object me)
{
    int i;
    object npc=this_object();
    object pl,ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    string name,depart,pl_id;
    int *tasks_diffculty=npc->query("tasks_diffculty");
    if (random(npc->query("working_force"))+random(10)>random(15)+random(tasks_diffculty[npc->query_temp("ming_adv_tasks/task_to_do")-1]))
    {
        if (name=me->query("name"))
        {
            command("say "+name+"大人，下官幸不辱命！");
        }
        npc->set("success",1);
        npc->improve();
    }
    else
    {
        if (name=me->query("name"))
        {
            command("say "+name+"大人，下官把差事给办砸了！");
        }
        npc->decrease();
        npc->set("fail",1);
    }
    ob->restore();
    depart=npc->query("depart_name");
    for (i=100;i<301;i++) 
        {
            if (ob->query(depart+"/officers/"+i)&&member_array(ob->query(depart+"/officers/"+i+"/id"),npc->parse_command_id_list())!=-1)
            {
                ob->set(depart+"/officers/"+i+"/pot_improve",npc->query("pot_improve"));//复制npc
                ob->set(depart+"/officers/"+i+"/working_force",npc->query("working_force"));
                ob->set(depart+"/officers/"+i+"/avaliable","yes");
            }
        }
    if (pl=npc->query_temp("ming_adv_tasks/task_giver"))
    {
        pl_id=pl->query("id");
        ob->add("affairs_completed/"+depart+"/"+pl_id+"/times",1);
    }
    ob->save();
    return 1;
}

int set_init_ability(string arg,int i)
{
        int age,n,tongyu,lianbing,zhengwu,renji,zhihui,qinmian,hr_degree;
        object me=this_object(),ob=load_object("/d/yingtianfu/neicheng/shengzhi");
        int pot_improve,working_force;
        string name,id;
        if (arg&&i)
        {
            ob->restore();
            name=ob->query(arg+i+"/name");
            id=ob->query(arg+i+"/id");
            pot_improve=ob->query(arg+i+"/pot_improve");//复制npc
            working_force=ob->query(arg+i+"/working_force");
            tongyu=ob->query(arg+i+"/tongyu");
            lianbing=ob->query(arg+i+"/lianbing");
            zhengwu=ob->query(arg+i+"/zhengwu");
            renji=ob->query(arg+i+"/renji");
            zhihui=ob->query(arg+i+"/zhihui");
            qinmian=ob->query(arg+i+"/qinmian");
            age=ob->query(arg+i+"/age");
        }
        else//初始生成
        {
            name=me->query("name");
            id=me->query("id");
            age=random(20)+20;
            ob->restore();
            hr_degree=ob->query("daming_overall/hr/backup_degree");
            if (!hr_degree)
            {
                hr_degree=50;
            }
            pot_improve=random(hr_degree)+random(30)+20;
            working_force=random(hr_degree/5)+random(hr_degree/5)+random(hr_degree/5)+random(hr_degree/5)+random(hr_degree/5)+random(10)+random(10)+random(10)+20;
            if (random(100)>49)
                {
                    n=random(20);
                    tongyu=hr_degree-n;
                    zhengwu=hr_degree+n;
                    n=random(20);
                    lianbing=hr_degree-n;
                    renji=hr_degree+n;
                    n=random(20);
                    if (random(2))
                    {
                        n=0-n;
                    }
                    zhihui=hr_degree-n;
                    qinmian=hr_degree+n;
                }
                else
                {
                    n=random(20);
                    tongyu=hr_degree+n;
                    zhengwu=hr_degree-n;
                    n=random(20);
                    lianbing=hr_degree+n;
                    renji=hr_degree-n;
                    n=random(20);
                    if (random(2))
                    {
                        n=0-n;
                    }
                    zhihui=hr_degree+n;
                    qinmian=hr_degree-n;
                }
        }
        me->set_name(name,({id,"officer","guan yuan","guan"}));
        me->set("ming/ability/tongyu",tongyu);
        me->set("ming/ability/zhengwu",zhengwu);
        me->set("ming/ability/lianbing",lianbing);
        me->set("ming/ability/renji",renji);
        me->set("ming/ability/zhihui",zhihui);
        me->set("ming/ability/qinmian",qinmian);
        me->set("pot_improve",pot_improve);
        me->set("working_force",working_force);
        me->set("age",age);
        return 1;
}

int save_npc(string arg,int i)
{
        int n,tongyu,lianbing,zhengwu,renji,zhihui,qinmian,age;
        object me=this_object(),ob=load_object("/d/yingtianfu/neicheng/shengzhi");
        int pot_improve,working_force;
        string name,id;
        name=me->query("name");
        id=me->query("id");
        age=me->query("age");
        pot_improve=me->query("pot_improve");
        working_force=me->query("working_force");
        tongyu=me->query("ming/ability/tongyu");
        zhengwu=me->query("ming/ability/zhengwu");
        lianbing=me->query("ming/ability/lianbing");
        renji=me->query("ming/ability/renji");
        zhihui=me->query("ming/ability/zhihui");
        qinmian=me->query("ming/ability/qinmian");
        ob->restore();
        ob->set(arg+i+"/name",name);
        ob->set(arg+i+"/id",id);
        ob->set(arg+i+"/pot_improve",pot_improve);
        ob->set(arg+i+"/working_force",working_force);
        ob->set(arg+i+"/tongyu",tongyu);
        ob->set(arg+i+"/zhengwu",zhengwu);
        ob->set(arg+i+"/lianbing",lianbing);
        ob->set(arg+i+"/renji",renji);
        ob->set(arg+i+"/zhihui",zhihui);
        ob->set(arg+i+"/qinmian",qinmian);
        ob->set(arg+i+"/age",age);
        ob->save();
        return 1;
}