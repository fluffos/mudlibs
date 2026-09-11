//厨娘 by row
#include <ansi.h>
#include <mudlib.h>
#define PCHOPWOODS PJOB+"chopwoods"
#define JOBID "chopwoods"
#define WOODS PJCHOPWOODS+"woods"
//#define S_ROOM FROOMPATH+""
inherit LIVING;
void ask_job(object usr);
void ask_pay(object usr);
void ask_food(object usr);
void setup()
{
        set_name("chu niang","厨娘");
        set_in_room_desc("「"+YEL+"整天烧水作饭"+NOR+"」厨娘(chu niang)");
        set_gender(2);
        set_age(40);
        add_question("job","job");
        add_question("pay","pay");
        add_question("rumors","rumors");
        add_question("here","here");
        add_question("name","name");
        add_ask_str("job","$N对$T道：这位$R，有什么我可以帮你的吗？\n");
        add_ask_str("pay","$N对$T道：$R，人道是。。。\n");
        add_ask_str("food","$N对$T哀求道：这位大妈，$s已走头无路了，求您赏口吃的吧!\n");
        add_question("food","food");
}
string long() {
	return "一位身材略胖的厨娘，面色红里透黑，正满头大汗忙个不停。\n"+
        "也许你能帮她一些忙(ask chu niang about job)。\n";
}
void ask_food(object usr)
{
    int n_withbody;
    int n_sum,n_bank,n_sal;
    string p_id;
    n_withbody=usr->query_all_con_money();
    n_bank=usr->query_amt_money("bank");
    p_id=(usr->query_id())[0];
    n_sal=CHAR_D->get_char(p_id,"gold")*10000;
    n_sum=n_withbody+n_bank+n_sal;
        this_object()->targetted_action(
                "$N仔仔细细上上下下打量了$T一番。\n",usr);
    if(n_sum>5000) // 50 silver
        {
                this_object()->targetted_action(
                        "$N对$T道：$m$R不象是穷人呀，自己买吃的好啦。\n",usr);
                return;
        }
        if(present("shuihu",usr)&&present("wotou",usr))
        {
                this_object()->targetted_action(
                        "$N对$T道：你身上不是带着吃的、喝的吗，还要？！\n",usr);
                return;
        }
        this_object()->targetted_action(
                "$N同情地对$T道：怪可怜的，看我能不能给你找点东西。\n",usr);
        if(!present("wotou",usr))
        {       object o=OBJ_D->clone_obj("wotou");
                o->move(usr);
                this_object()->targetted_action(
                        "$N给$T一个窝头。\n",usr);
        }
        if(!present("shuihu",usr))
        {       object o=new(PFOODANDDRINK+"shuihu");
                o->move(usr);
                this_object()->targetted_action(
                        "$N给$T一个水壶。\n",usr);
        }
        usr->responda("thank chu niang");
        usr->responda("touch chu niang");
        usr->responda("kiss chu niang");
        return;
}
mixed special_answer(object ob, string str)
{
        object player;
        player = this_body();
        switch(str)
        {
        case "food":
                ask_food(player);
                return;
        case "job":
                ask_job(player);
                return;
        case "pay":
                ask_pay(player);
                return;
        case "rumors":
                this_object()->targetted_action("$N叹了一声道："+
"唉，如今天下不太平，村里的年青人都被征去当兵啦。\n",ob);
                return;
        case "name":
                this_object()->targetted_action("$N咧开嘴笑道："+
"我一个乡下粗人，贱名不提也罢。\n",ob);
                return;
        case "here":
                this_object()->targetted_action("$N道：这里就是厨房，"+
"这么多活让我一个人干还真忙不过来。\n",ob);
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
        if (usr->query_job(JOBID,"beg_time"))
        {
        this_object()->targetted_action(
        "$N对$T道：快去干你的活吧。\n",usr);
        return;
        }
        if(CHAR_D->get_char(n_id,"nation"))
        {
        this_object()->targetted_action(
        "$N红着脸道：$m$R定在戏弄$s，$s怎敢劳动$R干这等粗活？\n",usr);
        return;
        }
        n_lasttimes=usr->query_job(JOBID,"count_lasttimes");	//用户的任务状态
        m_lasttimes=JOB_D->query_job(JOBID,"count_lasttimes");
        if(n_lasttimes>m_lasttimes)
        {
        this_object()->targetted_action(
        "$N对$T道：你今天干的砍柴活够多的了，该休息休息了。\n",usr);
        return;
        }
        usr->resign_job(JOBID);
        usr->add_job(JOBID);
        this_object()->targetted_action(
        "$N对$T道：好吧，我这里作饭还缺些柴火，你替我去砍些来。\n"+
        "村西面有片树林子。喏，给你一把砍柴刀，最少也要二十根。\n",usr);
        this_object()->targetted_action(
        "$N交给$T一柄"+YEL+"砍柴刀"+NOR+"。\n",usr);
        ob=new("/sgdomain/job/chopwoods/chopper");
        ob->move(usr);
}
void award(object usr)
{
        int isrobot;
        object ob;
        isrobot=usr->query_robot();
        if(isrobot)
        {
        this_object()->simple_action(
        "$N微微一笑：原来如此，好吧。\n");
        this_object()->targetted_action(
        "$N给$T一张百圆纸钱。\n",usr);
        usr->simple_action("$N高兴地直乐：终于有钱了！\n");
        ob=new(PMONEY+"fmoney");
        ob->move(usr);
        }
        else
        {
        string p_id;
        p_id=usr->query_id()[0];
        CHAR_D->set_char(p_id,"reputation",
        CHAR_D->get_char(p_id,"reputation")+1);
        this_object()->simple_action("$N道：不错，不错。\n");
        this_object()->targetted_action("$N给$T十两银子。\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(10);
        ob->move(usr);
        if(random(2)) {
              ob=new("/sgdomain/obj/other/tiezi");
              ob->move(usr);
             this_object()->targetted_action(
                "$N对$T又道：这次活干得尤其出色，再奖励一张贴子。\n",usr);
        }
        }
}
void ask_pay(object usr)
{
        object ob;
        object chopper;
        string n_id;
        int p_s;
        int isrobot;
        n_id=usr->query_id()[0];
        if(!usr->query_job(JOBID,"beg_time")) {
           this_object()->targetted_action(
           "$N疑惑地看了$T一眼，道：你开什么玩笑？\n",usr);
           return;
        }
        ob=present("firewoods",usr);
        chopper=present("chopper",usr);
        if(!objectp(ob))
        {
           this_object()->targetted_action(
           "$N疑惑地看了$T一眼，道：你开什么玩笑？\n",usr);
           return;
        }
        if(ob->query_count()<20)
        {
            this_object()->targetted_action(
            "$N对$T摇摇头道：还不够数呀，你再去砍些来。\n",usr);
           return;
        }
        else
        {
            this_object()->targetted_action(
            "$N接过$T递过来的柴火。\n",usr);
            destruct(ob);
            if(chopper)
                {
                this_object()->simple_action(
                "$N伸手要回了"+YEL+"砍柴刀"+NOR+"。\n");
                destruct(chopper);
                }
        this_object()->targetted_action(
        "$N对$T点点头，道：很好，但我还要给你出道题考考你。\n",usr);
        usr->finish_job(JOBID);
        ROBOT->robot_test(usr,(:award:));
        }
}
