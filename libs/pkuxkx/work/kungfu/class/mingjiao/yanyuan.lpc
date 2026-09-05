// yanyuan.cn.c
#include <title.h>
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void do_answer(string);

void create()
{
        set_name("颜垣", ({ "yan yuan", "yan" }));
        set("title",GRN "明教" NOR + YEL +"掌旗使" NOR);
        set("long","颜垣是明教厚土旗掌旗使。\n");
        set("gender", "男性");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 20);
        set("combat_exp", 50000);
        set_skill("force", 50);
        set_skill("guangming-shenghuogong", 40);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("hanbing-zhang", 40);
        set_skill("datengnuo-bufa", 40);
        set_skill("strike", 50);
        set_skill("literate",40);
        map_skill("force", "guangming-shenghuogong");
        map_skill("parry", "hanbing-zhang");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("strike", "hanbing-zhang");
        prepare_skill("strike", "hanbing-zhang");
        create_family("明教", 21, "弟子");
        setup();
        carry_object("/d/mingjiao/obj/huangshan")->wear();
       }

void attempt_apprentice(object ob)
{
if (((string)ob->query("family/family_name") != "明教" && (int)this_player()->query("combat_exp")>100 )&&(int)this_player()->query("reborn/chushi")<1)
         {   
         	  command("say 我派只收无家可归的孤儿。");
            return;
        }
        if((int)ob->query("betrayer")>=1)
        {
            command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
            return;
        }
        else if ((string)ob->query("gender")=="无性")
        {
            command("say 你无根无性，无法修炼明教的绝学！");
            return;
        }
           command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
           command("recruit "+ob->query("id"));
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
          if (ob->query("age")<20)
            ob->set("title",GRN "明教" NOR + YEL +"教童" NOR);
          else
            ob->set("title",GRN "明教" NOR + YEL +"教徒" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title")); 
        }
}
void re_rank(object student)
{
        if (student->query("age")<20)
          student->set("title",GRN "明教" NOR + YEL +"教童" NOR);
        else
          student->set("title",GRN "明教" NOR + YEL +"教徒" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, student->query("title"));
}

