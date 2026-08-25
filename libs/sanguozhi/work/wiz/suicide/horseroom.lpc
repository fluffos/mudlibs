#include <mudlib.h>
#define SPEED  8
inherit INDOOR_ROOM;


int is_running = 0;
int status =0;
int round = 0;
int winner;
int priority = -1;  
int level = 0;  
string p_id;
mapping bet=([]);
mixed * data = ({0,0,0,0,0,0});

void init_race()
{
status =0;
round = 0;
winner = -1;
priority = -1;  
level = 0;  
p_id = "";
bet=([]);
data = ({0,0,0,0,0,0});
}

string stat_me()
{
return sprintf("赛局状态(status)  :%d      比赛步伐(round) :%d\n"+
               "施术赛马(priority):%d      施术级别(level) :%d      施术人(p_id):%s\n"+
               "赛马位置(data)    :%O\n"+
               "押注情况(bet)     :%O\n",
               status,round,priority,level,p_id,data,bet);
}

string cmd_example()
{
return "例子：\n"
       "bet bid s 1 10      赌单马１号胜出，赌金１０两，赔率１赔４\n"
       "bet bid d 1+4 10    赌双马１号和４号胜出，赌金１０两，赔率１赔１６，次序错１赔８\n"
       "bet do  p 3         利用千术之预见术预见３号马独赢\n"
       "bet do  s 3         利用千术之干扰术影响３号马的发挥\n";
}


void deal_bet()
{
 mapping gainer;
 string *ids;
 object boss;
 int i;
 if (!boss=present("turf boss",this_object()))
     return ;
 gainer = bet[winner];
  if (!gainer) return;
 ids = keys(gainer);
 for (i=0;i<sizeof(ids);i++)
     {object me;
      me = find_body(ids[i]);
      if (me->query_con_money("gold")<1000)
         me->set_con_money("gold",me->query_con_money("gold")+gainer[ids[i]]*4);
      else
         me->add_money("bank",gainer[ids[i]]*4*10000);
      tell_environment(me,sprintf("%%^YELLOW%%^%s买中%d号马独赢，喜获彩金%d两%%^RESET%%^\n",
                          me->query_primary_name(),winner,gainer[ids[i]]*4));
     }
}



mapping get_bet_data()
{
return bet;
}

int have_enough_gold(object who,int tamt)
{
 int bring;
 bring=who->query_con_money("gold");
 if (bring>=tamt) return bring;
 else return 0;
}


mixed do_bet(string para)
{mixed * paras;
 int h_id1,h_id2,tamt,p_level,p_mp,pre_id;
 string tmp1,tmp2,tmp3;
 object me = this_body();
 string m_id = me->query_primary_id();
 if (!para) return cmd_example();
 sscanf(para,"%s %s %s",tmp1,tmp2,tmp3); 
 if (!tmp1) 
    if (para=="check") tmp1="check";
 if (!tmp1) return cmd_example();
 
 switch (tmp1){
 case "bid" :
      if ((tmp2!="s")&&(tmp2!="d")) return cmd_example();
      if (tmp2=="s")
         if (sscanf(tmp3,"%d %d",h_id1,tamt)<2) 
            return cmd_example();
         else
            {
        if (round!=1) return "现在不是押注的时候!\n";
            if ((h_id1<0)||(h_id1>=sizeof(data)))
               return  "有这个号码的马吗？\n";
            if ((tamt<1)||(tamt>100))
               return "一次押注的金额范围应在1-100gold之间！\n";
            if (!have_enough_gold(me,tamt))
               return "你身上好像没有这么多钱！还是多取点钱来吧！\n";
            else
               me->set_con_money("gold",me->query_con_money("gold")-tamt);
            if (!bet[h_id1]) bet[h_id1]=([]);
            bet[h_id1][m_id]+=tamt;
            return sprintf("你押注%d号马独赢，赌金%d两黄金！\n",h_id1,tamt);
            }
      return;
 case "do":
      if ((tmp2!="s")&&(tmp2!="p")) return cmd_example();
      if (tmp2=="p") 
          {
           if (sscanf(tmp3,"%d",pre_id)<1) 
               return cmd_example();
           if (round<25) return "现在比赛刚刚开始，你无法施术，等一会吧！\n";	
           p_level=this_body()->query_sk_level("qmdj");
           if (p_level<10)
               return "你的千王预见术等级太低了，还是再学学吧，免得献丑！\n";
           p_mp=this_body()->query_cur_mp();
           if (p_mp<40)
               return "你现在精神不够，还是休息休息再说吧。\n";
           if ((pre_id<0)||(pre_id>=sizeof(data)))
               return  "有这个号码的马吗？\n";
           if (priority==-1)
              {priority = pre_id;
               level = p_level;
               p_id = this_body()->query_primary_id();
              }
           else
              {
              if (p_level<=level)
                 return "你总觉得有点不对劲，无法施术\n";
              priority = pre_id;
              level = p_level;
              p_id = this_body()->query_primary_id();
              }
           this_body()->set_cur_mp(this_body()->query_cur_mp()-40);
           write("你的千王预见术施术成功!\n");
                 
        }
      return ;     
   case "check":      
      return stat_me();
      
 default :
   return cmd_example(); 
               }     

}


string get_run_info(mixed *data)
{string result;
 int i,j;
result="\n起点　　　　　　　　　　　　　　　　　    　　　　　　　　　　　                     终点\n";
for(i=0;i<sizeof(data);i++)
{
  string tmp;
  tmp = "|";
  for (j=0;j<data[i];j++)
    tmp+="-";
  tmp+= sprintf("%d号马",i);
  for (j=0;j<(80-data[i]-5);j++)
    tmp+="-";
  tmp+="|\n";
  result+=tmp;
}
return result+"\n";
}


mixed is_run()
{
return is_running;
}


void obj_leave(object ob)
{object *inv;
 inv = all_inventory(this_object());
 if (sizeof(inv)==0) 
   {remove_call_out("game_run");
    is_running = 0;
    }
 inv = filter_array(inv,(:file_name($1)[0..14]=="/std/race/human":));
 if (sizeof(inv)==0) 
   {remove_call_out("game_run");
    is_running = 0;}
}

void obj_arrive(object ob)
{object boss;
if (!is_running)
  if (ob->query_body())
   {call_out("game_run",1);
    bet=([]);
    status =0;
    round = 0;
    data = ({0,0,0,0,0,0});
    is_running = 1;}

if (boss=present("turf boss",this_object()))
    DELAY_D->delay_simple_action(boss,"$N大声嚷嚷道：小赌怡情，大赌兴家，大家快来博一把吧!\n",1);
   
}

void game_run()
{
object boss;
int rad;
remove_call_out("game_run");
if (!is_running) return;
if (!boss=present("turf boss",this_object()))
   {is_running = 0;
    return;}
switch(round){
  case 0 : //this time get bet.
    init_race();
    boss->simple_action("%^CYAN%^$N大声说道：快来买阿，快来买阿，马上马儿就要开跑了！\n%^RESET%^");
    round++;
    call_out("game_run",20);
    return;
  default : //this time race open
    if (!sizeof(keys(bet)))
       {
       round =0;
       call_out("game_run",20);
       return;
       }
    if (round==1)
       {status =1;
        boss->simple_action("%^CYAN%^$N大声说道：这一场比赛开始，现在不在接受下注！\n%^RESET%^");
       }
    round++;
    rad = random(sizeof(data));
    
    if ((priority!=-1)&&(random(2)==0))  //这儿是千王预见术的作弊code
       if (random(100)<level)
          rad = priority;
          
    
    data[rad] += SPEED;
    if (data[rad]>72) 
       {
        winner=rad;
        boss->simple_action(sprintf("%%^CYAN%%^$N大声说道：比赛结束，%d号马胜出！\n%%^RESET%%^",winner));
        status = 2;
        round = 0;
        deal_bet();
        call_out("game_run",10);
        return;}
    if (round%20==0)
        tell_environment(boss,get_run_info(data));
    call_out("game_run",2);
    return;
            } 
}


string get_extra_long()
{
if (!present("turf boss",this_object()))
   return "这是一个正在兴建中的赛马场!\n\n";
else
  {switch(status){
   case 0:
      return "这是一个热闹的赛马场，现在比赛还没正式开始，老板正在笑脸盈盈地接受赌客的下注。\n"+
              get_run_info(data);
   case 1:
      return "这是一个热闹的赛马场，现在比赛正在激烈的进行着，赌客们正在聚精会神地观看着比赛地情况。\n"+
              get_run_info(data);
   case 2:
      return "这是一个热闹的赛马场，现在比赛刚刚结束，老板正在笑脸盈盈和赌客结算赌金。\n"+
             get_run_info(data);
   default:
      return  "\n";
       
        }
  }
          
}

void setup(){
    set_objects( ([
	"/sgdomain/npc/turfboss" : 1
      ]) );
    set_area("wiz_area");
    set_brief("赛马场");
    set_long("                                  ");
    set_exits( ([
                "north" : START,
                "west" : "/wiz/suicide/pigroom",
                ]) );
    set_can_meet(1);
}

int is_casino()
{return 1;}
