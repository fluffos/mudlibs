#include <ansi.h>
#include "/d/yingtianfu/neicheng/npc/promote.h"
#define DEPART this_object()->query("depart")//各部不同
#define DEPART_NAME this_object()->query("depart_name")
#define LINE HIW"━━━━━━━━━━━━━━\n"NOR;
int task_finish(object me,int taskno,int result,object npc);
int officer_avaliable(object me,int no);
int sim_process(object me,int taskno);
int access(object me);
string points_color(int points)
{
    if (points>120)
    {
        return HIG+chinese_number(points)+NOR;
    }
    else if (points>80)
    {
        return HIC+chinese_number(points)+NOR;
    }
    else if (points>40)
    {
        return HIB+chinese_number(points)+NOR;
    }
    else
    {
        return HIR+chinese_number(points)+NOR;
    }
}

int do_query_active()//查询行动力
{
    object me=this_player();
    int second,points=(int)me->query("ming/energy");
    string point;
    if (points>0)
    {
        point=points_color(points);
        tell_object(me,"你现在可用行动力是"+point+"点。\n");
        return 1;
    }
    else
    {
        second=me->query("ming/energy_recover_time")-time();//恢复时设置me->set("ming/energy_recover_time",3600+time())
        if (second>0)
        {
            tell_object(me,"你现在行动力为零，尚需"+chinese_number(second)+"秒后，可以恢复。\n");
            return 1;
        }
        else
        {
            tell_object(me,"你现在行动力为零，现在可以恢复。\n");
            return 1;
        }
    }
}

int report_result(object me,object npc)//报告结果
{
    int i,result,result2;
    if (!me)
    {
        return 1;
    }
    if (!npc)
    {
        me->delete_temp("ming_adv_tasks/task");
        tell_object(me,"差事好像给办砸了。\n");
        return 1;
    }
    npc->move(environment(me));
    npc->finish(me);
    me->delete_temp("ming_adv_tasks/task");//情况任务分配
    result=npc->query_temp("ming_adv_tasks/task_to_do");
    message_vision("$N退了出去。\n",npc);
    if (npc->query("success"))
    {
        result2=2;
    }
    else
    {
        result2=1;
    }
    task_finish(me,result,result2,npc);
    destruct(npc);
    return 1;
}
int do_query_salary()
{
    object me=this_player();
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    string msg;
    if (!access(me))
    {
        tell_object(me,"你不是"+DEPART+"高级官员，不能使用这个命令。\n");
        return 1;
    }
    ob->restore();
    msg="上年度"+DEPART+"发放官饷、抚恤金情况如下：\n";
    msg+="共计银："+HIY+chinese_number(ob->query("daming_overall/allocate/"+DEPART_NAME+"/giveout_xiang"))+"两"+NOR+"，粮："+HIW+chinese_number(ob->query("daming_overall/allocate/"+DEPART_NAME+"/giveout_liang"))+"石"+NOR+"\n";
    tell_object(me,msg);
    return 1;
}
int do_query()//查询任务情况
{
    object me=this_player();
    string msg;
    if (!access(me))
    {
        tell_object(me,"你不是"+DEPART+"高级官员，不能使用这个命令。\n");
        return 1;
    }
    msg=HIW+"此刻你可以处理的公务事项：\n"+NOR;
    msg+=HIR+"list"+NOR+"：查询待办事项。\n";
    msg+=HIR+"active"+NOR+"：查询剩余行动力。\n";
    msg+=HIR+"select"+NOR+"：选定待办事项。\n";
    msg+=HIR+"officers"+NOR+"：查询本部官员细致情况。\n";
    msg+=HIR+"salary"+NOR+"：查询去年本部官饷发放情况。\n";
    tell_object(me,msg);
    return 1;
}

int task_pending(object me,object officer)
{
    if (!me)
    {
        return 1;
    }
    if (!officer)
    {
        tell_object(me,"很遗憾，你的命令并没有被传达过去。\n");
        me->delete_temp("ming_adv_tasks/task_give_pending");
        return 1;
    }
    if (officer->query_temp("ming_adv_tasks/task_pending_time")!="yes")
    {
        tell_object(me,"很遗憾，你的命令并没有被"+officer->query("name")+"接受。\n");
        me->delete_temp("ming_adv_tasks/task_give_pending");
        return 1;
    }
    else
    {
        tell_object(me,officer->query("name")+"已经接受了你的任务。去忙点别的吧。\n");
        me->delete_temp("ming_adv_tasks/task_give_pending");
        me->delete_temp("ming_adv_tasks/task");
        return 1;
    }
}

int access(object me)
{
    if (identification(me,DEPART+"尚书")||identification(me,DEPART+"左侍郎")||identification(me,DEPART+"右侍郎"))
    {
        return 1;
    }
    return 0;
}
void init()
{
    add_action("do_list","list");
    add_action("do_query_active","active");
    add_action("do_select","select");
    add_action("do_query","query");
    add_action("do_query_officer","officers");
    add_action("do_query_salary","salary");
}
int do_list()//可选任务
{
    object me=this_player();
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int i,points=(int)me->query("ming/energy");
    string msg="现在你可以进行的公务有：\n";
    string *tasks=this_object()->query("tasks");//任务数和消耗精力数必须对应，否则可能出错
    int *tasks_energy=this_object()->query("tasks_energy");
    int *tasks_diffculty=this_object()->query("tasks_diffculty");
    int *tasks_range=this_object()->query("tasks_range");
    int *tasks_xiang=this_object()->query("tasks_xiang");
    int *tasks_liang=this_object()->query("tasks_liang");
    if (!access(me))
    {
        tell_object(me,"你不是"+DEPART+"高级官员，不能插手"+DEPART+"的事务。\n");
        return 1;
    }
    ob->restore();
    for (i=0;i<sizeof(tasks_energy);i++)
    {
        if (tasks_energy[i]<=points)
        {
            msg+="["+(i+1)+"]"+HIG+tasks[i]+NOR;
            msg+="\n需消耗行动力："+HIG+chinese_number(tasks_energy[i])+NOR+"点";
        }
        else
        {
            msg+="["+(i+1)+"]"+WHT+tasks[i]+NOR;
            msg+="\n需消耗行动力："+WHT+chinese_number(tasks_energy[i])+NOR+"点";
        }
        msg+="\t需消耗银两："+chinese_number(tasks_xiang[i])+"两";
        msg+="\t需消耗储粮："+chinese_number(tasks_liang[i])+"份";
        if (!tasks_range[i])
        {
            msg+=RED+"\t(此任务仅能发放给NPC部属)"+NOR;
        }
        msg+="\n";
        
    }
    msg+=HIW+DEPART+"现库存：【银】"+chinese_number(ob->query("daming_overall/allocate/"+DEPART_NAME+"/xiang"))+"两"+"\t【粮】"+chinese_number(ob->query("daming_overall/allocate/"+DEPART_NAME+"/liang"))+"份\n";
    msg+=HIC+"请用select <编号>选择要办理的公务。\n"+NOR;
    tell_object(me,msg);
    return 1;
}
int do_select(string arg) //选定任务
{
    int taskno,points;
    object me=this_player();
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    string *tasks=this_object()->query("tasks");//任务数和消耗精力数必须对应，否则可能出错
    int *tasks_energy=this_object()->query("tasks_energy");
    int *tasks_diffculty=this_object()->query("tasks_diffculty");
    int *tasks_range=this_object()->query("tasks_range");
    int *tasks_xiang=this_object()->query("tasks_xiang");
    int *tasks_liang=this_object()->query("tasks_liang");
    points=(int)me->query("ming/energy");
    if (!access(me))
    {
        tell_object(me,"你不是"+DEPART+"高级官员，不能插手"+DEPART+"的事务。\n");
        return 1;
    }
    if(!arg || (sscanf(arg, "%d", taskno)< 1 ))
    {
        tell_object(me,"请输入你要进行的公务的编号。\n");
        return 1;
    }
    if (points<tasks_energy[taskno-1])
    {
        tell_object(me,"你的行动力不足以让你完成此项公务。\n");
        return 1;
    }
    ob->restore();
    if (tasks_xiang[taskno-1]>ob->query("daming_overall/allocate/"+DEPART_NAME+"/xiang"))
    {
        tell_object(me,DEPART+"现在没有足够的银钱来进行这项行动。\n");
        return 1;
    }
    if (tasks_liang[taskno-1]>ob->query("daming_overall/allocate/"+DEPART_NAME+"/liang"))
    {
        tell_object(me,DEPART+"现在没有足够的储粮来进行这项行动。\n");
        return 1;
    }
    if (taskno<=0||taskno>sizeof(tasks_energy))
    {
        tell_object(me,"没有这件公务的编号。\n");
        return 1;
    }
    if (me->query_temp("ming_adv_tasks/task"))
    {
        tell_object(me,"做完手头的事情再忙别的吧。\n");
        return 1;
    }
    message_vision("$N决定先着手解决"+tasks[taskno-1]+"。\n",me);
    sim_process(me,taskno);
    return 1;
}
int cost_me(object me,int no)
{
    string *tasks=this_object()->query("tasks");//任务数和消耗精力数必须对应，否则可能出错
    int *tasks_energy=this_object()->query("tasks_energy");
    int *tasks_diffculty=this_object()->query("tasks_diffculty");
    int *tasks_range=this_object()->query("tasks_range");
    int n=tasks_energy[no-1];
    me->add("ming/energy",-n);
    tell_object(me,"你消耗了"+chinese_number(n)+"点行动力，下达了命令。\n");
    return 1;
}

int query_officer(object me)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int i,j,len;
    string msg=HIY+sprintf("\n\n%s%|20s%s\n","【",DEPART+"官员档案","】")+NOR,dash=HIW+"━"+NOR,underline;
    ob->restore();
    me->delete_temp("ming/start_query_officer");
    for (i=100;i<301;i++) 
    {
        if (ob->query(DEPART_NAME+"/officers/"+i)&&ob->query(DEPART_NAME+"/officers/"+i+"/working_force"))
        {
             msg+=HIW+ob->query(DEPART_NAME+"/officers/"+i+"/name")+NOR+"\n";
             len=strwidth(ob->query(DEPART_NAME+"/officers/"+i+"/name"));
             len=len/2;
             underline=dash;
             for (j=0;j<len-1;j++)
             {
                underline+=dash;
             }
             msg+=underline+"\n";
             msg+="〖政务〗"+ob->query(DEPART_NAME+"/officers/"+i+"/zhengwu");
             msg+="〖人际〗"+ob->query(DEPART_NAME+"/officers/"+i+"/renji");
             msg+="〖统御〗"+ob->query(DEPART_NAME+"/officers/"+i+"/tongyu");
             msg+="〖练兵〗"+ob->query(DEPART_NAME+"/officers/"+i+"/lianbing");
             msg+="〖智慧〗"+ob->query(DEPART_NAME+"/officers/"+i+"/zhihui");
             msg+="〖勤勉〗"+ob->query(DEPART_NAME+"/officers/"+i+"/qinmian");
             msg+="\n";
        }
    }
    msg+="\n\n";
    tell_object(me,msg);
    return 1;
}

int do_query_officer()
{
    object me=this_player();
    int i;
    if (!access(me))
    {
        tell_object(me,"你不是"+DEPART+"高级官员，不能随意调阅"+DEPART+"的记录。\n");
        return 1;
    }
    if (time()-(int)me->query_temp("ming/start_query_officer")<60)
    {
        tell_object(me,"你刚刚已经吩咐属官去调阅所有本部所有官员的档案了。\n");
        return 1;
    }
    message_vision("$N唤过一个书吏，吩咐他带来本部官员的档案。\n",me);
    call_out("query_officer",random(3)+2,me);
    me->set_temp("ming/start_query_officer",time());
    return 1;
}
int select(string arg,object ob,object me,int no)
{
    int i;
    object officer,npc;
    string get_path;
    string *tasks=this_object()->query("tasks");//任务数和消耗精力数必须对应，否则可能出错
    int *tasks_energy=this_object()->query("tasks_energy");
    int *tasks_diffculty=this_object()->query("tasks_diffculty");
    int *tasks_range=this_object()->query("tasks_range");
    int *tasks_xiang=this_object()->query("tasks_xiang");
    int *tasks_liang=this_object()->query("tasks_liang");
    if (me->query_temp("ming_adv_tasks/task_give_pending"))
    {
        tell_object(me,"你总要给别人点时间决定啊！\n");
        return 1;
    }
    if (officer=find_player(arg))
    {
        if (officer->query("mingpin")&&officer->query("mingpin")<me->query("mingpin"))
        {
            tell_object(me,"驱使上官？亏你想得出来！\n");
            return 1;
        }
        else if (officer->query("mingpin")&&officer->query("mingpin")==me->query("mingpin"))
        {
            tell_object(me,"你不能命令一个同级的官员。\n");
            return 1;
        }
        else
        {
            cost_me(me,no);
            tell_object(officer,DEPART+"长官"+me->query("name")+"希望你能尽快回部处理"+tasks[no-1]+"的事务。\n");
            tell_object(officer,"请在三十秒内选择接受(accept)或是拒绝(refuse)。\n");
            tell_object(me,"你已经发公函给"+officer->query("name")+"了，三十秒内将有答案。\n");
            officer->set_temp("ming_adv_tasks/task_pending_time",time());
            officer->set_temp("ming_adv_tasks/task_giver",me);
            officer->set_temp("ming_adv_tasks/task_to_do",no);
            me->set_temp("ming_adv_tasks/task_give_pending",1);
            me->set_temp("ming_adv_tasks/task",1);
            call_out("task_pending",30,me,officer);
            return 1;
        }
    }
    else
    {
        ob->restore();
        npc=new(__DIR__"npc/random_npc");
        for (i=100;i<301;i++) 
        {
            if (ob->query(DEPART_NAME+"/officers/"+i)&&ob->query(DEPART_NAME+"/officers/"+i+"/id")==arg)
            {
                get_path=DEPART_NAME+"/officers/";
                npc->set_init_ability(get_path,i);
                ob->set(get_path+i+"/avaliable","no");
                ob->save();
            }
        }
        ob->restore();
        ob->add("daming_overall/allocate/"+DEPART_NAME+"/liang",-tasks_liang[no-1]);
        ob->add("daming_overall/allocate/"+DEPART_NAME+"/xiang",-tasks_xiang[no-1]);
        ob->save();
        cost_me(me,no);
        npc->set("depart",DEPART);
        npc->set("depart_name",DEPART_NAME);
        npc->set("tasks_diffculty",tasks_diffculty);
        npc->set_temp("ming_adv_tasks/task_giver",me);
        npc->set_temp("ming_adv_tasks/task_to_do",no);
        me->set_temp("ming_adv_tasks/task",1);
        npc->set("title",HIW+"大明"+DEPART+"官员"+NOR);
        npc->set("long","这是一位大明"+DEPART+"的官员。\n");
        npc->move(environment(me));
        npc->accept(me);
        message_vision("$N转身离去。\n",npc);
        npc->move("/d/yingtianfu/neicheng/wen_zhifang");
        call_out("report_result",30+random(15),me,npc);
        tell_object(me,"你选择了"+npc->query("name")+"来处理【"+tasks[no-1]+"】的事务。\n");
        return 1;
    }
}

int select_officer(string arg,object ob,object me,int no)
{
    int i,num,flag=0;
    string *tasks=this_object()->query("tasks");//任务数和消耗精力数必须对应，否则可能出错
    int *tasks_energy=this_object()->query("tasks_energy");
    int *tasks_diffculty=this_object()->query("tasks_diffculty");
    int *tasks_range=this_object()->query("tasks_range");
    if (arg=="mission_cancel")
    {
        tell_object(me,"你放弃了执行"+tasks[no-1]+"的事务。\n");
        me->delete_temp("ming_adv_tasks/task");
        return 1;
    }
    for (i=100;i<301;i++) //每部最多200名官员NPC+PLAYER
    {
        if (ob->query(DEPART_NAME+"/officers/"+i+"/id")==arg)
        {
            flag=1;
            num=i;
        }
    }
    if (flag==0)
    {
        tell_object(me,"没有"+arg+"这名官员！请重新选择或查询官员列表。放弃任务请输入"+HIR+"mission_cancel。\n"+NOR);
        officer_avaliable(me,no);
    }
    else
    {
        if (!tasks_range[no-1]&&!ob->query(DEPART_NAME+"/officers/"+num+"/working_force"))
        {
            tell_object(me,tasks[no-1]+"只能交给非玩家去处理，请重新选择。放弃任务请输入"+HIR+"mission_cancel。\n"+NOR);
            officer_avaliable(me,no);
            return 1;
        }
        select(arg,ob,me,no);
        if (arg==me->query("id"))
        {
            me->set_temp("ming_adv_tasks/task","myself");
            tell_object(me,"你决定亲自处理"+tasks[no-1]+"的事务。\n");
            return 1;
        }
    }
    return 1;
}

int officer_avaliable(object me,int no)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    mapping *officers;
    string officers_list="大人，"+DEPART+"现在可用官员如下：\n";
    int i,count=0;
    string *tasks=this_object()->query("tasks");//任务数和消耗精力数必须对应，否则可能出错
    int *tasks_energy=this_object()->query("tasks_energy");
    int *tasks_diffculty=this_object()->query("tasks_diffculty");
    int *tasks_range=this_object()->query("tasks_range");
    ob->restore();
    officers=ob->query(DEPART_NAME+"/officers");
    if (!sizeof(officers))
    {
        tell_object(me,"大人，现在"+DEPART+"全无可用之人，大人还是快去吏部借调点官员过来吧。\n");
        return 1;
    }
    else
    {
        for (i=100;i<301;i++) //每部最多200名官员NPC+PLAYER
        {
            if (!tasks_range[no-1]&&!ob->query(DEPART_NAME+"/officers/"+i+"/working_force"))
            {
                continue;
            }
            if (ob->query(DEPART_NAME+"/officers/"+i)&&ob->query(DEPART_NAME+"/officers/"+i+"/avaliable")!="no")
            {
                officers_list+=ob->query(DEPART_NAME+"/officers/"+i+"/name");
                officers_list+=ob->query(DEPART_NAME+"/officers/"+i+"/id");
                officers_list+="\n";
                count+=1;
            }
        }
        officers_list+="\n";
        officers_list+="请选择具体办事的人选，共有"+chinese_number(count)+"人可以着手此事。\n";
        officers_list+="如需放弃此任务，请输入"+HIR+"mission_cancel。\n"+NOR;
        if (count==0)
        {
            officers_list=DEPART+"缺乏人手办理此事。\n";
            officers_list+="大人，现在"+DEPART+"全无可用之人，大人还是快去吏部借调点官员过来吧。\n";
            tell_object(me,officers_list);
            return 1;
        }
        tell_object(me,officers_list);
        input_to( (: select_officer :),ob,me,no);
        return 1;
    }
}
int sim_process(object me,int taskno)//模拟执行,每个独立事件大约需要1分钟
{
    officer_avaliable(me,taskno);
    return 1;
}