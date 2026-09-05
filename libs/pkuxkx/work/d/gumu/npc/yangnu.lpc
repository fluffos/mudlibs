//yangn.c 扬女
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask();
//void consider();*/
void create()
{
        set_name("杨女", ({ "yang nu","yang" ,"nu"}));
        
         set("title",GRN "古墓派" NOR + MAG +"圣女" NOR);
		 set("start_room","/d/gumu/caodi");
        set("long",
                "她是神雕大侠夫妇的养女。\n"
                "她看起来十多岁，天生丽质，只是脸色略显白色。\
n");
        set("gender", "女性");
        set("age", 19);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 32);
        set("con", 20);
        set("dex", 30);
        set("per", 50);
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set("score", 80000);
/*set("inquiry", ([
                "冰魄杖" : (: ask_me :),
                "name"   : "我就是阿紫呀！！",
        ]) );
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
  */   
	 set_skill("force", 150);
        set_skill("jiuyin-shengong", 150);
	
	set_skill("strike", 150);
	set_skill("xiaohun-zhang", 150);
        set_skill("dodge", 180);
        set_skill("xianyun", 180);
        set_skill("parry", 150);
        set_skill("claw", 180);
        set_skill("jiuyin-baiguzhao", 180);
//	set_skill("sword",150);
//	set_skill("yunu-jianfa",120);
        set_skill("literate", 80);

       

        map_skill("force", "jiuyin-shengong");
	map_skill("claw", "jiuyin-baiguzhao");
        map_skill("dodge", "xianyun");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "jiuyin-baiguzhao");
  //      map_skill("sword", "yunu-jianfa");
	map_skill("strike","xiaohun-zhang");
	prepare_skill("claw", "jiuyin-baiguzhao");

        set("inquiry", ([
                "进墓" : (: ask_me :),
           	"九阴真经" : (: ask :),
        ]));

        create_family("古墓派" , 4, "弟子");
        setup();
       
}
void attempt_apprentice(object ob)
{
	if((string)ob->query("family/family_name")!="古墓派")
		{
		 command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜小虹小玲。"); 
                return;
        	}
	 if ((int)ob->query("max_neili") < 300)
		 {
		 command("say " + RANK_D->query_respect(ob) + "内力太低，再回去好好努力吧。"); 
                return;
        	}
        else
          {
        command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
        command("recruit "+ob->query("id"));
           }
       
}

void recruit_apprentice(object ob)
{
      if( ::recruit_apprentice(ob) )
      {	
			  if(ob->query("gender")=="女性")
			  {
          ob->set("title",GRN "古墓派" NOR + MAG +"女使" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, GRN "古墓派" NOR + MAG +"女使" NOR);
	      }
  			else
  			{
			    ob->set("title",GRN "古墓派"NOR + MAG + "使者" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, GRN "古墓派"NOR + MAG + "使者" NOR);
	      }
			
			  return;
		  }
}

void re_rank(object student)
{	
		  if(student->query("gender")=="女性")
			{
        student->set("title",GRN "古墓派" NOR + MAG +"女使" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, GRN "古墓派" NOR + MAG +"女使" NOR);
	    }
  		else
  		{
			  student->set("title",GRN "古墓派"NOR + MAG + "使者" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, GRN "古墓派"NOR + MAG + "使者" NOR);
	    }
	    
	    return;
}

string ask_me()
{	 mapping fam;
        object me=this_player();
        object ob;
	if (me->query("age")<16)
	{
	message_vision("杨女说道“好吧，我就带你去古墓吧。”\n",me);
		 me->move("/d/gumu/dating");
	return"好了，我要出去了。";
	}
	 if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
 	else
	{
	message_vision("杨女说道“好吧，我就带你去古墓吧。”\n",me);
		 me->move("/d/gumu/dating");
	return"好了，我要出去了。";
	}
	//if (me->query("age")>15)
	//return "你也不小了，还要进古墓。";
	//else
	//return RANK_D->query_respect(this_player()) +
        //        "与本派素无来往，不知此话从何谈起？";
//
}
	
	
  //      if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
 //               return RANK_D->query_respect(this_player()) +
  //              "与本派素无来往，不知此话从何谈起？";
string ask()
{	object me=this_player();
	me->set_temp("whip_book",1);
	   return"「九阴真经」是道家武学至上宝典，如果你帮我找回我古墓
	派的鞭法秘笈，我就告诉你藏经的地方。\n"  ;  
}
/*int accept_object(object who, object ob)
{       
        object me=this_player;

if ((string)ob->query("id")=="shouyin"){
                        write(
RED"神灵说道：壮士，真是有缘人啊!你可以进去了。\n"NOR
RED"神灵凌空一指，变出了一个出口。\n"NOR);
                        if(!(room=find_object("/d/guiyunzhuang/rukou")))
                                room=load_object("/d/guiyunzhuang/rukou");
                        room->set("exits/south","/d/guiyunzhuang/mihun");
                        remove_call_out("close_door");
                        call_out("close_door",8,room);
                        call_out("dest",1,ob);          
                        return 1;}
                return 0;
}*/
int accept_object(object who, object ob)
{
        object me = this_player();
       
        if((string)ob->query("id") == "whip book") 
        {
                if (me->query_temp("whip_book")!=1)
                {       command("say 多谢你帮我们找到了这秘笈。");
			
                        return 1;
		}
		else
                {
		command("say 多谢你帮我们找到了这秘笈。");
		command("say 终南山后有条小溪，溪底有条暗河，真经就藏在河底的一个小洞里。");
		me->set_temp("zhenjing",1);
		
		return 1;
		}
	}       
	else
		{command("say 这不是我想要的东西。");
		return 1;}
}
		
