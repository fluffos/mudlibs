// tang wuqing.c 唐无情

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("唐无情", ({ "tang wuqing", "tang" }));
	set("nickname", HIW "铁石心肠" NOR);
	set("long", 
		"他就是刑堂堂主唐无情，唐门刑法都有他执行。\n"
		"手段狠毒，残酷无情，江湖上听到他的名号都不寒而栗。\n"
		"他大约五十有余，面无表情，双眼闪着冷光。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 30);
	set("dex", 32);
	
	set("max_qi", 11000);
	set("max_jing", 13000);
	set("neili", 13000);
	set("max_neili", 13000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 100000);

	set_skill("force", 120);
	set_skill("biyun-xinfa",120);
	set_skill("dodge", 120);
	set_skill("qiulinshiye", 120);
	set_skill("strike", 120);
	set_skill("biye-wu", 220);
	set_skill("parry", 120);
	set_skill("unarmed",100);
	set_skill("throwing", 120);
	set_skill("liuxing-biao", 320);
	set_skill("literate", 100);
	set_skill("dusha-zhang", 180);
	set_skill("lansha-shou", 180);
	set_skill("hand", 180);
	set_skill("strike", 180);
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "liuxing-biao");
	map_skill("throwing", "liuxing-biao");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	create_family("唐门", 6 ,"刑堂堂主");
	set("class", "tangmen");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/tangmen/obj/gangbiao1")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 80) {
		command("say 唐门虽然以暗器为主，但还是要辅以内力。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在碧云心法上多下点功夫？");
		return;
	}
	if (ob->query_int() < 25) {
		command("say 唐门历来注重弟子的文学修为。");
		command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("say 唐门武学精深博大，你好好修习，将唐门发扬光大。");
	command("recruit " + ob->query("id"));
}
