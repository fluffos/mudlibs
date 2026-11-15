// XieXun.c
// pal 1997.05.09


#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("谢巽", ({"xie xun", "xie", "xun", }));
	set("long",
	"他是一位身材魁伟异常的的老者，身穿一件白布长袍。\n"
	"他满头黄发，威风凛凛，真如天神一般，只是两只眼睛并不睁开。\n"
	);

	set("title",HIG "明教" HIY "金毛狮王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 63);
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);

	set("combat_exp", 900000);
	set("score", 800000);

        set_skill("cuff",460);
        set_skill("dodge",460);
        set_skill("force", 460);
        set_skill("blade",460);
        set_skill("hand", 460);
        set_skill("literate",410);
        set_skill("qingfu-shenfa", 460);
        set_skill("qishang-quan",480);
        set_skill("shenghuo-shengong", 460);
        set_skill("pili-shou", 460);
        set_skill("parry", 460);
        set_skill("lieyan-dao",460);
        set_skill("martial-cognize", 300);

        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("cuff", "qishang-quan");
        map_skill("parry", "qishang-quan");
        map_skill("blade", "lieyan-dao");
        map_skill("hand", "pili-shou");

        prepare_skill("cuff","qishang-quan");
	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform cuff.shang") :),
		(: command("perform cuff.fei") :),
	}) );
	create_family("明教", 36, "护法法王");
	setup();
    	carry_object("/d/mingjiao/obj/baipao")->wear();
}

int accept_object(object who, object ob)
{
	if ((string)ob->query("id") == "yi xin")
	{
		say("谢巽说道：谢谢你终于让我知道了阳教主的下落，我"
		    "们明教上下无不感激！\n");
	}
	return 1;
}
void attempt_apprentice(object ob)
{
        command("say 老夫不收弟子。");
        command("say 这位"+RANK_D->query_respect(ob)+"还是请回吧。");
        return;
}
