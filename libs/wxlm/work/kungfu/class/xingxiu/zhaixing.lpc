// zhaixing.c 摘心毒手

inherit NPC;
inherit F_MASTER;

#include "xingxiu.h"

string ask_me();
string ask_book();

void create()
{
	set_name("摘心毒手", ({ "zhaixing zi", "zhaixing" }));
	set("nickname", "星宿派大师兄");
	set("long", 
		"他就是古春秋的大弟子、星宿派大师兄摘心毒手。\n"
		"他三十多岁，脸庞瘦削，眼光中透出一丝乖戾之气。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 2400);
	set("max_jing", 1200);
	set("neili", 2800);
	set("max_neili", 2800);
	set("jiali", 35);
	set("combat_exp", 320000);
	set("shen_type", -1);

	set_skill("force", 140);
	set_skill("huagong-dafa", 140);
	set_skill("guixi-gong", 140);
	set_skill("throwing", 120);
	set_skill("feixing-shu", 120);
	set_skill("dodge", 120);
	set_skill("zhaixinggong", 120);
	set_skill("whip", 80);
	set_skill("chanhun-suo", 80);
	set_skill("strike", 80);
	set_skill("chousui-zhang", 80);
	set_skill("claw", 80);
	set_skill("sanyin-wugongzhao", 80);
	set_skill("parry", 130);
	set_skill("poison", 115);
	set_skill("medical", 80);
	set_skill("xingxiu-qishu", 80);

	set("no_teach", ([
		"huagong-dafa" : "化灵大法要老仙亲自传授。",
	]));

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("throwing", "feixing-shu");
	map_skill("whip", "chanhun-suo");

	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");

	set("inquiry", ([
		"炼心弹"    : (: ask_me :),
		"秘籍"      : (: ask_book :),
		"天山器法"  : (: ask_book :),
	]));
	set("dan_count", 1);
	set("book_count", 1);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "claw.zhua" :),
		(: perform_action, "strike.biyan" :),
		(: perform_action, "strike.huolang" :),
		(: perform_action, "strike.huoqiu" :),
		(: perform_action, "strike.huoyan" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 150);
	set_temp("apply/unarmed_damage", 150);

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/clone/weapon/lianzi")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了。");
	welcome(ob);
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (query("dan_count") < 1)
		return "你来晚了，没有练心弹了。";

	add("dan_count", -1);
	ob = new("/d/xingxiu/obj/lianxindan");
	ob->move(this_player());
	return "这些练心弹够你用的了吧。";
}

string ask_book()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (query("book_count") < 1)
		return "你来晚了，现在没什么剩的了。";

	add("book_count", -1);
	ob = new("/clone/book/throw_book");
	ob->move(this_player());
	return "好吧，这本书你拿回去好好看看吧。";
}


