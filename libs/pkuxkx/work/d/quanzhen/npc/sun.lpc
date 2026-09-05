// Created by hacky
// data: 1997.10.10
               
#include <ansi.h>
#include <title.h> 
inherit NPC; 
inherit F_MASTER;
   

void create()
{
	set_name("孙不二", ({ "sun bu er" , "sun" }));
	set("nickname", HIB"清静散人"NOR);
        set("title",HIB"全真派"NOR+GRN"女真人"NOR);
		set("start_room","/d/quanzhen/jingrenf");
	set("long",
 "她是全真教的第二代弟子,全真七子中的唯一的一位女性,\n"
  );       
	set("gender", "女性");
	set("age", 39);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 27);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 350000);
	set("score", 10000);

	set_skill("daoxue-xinfa",100);
	set_skill("sword",110);
        set_skill("quanzhen-jian",100);
	set_skill("array", 80);
	set_skill("dodge", 100);
	set_skill("jinyan-gong", 120);
	set_skill("cuff", 100);
	set_skill("parry", 120);
        set_skill("yangxin-quan",100);
        set_skill("kongming-quan",80);
        set_skill("tiangang-beidou",100);
        set_skill("literate",80);
        set_skill("force",100);
        set_skill("xiantian-gong",90);

        map_skill("sword","quanzhen-jian");
	map_skill("dodge","jinyan-gong");
        map_skill("cuff","kongming-quan");
        map_skill("array","tiangang-beidou");
        map_skill("force","xiantian-gong");
        map_skill("parry","quanzhen-jian");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);
/*	set("inquiry", ([
        	"郭靖" :"靖儿是个好孩子，也没枉费我当年一番苦心，如今他现在正在\n"
			"襄阳前线配合官兵抵挡蒙古大军。\n",
	        "杨康" :"其实这孩子本性还是好的，只可惜“近朱者赤，近墨者黑”，古今亦然啊！\n",
	]) );
*/
	setup();
       
	create_family("全真派", 2, "弟子");
	carry_object(__DIR__"obj/robe")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}


void attempt_apprentice(object ob)
  
{       
        int exp;
        if( (string)ob->query("gender") != "女性" )
        {
	      command("say 我只收女弟子！你可以去拜我的师兄.");
           return;
        }
        if( (string)ob->query("family/family_name")!="全真派")
        {
             command("say " + RANK_D->query_respect(ob) + "还是先去拜程遥伽。");
             return;
        }
         if((int)ob->query("score")<600)
         {
          command ("say 你自问是否对本门尽力了?");
          return;
         }
         if ( (int)ob->query("shen")<10000)
        {
              command
          ("say " + RANK_D->query_respect(ob) + "是否还应该多做些善事?");
           return;
        }
        
                command("smile");
                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
                 
        exp = (int) ob->query("combat_exp");
        if( exp <= 25000 ) {
                ob->set("title",HIB"全真派"NOR+YEL"女弟子"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              ob->set_title(TITLE_RANK, HIB"全真派"NOR+YEL"女弟子"NOR);
                return ;
        } else if ( exp <= 50000 ) {
                ob->set("title",HIB"全真派"NOR+YEL"女道人"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              ob->set_title(TITLE_RANK, HIB"全真派"NOR+YEL"女道人"NOR);
                return ;
        } else  if ( exp<=75000 ) {
                ob->set("title",HIB"全真派"NOR+GRN"女道长"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              ob->set_title(TITLE_RANK, HIB"全真派"NOR+GRN"女道长"NOR);
                return ;
        } else {
                ob->set("title",HIB"全真派"NOR+GRN"女真人"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              ob->set_title(TITLE_RANK, HIB"全真派"NOR+GRN"女真人"NOR);
    }
}
