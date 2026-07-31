inherit NPC;
inherit F_VENDOR;

void create()
{
	object ob;
	set_name("老板男人", ({ "husband", "man" }) );
	set("gender", "男性" );
	set("age", 42);
	set("combat_exp", 50000);
	set_skill("dodge",150);
	set_skill("throwing", 100);
	set("attitude", "friendly");
	setup();
	ob = carry_object("/d/hua/obj/dart");
	ob->set_amount(100);
	ob->wield();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob=this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	say("老板男人说道：后山常有老虎出来伤人。英雄要是能为民除害, \n或是从河里钓条金鲤鱼来, 那几个小钱也就免了!\n");
}

int accept_object(object who, object ob)
{
	if (!ob->value()) {
		if (ob->name() == "死虎") {
			command("nod");
			message_vision("$N能为民除害, 真英雄也! \n", who);
			if (who->query("marks/点菜"))
				who->delete("marks/点菜");
			return 1;
		}
		if (ob->name() == "金鲤鱼") {
			command("nod");
			message_vision("$N能钓到千年罕见的金鲤鱼, 必是有缘之人! \n", who);
			if (who->query("marks/点菜"))
				who->delete("marks/点菜");
			return 1;
		}
		else {
			write("老板男人摇摇头说：我对这些不感兴趣。\n");
			return 0;
		}
	}
	else {
		tell_object(who, "你把钱交给店小二就行了。\n");
		return 0;
	}
}
