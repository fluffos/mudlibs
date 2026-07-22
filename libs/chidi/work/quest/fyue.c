inherit BHNPC;
//经验4亿~10亿
#include "/quest/name.h";
#include "/quest/location.h";
#include <ansi.h>;

mapping userskills;
string username;

int give_quests();
int ask_fangqi();
int accountguaiexp(int turn,object who);
int guaif(int turn,object who);
int guaim(int turn,object who);
int set_guai_qi_jing(int turn,object guai);
int getexp(int turn,int level,object who);
string setguaititle(int number,object guaiob);
string randomlocation(int i1);

void create()
{
  set_temp("username","fyue");
  set_temp("level",200);
  set_name("雾中楼", ({ "wu zhonglou", "wu","lou" }));
  set("title", HIR"杀手楼主"NOR);
  set("long", "他是杀手楼的雾中楼，据说一身修为已经达到了神的境界,你看他
两眼湛然若神， 精光内敛，显然已经天人合一，返朴归真了。\n");
  set("gender", "男性");
  set("age", 800);
  set("attitude", "friendly");
    set("no_suck",1);
  set("per", 100);
  set("str", 3000);
  set("int", 40);
  set("dex",500);
  set("con",500);
    set("max_qi", 300000);
  set("max_jing", 30000);
  set("neili", 88888);
  set("max_neili", 40000);
  set("max_jingli", 40000);
  set("jingli", 80000);
  set("combat_exp", 1050000000);
    set_skill("unarmed", 2000);
    set_skill("dodge", 2000);
  set_skill("sword", 2000);
  set_skill("blade", 2000);
  set_skill("parry", 2000);
  set_skill("force", 2000);
  set_skill("zixia-shengong", 2000);
   set_skill("taiji-quan", 2000);
  set_skill("fanliangyi-dao", 2000);
  set_skill("huashan-jianfa", 2000);
  set_skill("xianglong-zhang", 2000);
  set_skill("dugu-jiujian", 2000);
  set_skill("huashan-shenfa",2000);
  set_skill("literate", 2000);
  map_skill("force", "zixia-shengong");
  map_skill("dodge", "huashan-shenfa");
  map_skill("parry", "dugu-jiujian");
  map_skill("sword", "dugu-jiujian");
  map_skill("blade", "fanliangyi-dao");
     map_skill("unarmed", "taiji-quan");
     
  set("inquiry",([   "kill":(:give_quests():),
                         "fangqi": (: ask_fangqi :),
                          "放弃"  : (: ask_fangqi :),
]));

  set("chat_chance", 10);
	set("chat_msg", ({
		"雾中楼抬头看了你一眼，露出一副高深莫测的样子\n",
		"雾中楼长叹一声，世上再也不会有人记得我了！。\n",
	       (: command("'") :),
             //  (: random_move :),
               (: command("unwield dao"):),
               (: command("unwield jian"):),
               (: command("wield dao"):),
               (: command("wield jian"):),
               (: command("exercise 100"):),
	}) );
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
        (: perform_action, "sword.poqi" :),
        (: perform_action, "sword.pozhang" :),
        (: perform_action, "sword.pojian" :),
        (: exert_function, "recover" :),
        (: exert_function, "refresh" :),
    }) );
  setup();
    new("/d/city/obj/changjian")->move(this_object());
  carry_object("/d/gaochang/obj/feituoarmor")->wear();
}
void init()
{
	object who;

	::init();

	if( interactive(who = this_player()) && !who->is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, who);
	}
}
void greeting(object who)
{
	if( !who || environment(who) != environment() ) return;
	if ((int)who->query("combat_exp")<1000)
	{
	   switch(random(3))
	   {
		case 0:command("hi "+(string)who->query("id"));break;
	  	case 1:command("welcome "+(string)who->query("id"));break;
	   	case 2:command("bow "+(string)who->query("id"));break;
                case 3:command("whisper "+(string)who->query("id")+" 哎~!最近与杀手楼作对的敌人越来越多了,ask wu about kill");break;
	   }
     
	}
	else
           say("雾中楼对"+who->query("name")+"说道:这位"+RANK_D->query_respect(who)+
               ",别来无恙啊。\n");
           if(random(40)>20)
           command("heihei "+(string)who->query("id"));
	return;
}
int max_skill_level(object ob)
{  

   int s,i=0,maxlevel=1;
   string *str;
   userskills=ob->query_skills();
   if (!mapp(userskills)) {maxlevel=3;return maxlevel;}
   str=keys(userskills);
 //  if(!str) return notify_fail("你还是先去学习学习吧\n");
   s=sizeof(str);
   if (s<2) return userskills[str[0]]; 
   while (s>0)
     {
       s-=1;
       i=userskills[str[s]];
       if (i>maxlevel) maxlevel=i;
     }
   return maxlevel;
}

int accountlevel(int turn,object ob)
{
   int level;
   level=max_skill_level(ob);
   level=(int)level*(120+turn*2)/100;
   return level;
}

string randomlocation(int i1)
{
   string *str1,*str2,loca;
   int i2,temp;
   str1=keys(allloca);
   str2=allloca[str1[i1]];
   i2=sizeof(str2);
   temp=random(i2);
   if (temp==0 || temp==i2) temp=1;
   loca=str2[0]+str2[temp];
   return loca;
}
      
int give_quests()
{
   object guaiob,userob;
   object me,who,tempob;
   int chooseguai,rewardpot,rewardexp,maxqi,turn;
   int questbusytime,giveuptime,guailevel;
   int temp,i1;
   string *strtemp,locastr;
   me=this_object();
   who=this_player();
 if (who->query("combat_exp") < 100000000)//经验下限4亿
{
         message_vision ("$N看了看$n,摇了摇头的对$n说道：\n"
       +"$n还是去做其它任务吧！\n",me,who);
        return 1;
        }

   giveuptime=who->query_temp("questtime2");
   questbusytime=who->query_temp("questtime1");
   turn=who->query_temp("turn");
   
   if (who->query_temp("kill"))
     {
       if (time()<giveuptime)
        {      
         message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)
          +"，老夫不是请您去杀掉"+who->query_temp("guainame")+"吗？\n",me,who);
          return 1;
        }

        else turn-=2;
     }
   else
     {
     if (who->query("combat_exp") > 1800000000)//经验上限6亿
        {
         message_vision ("$N看了看$n,面带微笑的对$n说道：\n"
       +"您老人家都是高手了，我可不敢使唤您老人家！\n",me,who);
        return 1;
        }
      }
     
//每十个怪算一轮，用turn 做参数
   if (!turn || turn>9) 
      {
        who->set_temp("turn",0);
        turn=0;
      }
   turn=turn+1;
   guailevel=accountlevel(turn,who);
   guaiob=new("/quest/questguai"); 
   
   guaiob->set_heart_beat(1);
   guaiob->set_temp("killername",(string)who->query("id"));
   

//设置怪的jingli,neili,exp,

//   set_guai_qi_jing(turn,who);
   guaiob->set("max_neili",guaif(turn,who));
   guaiob->set("neili",guaif(turn,who));
       guaiob->set("jiali",(int)(guaif(turn,who)/2000));
    guaiob->set("max_jingli",guaim(turn,who));
     guaiob->set("jingli",guaim(turn,who));
      guaiob->set("combat_exp",accountguaiexp(turn,who));
   guaiob->set("neili_factor",(int)(guailevel/2));
   guaiob->set("jingli_factor",(int)(guailevel/2));
   set_guai_qi_jing(turn,guaiob);

//set guai's "long" and "title" 
   switch (random(3))
    {
     case 1 :
      guaiob->set("long","绿林人物"+guaiob->query("name")
                +",听说是星宿派的高手，颇有些本领。\n");break;
     case 2 :
      guaiob->set("long","黑道人物"+guaiob->query("name")
              +"他全身散发出一丝邪气。\n");break;
     default :
      guaiob->set("long","武当叛徒"+guaiob->query("name")
              +"，他混身上下杀气逼人。\n");
    }
   chooseguai=random(7);
   setguaititle(chooseguai,guaiob);   

//rewardexp and rewardpot 是杀怪后得到的qn and exp
   
   rewardexp=getexp(turn,guailevel,who);
   rewardpot=rewardexp*0.97*1.8;
   guaiob->set_temp("killrewardpot",rewardpot*10);
   guaiob->set_temp("killrewardexp",rewardexp*10);
   guaiob->set_temp("player",who);
   guaiob->setguaiskill(chooseguai,guailevel,guaiob);
   guaiob->check_time();  

//确定怪的位置 
   strtemp=keys(allloca);
   i1=sizeof(strtemp);
   temp=random(i1);
   if (temp==i1) temp=0;
   locastr=randomlocation(temp);  
   tempob=load_object(locastr);

//if we get a wrong path,these can help us 
   if (!tempob) 
     {
      message_vision(HIR"$N发现好象有什么地方不对劲了，可是"
      +"又说不上来。\nwrong room :"+locastr+"\n"NOR,who);
      return 1;
     }
   guaiob->move(tempob);

//设置玩家的暂时参数
   who->set_temp("questtime1",time()+120);
   who->set_temp("questtime2",time()+300);
   who->set_temp("guainame",guaiob->query("name"));
   who->set_temp("turn",turn);
   who->set_temp("kill",1);
   message_vision("$N哈哈大笑了几声，对$n说道："+RANK_D->query_respect(who)+"既是同道中人，我有一任务让你去完成\n",me,who);
   message_vision("$N对$n说道：现在"+HIY+""+guaiob->query("name")+"("
        +guaiob->query("id")+")"+NOR+"在"+HIG+""
        +strtemp[temp]+""+NOR+"与我楼作对，请壮士去杀掉他！\n",me,who); 
   return 1;
}
// accountguaiexp 计算怪的经验值
int accountguaiexp(int turn,object who)
{ 
   int userexp,guaiexp;
   userexp=who->query("combat_exp");
   guaiexp=userexp;
   return guaiexp;
}
// guaif 计算怪的内力
int guaif(int turn,object who)
{
   int userneili,guaineili;
  who=this_player();
   userneili=who->query("max_neili");
   guaineili=userneili/3;
   return guaineili;
}
int guaim(int turn,object who)
{
   int userjingli,guaijingli; 
   userjingli=who->query("max_jingli");
   guaijingli=userjingli/3;
   return guaijingli;
}
int set_guai_qi_jing(int turn,object guai)
{
   int maxqi,maxjing;
   maxqi=(int)guai->query("max_neili")*0.6;
   maxjing=(int)guai->query("max_jingli")*0.6;
   guai->set_temp("maxqi",maxqi);
   guai->set("max_qi",maxqi);
   guai->set("eff_qi",maxqi);
   guai->set("qi",maxqi);
   guai->set("max_jing",maxjing);
   guai->set("eff_jing",maxjing);
   guai->set("jing",maxjing);
   return 1;
}
//杀怪得到的exp,与玩家的skills ,exp,turn 有关
int getexp(int turn,int level,object who)
{
   int exp,userexp;
   userexp=who->query("combat_exp");
   exp=random(2000)+4000;
   return exp;
}

string setguaititle(int number,object guaiob)
{
   if (random(10)>7)
      {
       if (guaiob->query("combat_exp")>200000)
             guaiob->set("title","杀人狂魔");
      else if (guaiob->query("combat_exp")>100000)
             guaiob->set("title","恶贯满盈");
       else if (guaiob->query("combat_exp")>50000)
             guaiob->set("title","江洋大盗");
       else if (guaiob->query("combat_exp")>40000)
             guaiob->set("title","大盗");
      else if (guaiob->query("combat_exp")>30000)
             guaiob->set("title","采花贼");     
      else if (guaiob->query("combat_exp")>20000)
             guaiob->set("title","流氓头");  
        else if (guaiob->query("combat_exp")>5000)
             guaiob->set("title","流氓");
       else  guaiob->set("title","小流氓");
      }
   else 
      {
        switch (number)
        {
         case 1 :guaiob->set("title","魔女");break;
         case 2 :guaiob->set("title","恶道");break;
        case 3 :guaiob->set("title","恶僧");break;
         case 4 :guaiob->set("title","地痞");break;
         case 5 :guaiob->set("title","恶龙");break;
         case 6 :guaiob->set("title","老魔");break;
         default :guaiob->set("title","小贼");break;
}
}
}
 int ask_fangqi()
{        
         int temp,i1;
         object me,guai;
         string *strtemp,locastr;
         locastr=randomlocation(temp); 
         me = this_player();
         guai=load_object(locastr);
         if(!me->query_temp("kill"))
       { command("bite");
           command("say 你现在没有任务！\n");
           return 1;
         }
         me->apply_condition("questbusytime",4+random(4));
         me->delete("questtime1"); 
         me->delete("questtime2");
         me->delete("guainame");
        
         me->set_temp("turn",0);
         me->set_temp("kill",0); 
        command("shrug");
        command("say  只好任它去了。\n");
       
        destruct(guai);
        return 1;
}

