// keeper.c

inherit NPC;

void create()
{
	set_name("庙祝", ({ "miao zhu" }) );
	set("gender", "男性" );
	set("age", 84);
        set("long","这是一位满脸沧桑的老人，看著他佝偻的身
影，你忽然觉得心情沈重了下来。\n");
	set("combat_exp", 1);
	set("attitude", "friendly");
	setup();
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
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "庙祝说道：这位" + RANK_D->query_respect(ob)
		+ "，捐点香火钱积点阴德吧。\n");
}

int accept_object(object who, object ob)
{
	int val;

	if(ob->value()< 1000)
		return notify_fail("庙祝不收物品的捐献。\n");

	if( (val = ob->value()) >= 1000 )
	say( "庙祝说道：多谢这位" + RANK_D->query_respect(who)
		+ "，神明一定会保佑你的。\n");
        return 1;
}
