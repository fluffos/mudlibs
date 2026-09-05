// bing.c 官兵

inherit NPC;

void create()
{
	set_name("金吾卫卫士", ({ "jin wu", "weishi" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "金吾卫的卫士，负责巡逻长安，治理长安的职责。\n");
	set("attitude", "peaceful");
	set("changan_bing",1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 500000);
  set("shen_type",1);
 	set("max_qi", 3000);
 	set("max_jing", 3000);
 	set("neili", 3000);
 	set("max_neili", 3000);
 	set("jiali", 50);

	set_skill("unarmed", 150);
	set_skill("hand",150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("blade", 150);
	set_skill("force", 150);
	set_skill("halberd",150);
	set_skill("bixue-xinfa", 150);
	set_skill("kuangfeng-dao", 150);
	set_skill("longfeng-xiang", 150);
	set_skill("huzhua-shou", 150);
	set_skill("lujia-ji", 150);
	map_skill("force", "bixue-xinfa");
	map_skill("dodge", "longfeng-xiang");
	map_skill("parry", "huzhua-shou");
	map_skill("hand", "huzhua-shou");
	map_skill("blade", "kuangfeng-dao");
	map_skill("halberd", "lujia-ji");
	
	prepare_skill("hand", "huzhua-shou");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);

	setup();
	carry_object("/clone/weapon/fangtianji")->wield();
	carry_object(__DIR__"obj/mingguang-jia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("cakiller")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	me->apply_condition("cakiller", 60);
	kill_ob(me);
	return 1;
}
