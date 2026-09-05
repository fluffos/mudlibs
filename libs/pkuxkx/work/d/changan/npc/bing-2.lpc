// bing.c 官兵

inherit NPC;

void create()
{
	set_name("将军府亲兵", ({ "qin bing", "bing" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "这是一位将军府的亲笔，十分神气。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
        set("shen_type",1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);


 
	setup();
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/junfu")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	//me->apply_condition("killer", 100);
	kill_ob(me);
	return 1;
}
