// yideng.c 一灯大师 By River@SJ 2002.6.6

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("一灯大师", ({ "yideng dashi", "yideng", "dashi" }) );
	set("title",HIW"南帝"NOR);
	set("gender", "男性" );
	set("class", "bonze");
	set("age", 78);
	set("str", 35);
	set("con", 40);
	set("dex", 35);
	set("int", 35);
	set("per", 28);
	set("unique", 1);

	set("max_qi", 12000);
	set("max_jing", 7500);
	set("eff_jingli", 8500);
	set("neili", 22000);
	set("max_neili", 22000);
	set("jiali", 150);
	set("combat_exp", 4900000);
	set("score", 20000);

	create_family("天龙寺", 12, "俗家弟子");

	set("long", "一个身穿粗布僧袍，两道长长的白眉从眼角垂了下来，面目慈祥，\n"+
		"眉间虽隐含愁苦，但一番雍容高华的神色，却是一望而知。\n");

	set("combat_exp", 4900000);

	set_skill("parry", 400);
	set_skill("dodge", 380);
	set_skill("qingyan-zhang", 380);
	set_skill("strike", 380);
	set_skill("buddhism",200);
	set_skill("force", 400);
	set_skill("literate", 250);
	set_skill("sword", 180);
	set_skill("duanjia-jianfa", 380);
	set_skill("cuff", 200);
	set_skill("axe",200);
	set_skill("pangen-fu",380);
	set_skill("duanjia-quan", 400);
	set_skill("yiyang-zhi", 400);
	set_skill("finger", 400);
	set_skill("qiantian-yiyang", 400);
	set_skill("tianlong-xiang", 400);

	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "duanjia-jianfa");
	map_skill("sword", "duanjia-jianfa");
	map_skill("force", "qiantian-yiyang");
	map_skill("cuff", "duanjia-quan");
	map_skill("strike", "qingyan-zhang");
	map_skill("finger","yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");
	set("inquiry", ([
		"here": "这里便是石屋。",
	]));

	setup();
	carry_object("/d/tls/obj/jiasha")->wear();
	carry_object("/d/tls/obj/sengxie")->wear();
}

void attempt_apprentice(object ob)
{
	if ( ob->query_skill("qiantian-yiyang",1) < 180 ){
		command ("hmm");
		command ("say 你乾天一阳功如此之差，我可不收你！");
		return;
	}
	if( ob->query_int(1) < 34){
		command("say 武学之道必须悟性高，依我看" + RANK_D->query_respect(ob) + "的资质似乎不够？");
		return;
	}
	if(ob->query("shen") < 0){
		command("say 大理乃堂堂皇室，而这位" + RANK_D->query_respect(ob) + "眼露凶光，我看不适合在我大理呆下去了。");
		return;
	}
	if(ob->query_skill("liumai-shenjian", 1)){
		command("say 这位" + RANK_D->query_respect(ob) +"已经学会了六脉神剑，不再适合拜我为师了。");
		return;
	}
/*
	if (ob->query("tls")) {
		command ("say 你已经是天龙寺出家弟子了，我不能再收你了！");
		return;
	}
*/
	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
	command("recruit " + ob->query("id") );
	ob->delete("tls");
	ob->delete("class");
	ob->set("title",HIW"大理国南帝传人"NOR);
}
