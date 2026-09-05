// luo.c 骆冰

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("骆冰", ({ "luo bing", "luo","bing" }));
	set("title", HIR "红花会"HIG"十一当家" NOR);
	set("nickname", HIG "鸳鸯刀" NOR);
	set("long", 
"她是一个秀美的少妇。一手短刀，一手握着一柄长刀。\n");
	set("gender", "女性");
	set("class", "fighter");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 28);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1400);
	set("max_jing", 700);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 15000000);

	set_skill("literate", 300);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);

	set_skill("bingchuan-xinfa", 300);
	set_skill("zhuangzi-mengwu", 300);
	set_skill("luojia-dao", 300);
	
	map_skill("dodge", "zhuangzi-mengwu");
	map_skill("force", "bingchuan-xinfa");
	map_skill("blade", "luojia-dao");
	map_skill("parry", "luojia-dao");
	set("env/wimpy", 20);
      create_family("红花会", 3, "弟子");

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
         if ((string)ob->query("family/family_name")!="红花会" )
        {
         command("say 我不收外派弟子。");
         command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜马善均。");
                return;
        }if ((int)ob->query("shen") < 100000) {
                command("say 红花会所作所为都是扶危济困。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，本座一定收你。");
                return;
        }
        if ((int)ob->query("score")<1500){
            command("sigh"+ob->query("id"));
            command("say 你若为本门立点功劳,本座一定收你");
            return;      
            }
        if ((int)ob->query_skill("bingchuan-xinfa", 1) < 50) {
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
	        ob->set_title(TITLE_RANK, HIR "红花会" NOR + HIY +"堂主" NOR);
        }
        return;
}
void re_rank(object student)
{
        student->set("title",HIR "红花会" NOR + HIY +"堂主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, HIR "红花会" NOR + HIY +"堂主" NOR);
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

