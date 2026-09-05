// xiaoling.c 小玲
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
/*string ask_me();
void consider();*/
void create()
{
        set_name("小玲", ({ "xiao ling","ling" }));
        
         set("title",GRN "古墓派" NOR + YEL +"女使" NOR);
        set("long",
                "她是神雕大侠收养的孤儿\n"
                "她看起来十多岁，容貌秀丽，别有一番可人之处。\
n");
        set("gender", "女性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 24);
        set("per", 25);
        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 50000);
        set("score", 5000);
/*set("inquiry", ([
                "冰魄杖" : (: ask_me :),
                "name"   : "我就是阿紫呀！！",
        ]) );
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
  */   
	 set_skill("force", 60);
        set_skill("yunu-xinfa", 60);
	set_skill("cuff", 70);
	set_skill("meinu-quan", 70);
        set_skill("dodge", 80);
        set_skill("xianyun", 80);
        set_skill("parry", 70);
        set_skill("sword", 70);
        set_skill("yunu-jianfa", 70);
        set_skill("literate", 50);

        map_skill("force", "yunu-xinfa");
	map_skill("cuff", "meinu-quan");
        map_skill("dodge", "xianyun");
	 set_skill("parry", 70);
        set_skill("sword", 70);
        set_skill("yunu-jianfa", 70);
        set_skill("literate", 50);

        map_skill("force", "yunu-xinfa");
	map_skill("cuff", "meinu-quan");
        map_skill("dodge", "xianyun");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "yunu-jianfa");
        map_skill("sword", "yunu-jianfa");

	prepare_skill("cuff", "meinu-quan");

       

        create_family("古墓派" , 5, "弟子");
        setup();
         carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
void attempt_apprentice(object ob)
{
        if((int)ob->query("betrayer")>=5)
        {
          command("say 你多次背信弃义，我怎可信你!\n");
          command("say"+RANK_D->query_respect(ob)+"你多次残害黎民百姓，我怎可容你.\n");
          return;
        }
        
        if((string)ob->query("gender")=="无性")
        {
          command ("say 你不男不女的，我怎可收你.\n");
          command("say"+RANK_D->query_respect(ob)+"你不男不女的，我怎可收你.\n");
          return;
	      }
	      
	      if ( ob->query("class")=="bonze")
	      {
          command("say 我派不收佛门弟子，" + RANK_D->query_respect(ob) + "请现还俗了在来。");
          return;
        }
        
        command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
        command("recruit "+ob->query("id"));
        
        if ( ob->query("age")<16)
        {
          if( ob->query("gender")!="女性")
          {
            ob->set("title",RED "古墓派" NOR + GRN +"男童" NOR);
//title系统记录玩家title by seagate@pkuxkx
	          ob->set_title(TITLE_RANK, RED "古墓派" NOR + GRN +"男童" NOR);
	        }
          else
          {
            ob->set("title",RED "古墓派" NOR + GRN +"女童" NOR);
//title系统记录玩家title by seagate@pkuxkx
	          ob->set_title(TITLE_RANK, RED "古墓派" NOR + GRN +"女童" NOR);
	        }
        }
        else 
        {
          if( ob->query("gender")!="女性")
          {
            ob->set("title",RED "古墓派" NOR + GRN +"使者" NOR);
//title系统记录玩家title by seagate@pkuxkx
	          ob->set_title(TITLE_RANK, RED "古墓派" NOR + GRN +"使者" NOR);
	        }
          else
          {
            ob->set("title",RED "古墓派" NOR + GRN +"使女" NOR);
//title系统记录玩家title by seagate@pkuxkx
	          ob->set_title(TITLE_RANK, RED "古墓派" NOR + GRN +"使女" NOR);
	        }
        }        
}

