// heiyutangzhu.c
//Made by goodtaste
//1999.5.21


#include <ansi.h>

inherit NPC;
int ask_pk();

void create()
{
	seteuid(getuid());
	set_name("欧阳敏", ({ "ouyang min", "ouyang", "min",}) );
	set("title", HIY "红雨堂主" NOR);
        set("long","杀手帮红雨堂堂主，也是杀手帮唯一的女性，貌美无双\n");
	set("gender", "女性" );
	set("age", 20);
	set("attitude", "peaceful");
	set("str", 30);
	set("con", 30);
	set("int", 27);
	set("dex", 23);
        set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("shen_type", 1);
	set("combat_exp", 900000);
    set("per",40);
        set_skill("force", 110); 
	set_skill("sword", 110);
	set_skill("dodge", 110);
	set_skill("parry", 110);
      set_skill("yunu-jianfa", 91);
	set_skill("chuforce", 260); 
	set_skill("liuyun", 250);
        map_skill("force", "chuforce");
        map_skill("parry", "yunu-jianfa");
      map_skill("sword", "yunu-jianfa");
      map_skill("dodge", "liuyun");
	set("chat_chance", 5);
	set("chat_msg", ({
          "欧阳敏凝眸低唱：几番风雨几度情，孤灯独守到天明....\n",
	}) );
      set("inquiry",([
              "pk" : ( : ask_pk : ),
              "PK" : ( : ask_pk : ),
              "杀手" : ( : ask_pk : ),
                ]));
        add_money("gold", 3);
        setup();
        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/ling");
	

       
        
}

void init()
{	
	
 }


int accept_object(object who, object ob)
{
  if(who->query_temp("asked")!=1) 
    {
           say("欧阳敏说道："+RANK_D->query_respect(who)+"送给我这样贵重的东西，阿敏可不敢要\n");
           return 0;
    }
           if(ob->value()>=400000&&ob->query("money_id")) 
   {
              remove_call_out("destroying");
              call_out("destroying", 1, this_object(), ob);       
              who->set_temp("gold_given",1);
              who->set_temp("asked",0);
              say("好了，这位"+RANK_D->query_respect(who)+"您可以进去了\n");
              return 1;
   }
           else
            {
              say("欧阳敏轻轻的说道：这样的东西恐怕帮主不会喜欢，你还是快走吧，别惹帮主不高兴\n");
              return 0;
            }
}            
            
int ask_pk()
{
   object me=this_player();
   if(me->query("age")<15)
   {
      if(me->query("gender")=="男性")
        {
           say("欧阳敏关爱的说道：这位小弟弟，这里是很危险的，到别的地方去玩吧\n");
           return 1;
        }


      if(me->query("gender")=="女性")
        {
           say("欧阳敏关爱的说道：这位小妹妹，这里是很危险的，到别的地方去玩吧\n");
           return 1;
        }

      if(me->query("gender")=="无性")
        {
           say("欧阳敏关爱的说道：这位小公公，这里是很危险的，到别的地方去玩吧\n");
           return 1;
        }
   }
   if(me->query_temp("gold_given"))
   {
     say("欧阳敏说道：不用再给钱了，赶快进去吧!\n");
     return 1;
   }
    me->set_temp("asked",1);
    say("欧阳敏说道：帮主的吩咐，凡是要加入杀手帮的都必须孝敬他老人家一些东西\n");
    return 1;
}
