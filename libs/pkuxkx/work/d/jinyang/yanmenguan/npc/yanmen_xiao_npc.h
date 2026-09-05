int diffculty=2;//难度系数
#include <ansi.h>


void init()
{
    add_action("do_none", "steal");
    add_action("do_none", "attack");
    add_action("do_none", "beg");
    set("random_npc",1);
}

int do_none()
{
    return 1;
}

int gene_enemy(object ob)
{
    object killer1,killer2,boss;
    object env=environment(ob);
    object ctrl=load_object("/d/jinyang/yanmenguan/yanmenguan");
    object xiao=ctrl->query("yanmen/xiao");
    object p1=load_object("/d/jinyang/yanmenguan/guandao2");
    object p2=load_object("/d/jinyang/yanmenguan/milin");
    object p3=load_object("/d/jinyang/yanmenguan/milin2");
    int i,num;
    num=diffculty+1;
    if (env->query("road_no")<5)
    {
        for (i=0;i<num;i++)
        {
            killer1=new(__DIR__"killer1");
            killer1->do_copy(ob);
            killer1->move(env);
        }
        for (i=0;i<num-1;i++)
        {
            killer2=new(__DIR__"killer2");
            killer2->do_copy(ob);
            killer2->move(env);
        }
        if (env->query("road_no")==3)
        {
            if (!p1->query("yanmen/zheyan"))
            {
                for (i=0;i<5;i++)
                {
                    killer2=new(__DIR__"killer2");
                    killer2->do_copy(ob);
                    killer2->move(env);
                }
            }
        }
    }
    else if (env->query("road_no")>=5&&env->query("road_no")<=7)
    {
        num=num+1;
        for (i=0;i<num;i++)
        {
            killer1=new(__DIR__"killer1");
            killer1->do_copy(ob);
            killer1->move(env);
        }
        for (i=0;i<num-1;i++)
        {
            killer2=new(__DIR__"killer2");
            killer2->do_copy(ob);
            killer2->move(env);
        }
        if (env->query("road_no")==5)
        {
            if (!p2->query("yanmen/dig"))
            {
                for (i=0;i<5;i++)
                {
                    killer2=new(__DIR__"killer2");
                    killer2->do_copy(ob);
                    killer2->move(env);
                }
            }
        }
        if (env->query("road_no")==6)
        {
            if (!p3->query("yanmen/dig"))
            {
                for (i=0;i<5;i++)
                {
                    killer2=new(__DIR__"killer2");
                    killer2->do_copy(ob);
                    killer2->move(env);
                }
            }
        }
    }
    else if (env->query("road_no")>7&&env->query("road_no")<17)
    {
        num=num+2;
        if (random(10)>4)
        {
            for (i=0;i<num;i++)
            {
                killer1=new(__DIR__"killer1");
                killer1->do_copy(ob);
                killer1->move(env);
            }
        }
        else
        {
            for (i=0;i<num-1;i++)
            {
                killer2=new(__DIR__"killer2");
                killer2->do_copy(ob);
                killer2->move(env);
            }
        }
    }
    else//决战专用
    {
        num=num+4;
        for (i=0;i<num+random(3);i++)
        {
            killer1=new(__DIR__"killer1");
            killer1->do_copy(ob);
            killer1->move(env);
        }
        for (i=0;i<num+random(4);i++)
        {
            killer2=new(__DIR__"killer2");
            killer2->do_copy(ob);
            killer2->move(env);
        }
        boss=new(__DIR__"boss3");
        boss->do_copy(xiao);
        boss->move(env);
    }
    return 1;
}

int syn_for_xiao()
{
    object ob=this_object();
    object xiao,mrs_xiao,guanjia,jiading,yahuan;
    object ctrl=load_object("/d/jinyang/yanmenguan/yanmenguan");
    object env=environment(ob);
    xiao=ctrl->query("yanmen/xiao");
    mrs_xiao=ctrl->query("yanmen/mrs_xiao");
    guanjia=ctrl->query("yanmen/guanjia");
    jiading=ctrl->query("yanmen/jiading");
    yahuan=ctrl->query("yanmen/yahuan");
    if (env->query("road_no")<=7&&env->query("road_no")>=14&&
        time()-(int)xiao->query("yanmen/last_go")>40&&
        !xiao->is_busy()&&living(xiao)&&living(ob)&&env!=environment(xiao))
    {
        ob->move(environment(xiao));
        message_vision("$N赶紧远远跟上萧远山。\n",ob);
    }
    call_out("syn_for_xiao",40,ob);
    return 1;
}

int swim()
{
    this_object()->set("start_swim",1);
    command("swim");
    return 1;
}

int gotowest()
{
    object ob=this_object();
    if (ob->is_busy())
    {
        call_out("gotowest",1);
        return 1;
    }
    command("halt");
    command("west");
    if (ob->query("yanmen_npc")==1)
    {
        gene_enemy(ob);
    }
}

int line_up()
{
    object ob=this_object();
    object env=environment(ob);
    object xiao,mrs_xiao,guanjia,jiading,yahuan;
    object ctrl=load_object("/d/jinyang/yanmenguan/yanmenguan");
    int flag=0;
    xiao=ctrl->query("yanmen/xiao");
    mrs_xiao=ctrl->query("yanmen/mrs_xiao");
    guanjia=ctrl->query("yanmen/guanjia");
    jiading=ctrl->query("yanmen/jiading");
    yahuan=ctrl->query("yanmen/yahuan");
    if (ob->query("yanmen_npc")==1)
    {
        if (mrs_xiao&&living(mrs_xiao)&&environment(mrs_xiao)!=env)
        {
            flag=1;
        }
        if (guanjia&&living(guanjia)&&environment(guanjia)!=env)
        {
            flag=1;
        }
        if (jiading&&living(jiading)&&environment(jiading)!=env)
        {
            flag=1;
        }
        if (yahuan&&living(yahuan)&&environment(yahuan)!=env)
        {
            flag=1;
        }
        if (flag==1)
        {
            command("say 还有人没有到齐，我们再等等。");
        }
        if (flag==0)
        {
            if (xiao&&living(xiao))
            {
                xiao->gotowest();
            }
            if (mrs_xiao&&living(mrs_xiao))
            {
                mrs_xiao->gotowest();
            }
            if (guanjia&&living(guanjia))
            {
                guanjia->gotowest();
            }
            if (jiading&&living(jiading))
            {
                jiading->gotowest();
            }
            if (yahuan&&living(yahuan))
            {
                yahuan->gotowest();
            }
        }
    }
}

int clear_enemy()
{
    object ob=this_object();
    object env=environment(ob);
    object *all=all_inventory(env);
    int i,j=0;
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("yanmen_enemy"))
        {
            j=1;
        }
    }
    if (j==1)
    {
        return 0;
    }
    if (j==0)
    {
        return 1;
    }
}

int check_for_moving()
{
    object ob=this_object();
    object env=environment(ob);
    object xiao,mrs_xiao,guanjia,jiading,yahuan;
    object ctrl=load_object("/d/jinyang/yanmenguan/yanmenguan");
    object center=load_object("/d/jinyang/yanmenguan/center");
    xiao=ctrl->query("yanmen/xiao");
    mrs_xiao=ctrl->query("yanmen/mrs_xiao");
    guanjia=ctrl->query("yanmen/guanjia");
    jiading=ctrl->query("yanmen/jiading");
    yahuan=ctrl->query("yanmen/yahuan");
    if (!xiao)
    {
        return 1;
    }
    if (time()-(int)ob->query("yanmen/last_go")>40&&!xiao->is_busy()&&!ob->is_busy()&&living(xiao)&&living(ob)&&clear_enemy())
    {
        xiao->set("yanmen/task_init",1);
        if (ob->query("yanmen_npc")==5)//丫鬟永远比夫人慢
        {
            if (living(mrs_xiao)&&(int)environment(mrs_xiao)->query("road_no")<(int)environment(ob)->query("road_no"))
            {
                call_out("check_for_moving",1,ob);
                return 1;
            }
        }
        if (ob->query("yanmen_npc")==2||ob->query("yanmen_npc")==3)//家丁永远比萧远山慢
        {
            if (living(xiao)&&(int)environment(xiao)->query("road_no")<(int)environment(ob)->query("road_no"))
            {
                call_out("check_for_moving",1,ob);
                return 1;
            }
        }
        if (env&&env->query("road_no")==14)//山路尽头，如果萧夫人没死，必须一起走。
        {
            if (living(mrs_xiao)&&environment(xiao)!=environment(mrs_xiao))
            {
                call_out("check_for_moving",1,ob);
                return 1;
            }
        }
        center->set("yanmen/already_start",1);
        ob->continue_move();
    }
    call_out("check_for_moving",1,ob);
    return 1;
}

int check_status()
{
    object ob = this_object();
    object medicine;
    if ((ob->query("qi") <=(ob->query("max_qi")/100)*50 || ob->query("eff_qi") <=(ob->query("max_qi")/100)*50 
        || ob->query("jing") <= (ob->query("max_jing")/100)*50 || ob->query("eff_jing") <= (ob->query("max_jing")/100)*50)&&ob->query("medicine")>0)
    {
        ob->add("drug",-1);
        medicine=new("/d/ludingshan/obj/special/dan4");
        medicine->move(ob);
        command("eat dan");
        return 1;
    }
    
    call_out("check_status",3);
    return 1;
}

void do_copy(object me)
{
        object ob,armor;
        mapping skills;
        int i,exp,tempskill;
        ob = this_object();
        tempskill = 0;
        if (ob->query("yanmen_npc")==1)
        {
            exp = me->query("combat_exp");
            tempskill = to_int(pow(exp/100,0.333)*10);
            if (tempskill<500)
            tempskill=500;
        }
        if (ob->query("yanmen_npc")==2)
        {
            exp = me->query("combat_exp")/3;
            tempskill = to_int(pow(exp/100,0.333)*10)*2/3;
        }
        if (ob->query("yanmen_npc")==3)
        {
            exp = me->query("combat_exp")/2;
            tempskill = to_int(pow(exp/100,0.333)*10)*3/4;
        }
        if (ob->query("yanmen_npc")==4)
        {
            exp = me->query("combat_exp");
            tempskill = to_int(pow(exp/100,0.333)*10)*9/10;
            if (tempskill<500)
            tempskill=500;
        }
        if (ob->query("yanmen_npc")==5)
        {
            exp = me->query("combat_exp")/5;
            tempskill = to_int(pow(exp/100,0.333)*10)/3;
            if (tempskill<500)
            tempskill=500;
        }
        skills = ob->query_skills();
        for (i=0;i<sizeof(skills);i++)
        {
            skills[keys(skills)[i]] = tempskill;
        }
        ob->set("combat_exp",exp);
        
        for (i=1;i<10;i++)
        {
            armor=new("/obj/gem/armor");
            armor->gen_armor(i);
            armor->set("no_get",1);
            armor->move(ob);
        }
        command("remove armor 2");
        command("wear all");
        
}

void unconcious() 
{   
        object ob=this_object();
        if(ob->query("qi") > (ob->query("max_qi")/100)*50 && ob->query("eff_qi") > (ob->query("max_qi")/100)*50 && ob->query("jing") > (ob->query("max_jing")/100)*50 && ob->query("eff_jing") > (ob->query("max_jing")/100)*50)
		{
            message_vision("$N冷哼一声，好不在意的避过敌人杀招。\n",ob);
			return;
		} 
}

void die()
{
    object center=load_object("/d/jinyang/yanmenguan/center");
    object ob=this_object();
    if (ob->query("yanmen_npc")==1)
    {
        center->end();
        message("channel:baowei",WHT"【江湖传闻】萧远山在雁门关战役中身死，玩家任务失败。\n"NOR,users());
    }
    if (ob->query("yanmen_npc")==2)
    {
        center->add("bonus",-5);
    }
    if (ob->query("yanmen_npc")==3)
    {
        center->add("bonus",-3);
    }
    if (ob->query("yanmen_npc")==4)
    {
        center->add("bonus",-8);
    }
    if (ob->query("yanmen_npc")==5)
    {
        center->add("bonus",-4);
    }
    ::die();
}