// accountant 帐房先生
//fire
#include <ansi.h>
#define JOBID "digsoil"
#define SOIL PJDIGSOIL+"soil"
#define S_ROOM FROOMPATH+"vfield"
inherit LIVING;
object room;
object soil;
string employee;
int starttime;
void ask_pay(object usr);
void ask_job(object usr);
void setup()
{
   object jia;
   jia=new(PTORSO+"choup");
   jia->move(this_object());
   jia->do_wear();
   set_name("xian sheng", "帐房先生");
   set_in_room_desc("「"+HIR+"不干活就休想拿钱"+NOR+"」帐房先生(xian sheng)");
   set_long("帐房先生抬头看了你一眼，\n"+
       "要工作就ask xian sheng about job。\n"+
       "要钱就ask xian sheng about pay。\n");
   set_gender(1);
   set_age(50);
   set_sg_rongmao(-1);
   employee="";
   starttime=0;
   add_question("job", "job");
   add_question("pay","pay");
   add_ask_str("pay","$N颤颤惊惊地对$T道：东家，这，，这，，钱。。。\n");
  set_clean_up(1);
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
      default:
         return ;
    }
}
void award(object usr)
{
    int isrobot;
    object ob;
    isrobot=usr->query_robot();
    if(isrobot)
    {   this_object()->simple_action(
         "$N暗笑道：真是个白痴,嘿嘿。\n");
        this_object()->targetted_action(
         "$N对$T道：$R真是又能干，又聪明，这是奖你张大票子。\n",usr);
        this_object()->targetted_action(
         "$N给$T一张百圆纸钱。甛n",usr);
        usr->simple_action("$N高兴地连称：好！好！谢大人赏赐。\n");
        ob=new(PMONEY+"fmoney");
        ob->move(usr);
    }
    else
    {
        string p_id;
        p_id=usr->query_id()[0];
        CHAR_D->set_char(p_id,"reputation",
         CHAR_D->get_char(p_id,"reputation")+1);
        tell_user(p_id,"你的声望提高了。\n");
        this_object()->simple_action("$N说到：不错，不错．\n");
        this_object()->targetted_action(
         "$N给$T二十两银子。\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(20);
        ob->move(usr);
    }
}
void ask_pay(object usr)
{
    string n_id;
   int p_s;
    int isrobot;
    n_id=usr->query_id()[0];
    if (employee!=n_id)
    {
        if(usr->query_job(JOBID,"beg_time"))
        {
          this_object()->targetted_action(
            "$N对$T道：活儿已经给别人了。\n",usr);
          usr->resign_job(JOBID);
          return;
        }
        this_object()->targetted_action(
            "$N对$T道：没干活就想拿钱呀。\n",usr);
        return;
    }
    room=load_object(S_ROOM);
    soil=present("soil", room );
    p_s=soil->query_status();
    if(p_s<40)
    {
        this_object()->targetted_action(
          "$N对$T说：活儿没做利索，就想拿钱？！\n",usr);
        return;
    }
    this_object()->targetted_action(
      "$N对$T说道：活儿干得不错，但我还要给你一道题,看你聪明不聪明。\n",usr);
    usr->finish_job(JOBID);
    employee="";
    starttime=0;
    ROBOT->robot_test(usr,(:award:));
}
void ask_job(object usr)
{
    string n_id;
    int n_lasttimes,m_lasttimes;
    int p_s;
    n_id=usr->query_id()[0];
    if (employee==n_id)
    {
        this_object()->targetted_action(
         "$N对$T道：活儿已经安排给你了，还不去做？\n",usr);
        return;
    }
    if(employee!="") // some body working
    {
        object e;
        e=find_body(employee);
        if(objectp(e)) // this guy still on line
        {
           if((time()-starttime)<600) // not long to 10 min
           {
                this_object()->targetted_action(
                 "$N对$T道：活儿现在有人做，待会儿再来吧。\n",usr);
                return;
           }
         }
    }
    if(CHAR_D->get_char(n_id,"nation"))
    {
       this_object()->targetted_action(
         "$N对$T对满脸堆笑道：$m$R折杀$s也，此乃下人的活，怎敢劳动$R。\n",
usr);
       return;
    }
    n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
    m_lasttimes=JOB_D->get_job(JOBID,"count_lasttimes");
    m_lasttimes=10; // because job_d not finished
    if(n_lasttimes>m_lasttimes)
    {
      this_object()->targetted_action(
          "$N对$T道：你今天干的活够多的了，该休息休息了。\n",usr);
        return;
    }
    room=load_object(S_ROOM);
    soil=present("soil", room );
    p_s=soil->query_status();
    if(p_s>20)
    {
        this_object()->targetted_action(
          "$N对$T道：现在没什么活儿可干，待会儿再来吧。\n",usr);
        return;
    }
    usr->resign_job(JOBID);
    usr->add_job(JOBID);
    employee=n_id;
    starttime=time();
    this_object()->targetted_action(
     "$N对$T道：那好，村北头那块地就交给你了，\n"+
     "地锄好，水浇足，就来领钱吧，工具到厨房去找。\n",usr);
}