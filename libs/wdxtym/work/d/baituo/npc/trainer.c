//trainer.c

inherit NPC;

void greeting(object);
void init();
void create()
{
	set_name("教练", ({ "trainer"}) );
	set("gender", "男性" );
	set("age", 25);
	set("long", "这是个和蔼可亲的教练。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("combat_exp", 30000);
	set("score", 20000);

	set_skill("force", 60);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 60);
	set_skill("staff",60);

	setup();
}

void init()
{
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (check_family(ob, "欧阳世家"))
	{
		if (ob->query("qi") < 60)
			message_vision("教练对着$N笑道：练功累吧？没关系，苦尽甜来嘛。\n",ob);
		else
			message_vision("教练对着$N夸道：继续练功，加油啊！\n",ob);
	}
}

void attempt_apprentice(object ob)
{
	if (ob->query("born_family") != "欧阳世家")
	{
		command("shake");
		command("say 哪里来的家伙居然敢来白驼山添乱？");
		return;
	}

	command("say 呵呵，我不收徒，去找欧阳庄主吧。\n");
	return;
}

int accept_fight(object ob)
{
	if (ob->query("born_family") != "欧阳世家")
	{
		command("shake");
		command("say 哪里来的家伙居然敢来白驼山添乱？");
		return 0;
	}

	command("say 不要和我比划，你可以和里面的木人练练功。");
	return 1;
}
