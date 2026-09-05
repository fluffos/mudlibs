// Npc: /kungfu/class/shaolin/qing-wei.c
// Date: YZC 96/01/19

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("清为比丘", ({
		"qingwei biqiu",
		"qingwei",
		"biqiu",
	}));
	set("long",
		"他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含\n"
		"着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 23);
	set("int", 19);
	set("con", 22);
	set("dex", 20);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 50000);
	set("score", 500);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo-zhang", 50);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "banruo-zhang");

	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 40, "弟子");

	setup();

        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}


void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "男性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}
        if( (string)ob->query("family/family_name") != "少林派" && ob->query("is_shaolin"))
        {
                command ("say 阿弥陀佛！" + RANK_D->query_respect(ob) +"既然已经叛出少林，那又何必回少林。");
                return;
        }
        
	if( !ob->query("family")&&ob->query("combat_exp")>5000&&!ob->query("reborn/chushi")) 
	{
		command ("say 阿弥陀佛！本寺不收经验太高的普通百姓！\n");
		return;
	}
	
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫僧就收下你做『俗家弟子』了。");
	}
	command("say 阿弥陀佛，善哉！善哉！");
	command("recruit " + ob->query("id"));
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
		      ob->set("is_shaolin", 1);
          if (this_player()->query("class")=="bonze")
            ob->set("title",HIR "少林" NOR + CYN "小沙弥" NOR);
          else
            ob->set("title",HIR "少林" NOR + CYN "俗家弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
        }

}

void re_rank(object student)
{
        if (this_player()->query("class")=="bonze")
          student->set("title",HIR "少林" NOR + CYN "小沙弥" NOR);
        else
          student->set("title",HIR "少林" NOR + CYN "俗家弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, student->query("title"));
}
