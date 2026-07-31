// qiangdao.c 强盗
// netkill /98/8/15/

inherit NPC;

void create()
{
	set_name("强盗", ({ "qiang dao", "qiang" }));
	set("nickname", "街匪路霸");
	set("long", 
		"一个满脸胡子的强盗，你最好别若他。\n");
	set("gender", "男性");
	set("age", 38);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1700);
	set("max_neili", 1700);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("score", 60000);

	set_skill("force", 80);
	set_skill("taiji-shengong", 60);
	set_skill("dodge", 80);
	set_skill("tiyunzong", 60);
	set_skill("unarmed", 80);
	set_skill("taiji-quan", 60);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("taiji-jian", 60);

	set_skill("literate", 80);

	map_skill("force", "taiji-shengong");
	
	set("chat_chance_combat", 40);
	
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			command("rob");
			break;
		case 1:
			command("hi"); 
			break;
	}
}
int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 1000) 
	{
		tell_object(who, "强盗一侧身，把路让开，说道：请这边走。\n");

		who->set_temp("dirs",1);

		return 1;
	}

	return 0;
}