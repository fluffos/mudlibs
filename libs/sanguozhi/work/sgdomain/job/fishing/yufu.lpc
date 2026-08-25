// yufu.c (渔夫)
#include <ansi.h>
#include <mudlib.h>
#define JOBID "fishing"
inherit LIVING;
string employee;
int starttime;
void ask_job(object usr);
void ask_pay(object usr);
void setup()
{
        set_name("yu fu", "渔夫");
        add_id("yufu");
        set_in_room_desc("辛勤捕鱼的渔夫(yu fu)");
        set_long("一位年纪很大的渔夫，饱经风吹雨打。\n"+
        "也许你能帮他一些忙(ask yu fu about job)。\n");
        set_gender(1);
        set_age(56);
        set_sg_rongmao(-5);
        employee="";
        starttime=0;   
        add_question("job","job");
        add_question("pay","pay");
        add_question("name", "name");
        add_question("rumors", "rumors");
        add_ask_str("job","$N对$T道：这位$R，有什么我可以帮你的吗？\n");
}
        
mixed special_answer(object ob, string str)
{
        object player;
        player = this_body();
        switch(str)
        {
        case "job":
                ask_job(player);
                return;
        case "pay":
                ask_pay(player);
                return;
        case "name":
                this_object()->targetted_action("$N微微点了点头道："+
                        "小民从小在此捕鱼，贱名不足挂齿。\n", ob);
                return;
        case "rumors":
                this_object()->targetted_action("$N笑道："+
                        "小民从小在此捕鱼，不知道外面的事。\n", ob);
                return;
        default:   
                return;
        }
}
                
void ask_job(object usr)
{
        string n_id;
        int n_lasttimes,m_lasttimes;
        int p_s;
        object ob;
        n_id=usr->query_id()[0];
        if(employee==n_id)
        {
        this_object()->targetted_action("$N对$T道：快去干你的活吧。\n",usr);
        return;
        }
        if(employee!="")
        {
        object e;
        e=find_body(employee);
        if(objectp(e))
        {
                if((time()-starttime)< 300)
                {
                this_object()->targetted_action(
                "$N对$T道：活儿已经有人在干了，待会再来吧。\n",usr);
                return;
                }
        }
        }
        if(CHAR_D->get_char(n_id,"nation"))
        {
        this_object()->targetted_action(
        "$N一怔：这等下人的活，怎敢劳动$R？若要鲜鱼，"+
        "$s日后亲自奉送几条上府。\n", usr);
        return;
        }
        n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
        m_lasttimes=JOB_D->get_job(JOBID,"count_lasttimes");
        m_lasttimes=15; 
        if(n_lasttimes>m_lasttimes)
        {
        this_object()->targetted_action(
        "$N对$T道：你今天干的活够多的了，该休息休息了。\n",usr);
        return; 
        }
        usr->resign_job(JOBID);
        usr->add_job(JOBID);
        employee=n_id;
        starttime=time();
        this_object()->targetted_action(
        "$N对$T道：好吧，你帮我捕两三条鱼吧。这张渔网给你用吧。\n", usr);
        this_object()->targetted_action("$N交给$T一张渔网。\n",usr);
        ob=new("/sgdomain/job/fishing/net");
        ob->move(usr);
}
         
void award(object usr)  
{
        int isrobot;
        object ob;
        isrobot=usr->query_robot();
        if(isrobot)
        {
        this_object()->simple_action("$N微微一笑：原来如此，好吧。\n");
        this_object()->targetted_action("$N给$T一张百圆纸钱。\n",usr);
        usr->simple_action("$N高兴地直乐：终于有钱了！\n");
        ob=new(PMONEY+"fmoney");
        ob->move(usr);
        }
        else
        {
        string p_id;
        int p_sjlev, p_sjexp;   
        p_id=usr->query_id()[0];
        p_sjlev=usr->query_sk_level("jbsj");
        p_sjexp=usr->query_sk_exp("jbsj");
        if((p_sjlev<50) )
        {
                write("你的基本水计提高了。\n");
                usr->award_exp(100,"jbsj");
        }
        this_object()->simple_action("$N道：不错，不错。\n");
        this_object()->targetted_action("$N给$T十两银子。\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(10);
        ob->move(usr);
        }
}
void ask_pay(object usr)
{
        object ob;
        string n_id;
        int p_s;
        int isrobot;
        n_id=usr->query_id()[0];
        if(employee!=n_id)
        {
                if(usr->query_job(JOBID,"beg_time"))
                { 
                this_object()->targetted_action(
                "$N对$T道：活儿已经给别人了。\n",usr);
                usr->resign_job(JOBID);
                return;
                }
        this_object()->targetted_action(
        "$N对$T道：你还没干活呢。\n",usr);
        return;
        }
        all_inventory(usr);
        ob=present("fish",usr);
        if(!objectp(ob))
        {
        this_object()->targetted_action(
        "$N疑惑地看了$T一眼，道：你开什么玩笑？\n",usr);
        return;
        }
        if(count(ob)<2)
        {
        this_object()->targetted_action(
        "$N对$T摇摇头道：还不够数。\n",usr);
        return;
        }
        else
        {
        this_object()->targetted_action(
        "$N对$T点点头，道：很好，但我还要给你出道题考考你。\n",usr);
        destruct(ob);
        ob=present("fish",usr);
        destruct(ob);
        ob = present("net", usr);
        if (ob) destruct(ob);
        usr->finish_job(JOBID);
        employee="";
        starttime=0;
        ROBOT->robot_test(usr,(:award:));
        }
}        
