

inherit NPC;

void create()
{
	set_name("亲兵", ({ "qin bing", "bing" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "这是吕文德豢养的亲兵,平时欺压百姓,作威作福还可以,一到战场上就象不堪一击了。\n");
	set("attitude", "peaceful");
	set("str", 47);
	set("dex", 18);
	set("combat_exp", 2000);
	set("shen_type", 1);
	set_skill("unarmed", 40);
	set_skill("parry", 30);
	set_skill("blade", 20);
	set_skill("force", 100);
//	if (random(2) == 1) {
//		set("chat_chance", 10);
//		set("chat_msg", ({
//			(: random_move :),
//		}));
//	}
        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
        "亲兵喝道：大胆刁民,竟敢闯吕大人的府第,你是活得不耐烦了!\n"
        
	}));
	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/junfu")->wear();
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

	command("say 大爷我忙着吃酒,没空理你.\n");
        return 0;
}
