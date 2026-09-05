// Created by hacky
// data: 1997.11.20
               
#include <ansi.h>
#include <title.h> 
inherit NPC; 
inherit F_MASTER;
void re_rank(object);      

void create()
{
	set_name("王处一", ({ "wang chuyi" , "wang" }));
        set("title",HIB"全真派"NOR+GRN"真人"NOR);
	set("long",
	"他是全真教的第二代弟子，仙风道骨，颌下三缕长须，头戴一顶紫金冠，身穿\n"
	"一件八卦道袍，手执拂尘，看上去飘飘然宛如神仙中人，俨然是一位得道高人。\n");
	set("gender", "男性");
	set("apprentice_available", 20);
	set("age", 53);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 300);
	set("combat_exp", 200000);
	set("score", 10000);

	set_skill("daoxue-xinfa",120);
	set_skill("sword",120);
        set_skill("quanzhen-jian",120);	
	set_skill("array", 100);
	set_skill("dodge", 100);
	set_skill("jinyan-gong", 100);
	set_skill("cuff", 120);
	set_skill("parry", 120);
        set_skill("yangxin-quan",100);
        set_skill("kongming-quan",100);
        set_skill("tiangang-beidou",100);
        set_skill("force",100);
        set_skill("xiantian-gong",100);

        map_skill("sword","quanzhen-jian");
	map_skill("dodge","jinyan-gong");
        map_skill("array","tiangang-beidou");
        map_skill("cuff","yangxin-quan");
        map_skill("force","xiantian-gong");
        map_skill("parry","quanzhen-jian");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);
	
	setup();
                	
	create_family("全真派", 2, "真人");
	carry_object(__DIR__"obj/robe")->wear();

}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本真人今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "男性" )
        {
	      command("say 我只收男弟子！\n");
           return;
        }
      if((string)ob->query("family/family_name")!="全真派")
   {
    command ("say"+RANK_D->query_respect(ob)+"若想入我重阳宫，可先败尹志平。\n");
   return;
    }
     if((int)ob->query("score")<650)
   {
   command ("say 你自问是否对本门尽力了?");
    return;
    }
     if((int)ob->query("shen")<20000)
   {
    command ("say 学武之人，德义为先，希望"+RANK_D->query_respect(ob)+"多做些善事\n");
   return;
      }
     if((int)ob->query("combat_exp")<20000)
    {
      command ("say 你还是先跟尹志平练几年再来拜我吧\n");
      return;
     }
        else {
                command("smile");
                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
         }
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
        re_rank(ob);
        add("apprentice_availavble", -1);
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 25000 ) {
                student->set("title",HIB"全真派"NOR+YEL"弟子"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              student->set_title(TITLE_RANK, HIB"全真派"NOR+YEL"弟子"NOR);
                return ;
        } else if ( exp <= 50000 ) {
                student->set("title",HIB"全真派"NOR+YEL"道人"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              student->set_title(TITLE_RANK, HIB"全真派"NOR+YEL"道人"NOR);
                return ;
        } else  if ( exp<=75000 ) {
                student->set("title",HIB"全真派"NOR+GRN"道长"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              student->set_title(TITLE_RANK, HIB"全真派"NOR+GRN"道长"NOR);
                return ;
        } else {
                student->set("title",HIB"全真派"NOR+GRN"真人"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              student->set_title(TITLE_RANK, HIB"全真派"NOR+GRN"真人"NOR);
    }
}

