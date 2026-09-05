//Made by goodtaste

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
void create()
{
	set_name("阿萍", ({ "ping"}));
	set("shen_type", 0);

	set("per", 25);
	set("gender", "女性");
	set("age", 25);
	set("long",
		"一个年轻的妓女，还算有几分姿色，但是颦笑之间总是带着些倦意\n"
		);
	set("combat_exp", 500);
	set("attitude", "friendly");
	
	
	

	set("shen_type",1);set("score",200);setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("fuck","sleep");
        
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	message("vision","这位"+RANK_D->query_respect(ob)+"人家等你好久了...\n",ob);
}


int fuck(string arg)
{  object me=this_player();
   object ob=this_object();
   
   if(!arg||arg!="ping")
  {   
      message("vision",RED "阿萍撒娇道：我在这里呢，没看见吗?\n" NOR,me);            
      return 1;
  }
   if(!me->query_temp("can_fuck"))
      {
          write("你还没付钱呢，阿萍我再喜欢你，也要吃饭吧?\n");
          return 1;
      }
   if(me->query_temp("fucking"))
      {
         message("vision",RED"你不是正在干吗？还要什么啊?\n"NOR,me);
         return 1;
      }
   message("vision",RED"只见"+me->name()+"急急忙忙脱了衣服就往阿萍身上扑去!\n"NOR,environment(me));
   message("vision",HIW"你们都把眼睛放老实点!\n"NOR,environment(me),me);
   me->set_temp("fucking",1);
   remove_call_out("truth");
   call_out("truth", 10, me, ob);
   return 1;
}

int truth(object me,object ob)
{   
    int i; 
    me->start_busy(3);
    
    for(i=0;i<random((int)me->query("jingli")/100+1);i++)
      {
          remove_call_out("delay");
          call_out("delay",1, me, ob);
      }
          
          remove_call_out("over");
          call_out("over",15,me);
     return 1;
}


int mimi(object me)
{
   message("vision",BLU"上次金刀护法来过我这里，告诉我欧阳堂主总是把堂主令带在身上，
还说只要有她的令，我就可以去护法那里玩，哼，有什么好玩的，我才不去呢！他要我不要把
这事告诉别人，可是我真的很喜欢你哟！呵，呵...不要告诉别人就是了，啊？\n"NOR,me);
   me->set_temp("aping",1);
   me->delete_temp("fucking");
   me->delete_temp("can_fuck");
   return 1;
}



int delay(object me,object ob)
{ 
    switch(random(3))
            {          
             case 0:
                     message("vision",HIR""+me->name()+"一边用手轻轻抚摸阿萍的酥胸，一边吻着阿萍的香唇.\n"NOR,environment(me));
                     me->add("qi",-30);
                     me->add("jing",-30);
                     break;
             case 1:
                     message("vision",HIY""+me->name()+"咬着阿萍的耳朵,右手在她的丰臀上四处乱摸.\n"NOR,environment(me));
                     me->add("qi",-35);
                     me->add("jing",-40);
                     break;
             case 2:
                     message("vision",RED""+me->name()+"大汗淋漓，呼呼的喘着粗气，阿萍则凤目微闭，不停的娇吟!\n",environment(me));
                     me->add("qi",-45);
                     me->add("jing",-45);
                     break;
             }
      
  return 1;
}

   

int over(object me)
{
   message("vision","你纵欲之后，疲惫的从阿萍香软的胴体上爬了下来\n",me);
    if(me->query("max_jingli")<1000)
      {
         message("vision",HIY"阿萍显然对你很不满意，嘴里不停的嘟如着：真是没用...\n"NOR,me);
         me->delete_temp("fucking");
         me->delete_temp("can_fuck");  
         return 1;
      }
     message("vision",HIY"阿萍懒懒的躺在床上，雪白的胴体赤裸的呈现在你面前。。。\n"NOR,me);
     message("vision",HIY"阿萍把嘴附到你耳边：告诉你一个秘密...\n"NOR,me);
     me->add("qi",-100);
     me->add("jing",-100);
     remove_call_out("mimi");
     call_out("mimi", 4, me);
     return 1;
}