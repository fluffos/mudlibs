// accountant 帐房先生
//fire
#include <ansi.h>
#define JOBID "digsoil"
#define SOIL PJDIGSOIL+"soil"
#define S_ROOM "/a/huayin/vfield"
inherit LIVING;
object room;
object soil;
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
   set_gender(1);
   set_age(50);
   set_sg_rongmao(-1);
   add_question("job", "job");
   add_question("pay","pay");
   add_ask_str("pay","$N颤颤惊惊地对$T道：东家，这，，这，，钱。。。\n");
  set_clean_up(1);
}
string long() {
   return "帐房先生抬头看了你一眼，\n"+
       "要工作就ask xian sheng about job。\n"+
       "要钱就ask xian sheng about pay。\n";
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
        this_object()->simple_action("$N说到：不错，不错．\n");
        this_object()->targetted_action(
         "$N给$T十两银子。\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(10);
        ob->move(usr);
        if(random(2)==1) {
              ob=new("/sgdomain/obj/other/tiezi");
              ob->move(usr);
             this_object()->targetted_action(
                "$N对$T又道：这次活干得尤其出色，再奖励一张贴子。\n",usr);
        }
    }
}
void ask_pay(object usr)
{
    string n_id;
   int p_s;
    int isrobot;
    n_id=usr->query_id()[0];
    if(!usr->query_job(JOBID,"beg_time")) {
        this_object()->targetted_action(
            "$N对$T道：没干活就想拿钱呀。\n",usr);
        return;
    }
    if((usr->query_job(JOBID,"status"))!="done")
    {
        this_object()->targetted_action(
          "$N对$T说：活儿没做利索，就想拿钱？！\n",usr);
        return;
    }
    this_object()->targetted_action(
      "$N对$T说道：活儿干得不错，但我还要给你一道题,看你聪明不聪明。\n",
      usr);
    usr->finish_job(JOBID);
    ROBOT->robot_test(usr,(:award:));
}
void ask_job(object usr)
{
    string n_id;
    int n_lasttimes,m_lasttimes;
    int p_s;
    n_id=usr->query_id()[0];
    if(CHAR_D->get_char(n_id,"nation"))
    {
       this_object()->targetted_action(
         "$N对$T对满脸堆笑道：$m$R折杀$s也，此乃下人的活，怎敢劳动$R。\n",usr);
       return;
    }
    if (usr->query_job(JOBID,"beg_time"))
    {
        this_object()->targetted_action(
         "$N对$T道：活儿已经安排给你了，还不去做？\n",usr);
        return;
    }
    n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
    m_lasttimes=JOB_D->query_job(JOBID,"count_lasttimes");
    if(n_lasttimes>m_lasttimes)
    {
      this_object()->targetted_action(
          "$N对$T道：你今天锄地浇水的活干得够多的了，该休息休息了。\n",usr);
        return;
    }
    room=load_object(S_ROOM);
    soil=present("soil", room );
    soil->set_status(0);
    usr->resign_job(JOBID);
    usr->add_job(JOBID);
    usr->set_job(JOBID,"status","beg");
    this_object()->targetted_action(
     "$N对$T道：那好，村北头那块地就交给你了，\n"+
     "地锄好，水浇足，就来领钱吧，工具到厨房去找。\n",usr);
}
