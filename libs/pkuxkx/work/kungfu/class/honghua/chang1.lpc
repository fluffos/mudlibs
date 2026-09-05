// chang1.c 常赫志

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("常赫志", ({ "chang hezhi", "chang","hezhi" }));
	set("title", HIR "红花会"HIG"五当家" NOR);
	set("nickname", HIB "黑无常" NOR);
	set("long", 
"他身材又高又瘦，脸色蜡黄，眼睛凹进，眼角上有一粒黑痣，眉毛
斜斜的倒垂下来，形相甚是可怖。他是青城派慧侣道人的徒弟。黑沙
掌的功夫，江湖上无人能敌。黑白无常两兄弟是川江上著名的侠盗，
一向劫富济贫，不过心狠手辣，因此得了这难听的外号。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 42);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 14);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 5000000);

	set_skill("literate", 150);
  set_skill("strike", 150);
  set_skill("heisha-zhang", 150);
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);

	set_skill("bingchuan-xinfa", 150);
	set_skill("zhuangzi-mengwu", 150);
	set_skill("luohua-jian", 150);
	
	map_skill("dodge", "zhuangzi-mengwu");
  map_skill("strike", "heisha-zhang");
	map_skill("force", "bingchuan-xinfa");
	map_skill("sword", "luohua-jian");
	map_skill("parry", "luohua-jian");

  prepare_skill("strike", "heisha-zhang");

	set("env/wimpy", 20);
	create_family("红花会", 3, "弟子");
 	setup();
	carry_object("/clone/misc/cloth")->wear();

}

void attempt_apprentice(object ob)
{
         if ((string)ob->query("family/family_name")!="红花会" )
        {
         command("say 我不收外派弟子。");
         command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜马善均。");
                return;
        }
        if ((int)ob->query("shen") < 100000) 
        {
                command("say 红花会所作所为都是扶危济困。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，本座一定收你。");
                return;
        }
        if ((int)ob->query("score")<800)
        {
            command("sigh"+ob->query("id"));
            command("say 你若为本门立点功劳,本座一定收你");
            return;      
        }
        if ((int)ob->query_skill("bingchuan-xinfa", 1) < 50) 
        {
          command("say 你的冰川心法太低了，无法修习我的功夫。");
          command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在冰川心法上多下点功夫？");
                return;
        }
        if((int)ob->query("betrayer")>=1)
        {
                command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
      command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
      command("recruit "+ob->query("id"));
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
          ob->set("title",HIR "红花会" NOR + HIY +"堂主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
	      }
        return;
}

void re_rank(object student)
{
        student->set("title",HIR "红花会" NOR + HIY +"堂主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, student->query("title")); 
        return;
}

void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 50");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}