// tang wuhuo.c 唐无火

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("唐无火", ({ "tang wuhuo", "tang" }));
	set("nickname", HIW "不温不火" NOR);
	set("long", 
		"他是唐门第七代弟子中的杰出人物。处事为人八面玲珑，做事\n"
		"稳稳当当，脾气不急不燥。江湖人称“不温不火”唐大侠。\n"
		"他大约四十有余，笑容可掬，双目隐有精芒闪烁。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 98);
	set("int", 90);
	set("con", 90);
	set("dex", 92);
	
	set("qi", 30000);
	set("eff_qi", 30000);
	set("max_qi", 30000);
        set("jing", 30000);
	set("eff_jing", 30000);
	set("max_jing", 30000);
	set("neili", 80000);
	set("max_neili", 80000);
	set("jiali", 60);
	set("combat_exp", 3800000);
	set("score", 60000);

	set_skill("force", 200);
	set_skill("biyun-xinfa",300);
	set_skill("dodge", 100);
	set_skill("qiulinshiye", 200);
	set_skill("strike", 100);
	set_skill("unarmed",100);
	set_skill("biye-wu", 100);
	set_skill("parry", 100);
	set_skill("throwing", 100);
	set_skill("zhuihun-biao", 300);
	set_skill("literate", 100);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "zhuihun-biao");
	map_skill("throwing", "zhuihun-biao");
	
	create_family("唐门", 7, "弟子");
	set("class", "tangmen");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "strike.meng" :),
		(: perform_action, "strike.meng" :),
		(: perform_action, "dodge.rain" :),
                (: perform_action, "dodge.wu" :),
	}) );

	setup();
	carry_object("/d/tangmen/obj/gangbiao1")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 70) {
		command("say 唐门虽然以暗器为主，但还是要辅以内力。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在碧云心法上多下点功夫？");
		return;
	}
	if (ob->query_int() < 24) {
		command("say 唐门历来注重弟子的文学修为。");
		command("say 本派功夫要能熟练运用，必须能体会其中所含深远意境，悟性差了是不行的。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("say 唐门武学精深博大，你好好修习，将唐门发扬光大。");
	command("recruit " + ob->query("id"));
}
