// whuan
// zhu wanli

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("褚万里", ({ "zhu wanli", "zhu"}));
    set("long","他是一位身穿黄衣的军官，约莫三十来岁年纪，脸上英气逼人。手持一根铁杆。\n");
	set("title",HIR"大理王府"+HIC"武将"NOR);
	set("gender", "男性");
	set("age", 35);
	set("inquiry", ([
		"段正淳": "我家王爷生性风流。",
	    ]));
	set_skill("cuff", 60);
	set_skill("jinyu-quan", 60);
	set_skill("dodge", 50);
	set_skill("duanjia-shenfa", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("literate", 65);
	set_skill("staff", 80);
	set_skill("duanjia-xinfa",60);
	map_skill("cuff","jinyu-quan");
	map_skill("dodge","duanjia-shenfa");
	map_skill("force","duanjia-xinfa");
	prepare_skill("cuff","jinyu-quan");
	set("str", 32);
	set("int", 21);
	set("con", 27);
	set("dex", 23);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);
	set("combat_exp", 500000);
	set("attitude", "peaceful");
	set("shen_type", 1);
	create_family("大理段家", 15, "弟子");
	setup();
	carry_object("/d/dalicheng/obj/ycloth")->wear(); 	
	carry_object("/d/dalicheng/obj/diaogan")->wield();
}

void attempt_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");

        return notify_fail("暂未开放。\n");
        if (myfam && myfam["family_name"] == "大理王府"){
        command("ah "+(string)ob->query("id"));
        command("say "+ RANK_D->query_respect(ob) +"不必谦虚，我们共同切磋如何？\n");
        return;
        }

        if( (string)ob->query("gender") == "无性" ){
                command ("say 大理王府向来不收身体残缺之人。");
                return;
        }

        if( (int)ob->query("combat_exp") >= 1000 && (int)ob->query("reborn/chushi")<1 ) {
                command ("say 你的功夫已有根基，我岂敢做你的师傅？");
                return;
        }
        if( (int)ob->query("str") < 20 ){
                command ("say 我看你的膂力太差，并不适合在王府当差。");
                return;
        }
        if ((string)ob->query("family/family_name") == "灵鹫宫" && ob->query("lingjiu/xiulian")){
                command("say 你想干什么？修炼完再来吧！");
                return;         
        }
        command("say 好吧，以后你就先就在王府当差，干些杂活吧。");
        command("recruit " + ob->query("id"));
        ob->set("title", HIR"大理王府"+HIY"随从"NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, HIR"大理王府"+HIY"随从"NOR);
}
