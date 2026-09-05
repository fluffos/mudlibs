// Made by goodtaste
// zhong guan

#include <ansi.h>
#include <net/dns.h>
inherit F_DEALER;
inherit NPC;
int ask_pk();

void create()
{         seteuid(getuid());
        set_name("梁柳鹤", ({"liang liuhe" , "liang" ,"guan"}));
        set("title",RED"笑面菩萨"NOR);
        set("long",
                "杀手帮总管，帮内大小事物都经他手，权威极重\n"
               );
        set("count",30);
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 50);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("qi",1000);
        set("max_qi", 1000);
   	set("jing",1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiaji", 50);
        set("combat_exp", 1000000+random(500000));
        set("chat_chance",5);
        set("chat_msg",({
               "梁柳鹤说道：凡事和气第一，不要伤了别人又伤了自己\n",
            }));
 
        set_skill("force", 200);
	set_skill("chuforce",200);//待写
        set_skill("dodge", 200);
        set_skill("liuyun",200);//待写
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("guihun-jian", 200);//待写
        map_skill("force", "chuforce");
        map_skill("dodge", "liuyun");
        map_skill("parry", "guihun-jian");
        map_skill("sword", "guihun-jian");
        create_family("杀手帮",1,"弟子");
           set("inquiry",([
              "pk" : ( : ask_pk : ),
              "PK" : ( : ask_pk : ),
              "杀手" : ( : ask_pk : ),
                ]));
        setup();

        carry_object(__DIR__"obj/shashou_sword")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}


int ask_pk()
{ object *death;
  int i;
object ob=this_object();
  int my_exp,his_exp,sub_exp;
  object me=this_player();
  if(me->query("age")<15) 
    {
         say("梁柳鹤说道:这位"+ RANK_D->query_respect(me) +"年纪尚小不要过早进这一行\n");
         return 1;
}
  if(me->query("pker")==1){
         say("梁柳鹤把脸一沉：你以为你有多大本事？想同时接几个任务！\n");
         return 1;
}
  if(me->query("combat_exp")>=1000000)
    {
       say("梁柳鹤说道：这位大侠身手非凡，还是直接去找帮主吧！\n");
       me->set_temp("face_zhu",1);
       return 1;
    }
   if(ob->query("count")<=0)
   {say("梁柳鹤微微一笑:我今天累了,下去吧.\n");return 1;} 
  if (me->query_condition("bonze_pk" ) > 0)
     {
         say("梁柳鹤向你挥挥手：没什么事了下去吧\n");
         return 1;
     }
   say("梁柳鹤说道：哦，"+RANK_D->query_respect(me) +"有兴趣杀个人玩玩吗？嘿嘿....\n");
   command("say 让我看看有没有合适你的家伙\n");
   death=users();
   for(i=0;i<sizeof(death);i++)
    {
     his_exp=death[i]->query("combat_exp");
     my_exp=me->query("combat_exp");
     if(my_exp>his_exp) 
        sub_exp=my_exp-his_exp;
     else
        sub_exp=his_exp-my_exp;
        if(sub_exp<=(my_exp/10)&&me->query("id")!=death[i]->query("id")&&(int)death[i]->query("age")>16&&!wizardp(death[i]))
     {
         me->set("deathname",(string)death[i]->query("id"));
         me->set("deathexp",death[i]->query("combat_exp"));
 message("vision","梁柳鹤说道：有了，就是他了,【"+death[i]->query("name")+"】如何？\n",me);
         me->set_temp("get_answer",1);
         say("想好了回答(answer)我\n");
         return 1;
       }
     }
      
       say("很遗憾，没有合适于你的人\n");
       return 1;
}
    
void init()
{
        
        add_action("get_answer","answer");
        add_action("request","request");
        add_action("re_fail","fail");
        add_action("linshang","linshang");
        add_action("pk_score","pkscore");

}
 

int get_answer(string answer)
{
  object me,ob;
  me=this_player();
  ob=this_object();
  if(!answer||(answer!="yes"&&answer!="no"))
  {
        say("梁柳鹤说道：我可没空陪你玩！给我滚！\n");
	remove_call_out("kicking");
	call_out("kicking", 0, me);
        return 1;
   }
  if(!me->query_temp("get_answer"))
  { 
    say("你说的关我什么事\n");
    return 1;
  }
  if(answer=="yes")
{
  say("梁柳鹤哈哈大笑几声，这位"+RANK_D->query_respect(me) +
      "果然有魄力，好！\n");   
  me->set("pker",1);
  CHANNEL_D->do_channel(this_object(), "jh", "杀手帮杀手开始行走江湖!");
  ob->add("count",-1);
  delete_temp("get_answer");
  me->set("pk_level",1);
  return 1;
}
  else
   {
     command("heng");
     say("没有胆量就不要来我这里！\n");
     return 1;  
    }

}
int request()
{
object me;
me=this_player();
if(!(me->query("pker")))
{ say("梁柳鹤说道：这位"+RANK_D->query_respect(me)+"不知从何说起啊?\n");
  return 1;
}
if(!me->query("accomplish1"))
{
 say("任务没有完成，你居然敢回来见我！\n");
 remove_call_out("kicking");
 call_out("kicking",0,me);
 return 1;
}
 say("梁柳鹤哈哈大笑几声：好，我没有看走眼，果然是个人物！\n");
 me->delete("accomplish1");
 me->add("combat_exp",(me->query("deathexp"))/50);
 me->delete("deathexp");
 me->delete("accomplish1");
 me->delete("deathname");
 
 message_vision(HIY "你被奖励了!\n" NOR,me);
 me->apply_condition("bonze_pk", 500);
 me->delete("pker");
 me->delete("pk_level");
 say("梁柳鹤笑着说：好了，没什么事了，你下去吧\n");
   return 1;
}

 

   

int kicking(object me)
{
        if (!me|| environment(me) != environment()) return 0;

	me->move("/d/pker/shanmen");
	message("vision","梁柳鹤一个大脚把" +me->query("name") +
		"从万纶台踢了出来\n", environment(me),me);
        return 1;
}
  



int re_fail()
{  object me,ob,feilong,jujing,menzhu;
   string name,name1,name2,name3;
   me=this_player();
   ob=this_object();
   feilong=load_object("/clone/npc/feilong");
   name1=feilong->query("winner");
   jujing=load_object("/clone/npc/jujing");
   name2=jujing->query("winner");
   menzhu=load_object("/clone/npc/men-zhu");
   name2=menzhu->query("winner");
   name=me->query("id");
   if(me->query("pker")!=1)
   {
        say("梁柳鹤迷惑的望着你：这为大侠不知从何说起?\n");
        return 1;
   }
   if(name==name1||name==name2||name==name3)
   {
   	say("梁柳鹤冷笑一声:你还有帮主之位,就想承认失败?\n");
   	return 1;
   }	

   say("梁柳鹤大怒：想不到你是个这样的懦夫！算老夫看走了眼！给我滚！\n");
   me->delete("pker");
   if (me->query("combat_exp") > 2000)
	   me->add("combat_exp",-(me->query("deathexp"))/50);
   me->delete("deathexp");
   me->delete("deathname");
   ob->add("count",1);
   remove_call_out("kicking");
   call_out("kicking", 1, me);
   return 1;
}
  

int linshang()
{
  object me,ob;
  object dan;
  me=this_player();
  ob=this_object();
  if(!me->query_temp("get_dan"))
    {
        say("梁柳鹤哈哈大笑起来：你小子是不是穷疯了？\n");
        return 1;
    }
  say("梁柳鹤微笑着说：辛苦了，这颗玄气丹你拿回去养养身体吧\n");
  command("smile");
  dan=new(__DIR__"obj/dan");
  dan->move(me);
  me->delete_temp("get_dan");
  return 1;   
}



int pk_score()
{
   object me=this_player();
   if(!me->query("pker"))
   {
      write("梁柳鹤迷惑的看着你：这话不知从何说起?\n");
      return 1;
   }
   message("vision",HIY"梁柳鹤告诉你:\n杀手帮忠诚度:"NOR+me->query("pkscore")+HIY"\n"NOR,me);
   message("vision",HIY"你现在的目标:"NOR+me->query("deathname")+"\n"+HIY"他的经验是:"NOR+(string)me->query("deathexp")+"\n",me);
   message("vision",HIY"你的杀气是:"NOR+(string)me->query("shaqi")+"\n",me);
   if(me->query("reward")!=0)
   message("vision",HIY"你在杀手帮中的头衔是:"NOR+me->query("pktitle")+"\n",me);
   return 1;
}



























  
  


