// fengbuping.c -封不平
#include <ansi.h>
inherit NPC;
#include <title.h>
inherit F_MASTER;
int ask_xueyi();

void create()
{
        set_name("成不忧",({"cheng buyou","cheng","buyou"}));
	set("title", GRN "华山" NOR + YEL "剑宗" NOR + CYN "传人" NOR);
        set("long",
                "华山派剑宗传人。\n"
                "他是华山剑宗的第一高手。剑气之争剑宗一败涂地，封不平隐居苦练，。\n");
        set("gender", "男性");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 26);
        set("con", 26);
        set("dex", 26);

        set("max_qi",  2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("score", 10000);

        set_skill("force", 100);
        set_skill("huashan-neigong", 100);
        set_skill("dodge", 120);
        set_skill("huashan-shenfa", 120);
        set_skill("parry", 120);
        set_skill("sword", 130);
        set_skill("huashan-jianfa", 120);
        set_skill("strike", 100);
        set_skill("hunyuan-zhang", 100);
		set_skill("xiyi-jian",150);
        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派" , 18, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name")!="华山派")
	{
		command("say 你非我派弟子，我不能收你。");
		return ;
	}
	if (!ob->query("huashan_newskills/jianzong"))
	{
		command("say 我只会传授剑宗弟子武功。");
		return;
	}
	command("say 好吧，小兄弟！我今天收下你了！\n");
	command("recruit "+ob->query("id"));
}
void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	{
		ob->set("title",GRN "华山派" NOR + RED +"剑宗弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	  ob->set_title(TITLE_RANK, ob->query("title"));
	}
}