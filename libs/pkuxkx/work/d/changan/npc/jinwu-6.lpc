// bing.c 官兵

inherit NPC;

void create()
{
	set_name("金吾卫亲兵", ({ "jin wu", "qinbing" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "金吾卫大将军的亲兵。\n");
	set("attitude", "peaceful");
	set("changan_bing",1);

	set("str", 34);
	set("dex", 20);
	set("combat_exp", 1500000);
  set("shen_type",1);
 	set("max_qi", 5000);
 	set("max_jing", 5000);
 	set("neili", 5000);
 	set("max_neili", 5000);
 	set("jiali", 75);

	set_skill("unarmed", 220);
	set_skill("hand",220);
	set_skill("dodge", 220);
	set_skill("parry", 220);
	set_skill("blade", 220);
	set_skill("force", 220);
	set_skill("halberd",220);
	set_skill("bixue-xinfa", 220);
	set_skill("kuangfeng-dao", 220);
	set_skill("longfeng-xiang", 220);
	set_skill("huzhua-shou", 220);
	set_skill("lujia-ji", 220);
	map_skill("force", "bixue-xinfa");
	map_skill("dodge", "longfeng-xiang");
	map_skill("parry", "huzhua-shou");
	map_skill("hand", "huzhua-shou");
	map_skill("blade", "kuangfeng-dao");
	map_skill("halberd", "lujia-ji");
	
	prepare_skill("hand", "huzhua-shou");
	set_temp("apply/attack", 75);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 75);
	set_temp("apply/armor", 200);

	setup();
	carry_object(__DIR__"obj/modao")->wield();
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

void kill_ob(object me)
{
	command("say 大胆毛贼，这里也是你们敢闯得？剁了喂狗！\n");
	if ( me->query_condition("cakiller")<100 )
	  me->apply_condition("cakiller", 100);
	::kill_ob(me);
}