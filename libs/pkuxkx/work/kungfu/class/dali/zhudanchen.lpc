// whuan
// zhu danchen

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
#include "/new_quest/qzhengpai.h"
#include "/new_quest/quest.h"

void create()
{
	set_name("朱丹臣", ({ "zhu danchen", "zhu"}));
	set("long", "他手拿一册诗书，正在用心诵读，腰畔插着一对判官笔。\n");
	set("title",HIR"大理王府"+HIC"武将"NOR);
	set("gender", "男性");
	set("age", 35);
	set("inquiry", ([
		"段正淳": "我家王爷生性风流。",
		"段誉"  : "我家小王子最近跑丢了，怎么也找不到。",
    "quest":   (: ask_quest() :),
    "cancelquest":   (: ask_cancel() :),
    "取消任务":   (: ask_cancel() :),			
	    ]));
	set_skill("cuff", 100);
	set_skill("jinyu-quan", 100);
	set_skill("dodge", 100);
	set_skill("duanjia-shenfa", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("literate", 150);
	set_skill("sword", 100);
	set_skill("duanjia-jian", 100);
	set_skill("duanjia-xinfa",100);
	map_skill("cuff","jinyu-quan");
	map_skill("dodge","duanjia-shenfa");
	map_skill("force","duanjia-xinfa");
	map_skill("sword","duanjia-jian");
	prepare_skill("cuff","jinyu-quan");
	
	set("str", 32);
	set("int", 21);
	set("con", 27);
	set("dex", 23);
	set("per", 35);
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
	carry_object("/d/dalicheng/obj/panguanbi")->wield();
}

void attempt_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");

        return notify_fail("暂未开放。\n");
        if (myfam && myfam["family_name"] != "大理王府"){
        command("ah "+(string)ob->query("id"));
        command("say "+ RANK_D->query_respect(ob) +"如果想加入大理王府，可以先找褚兄弟。\n");
        return;
        }

        if (myfam["master_id"] =="duan zhengchun" || myfam["master_id"] =="yideng dashi"){
          command("say 岂敢！岂敢！");
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
