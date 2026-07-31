// armorboss.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("防具店老板", ({ "armor boss", "boss" }) );
	set("gender", "男性" );
	set("age", 40);

	set("long", "防具店老板个脸上有一道伤疤中年人，一笑起来份外诡异。\n");

	set("combat_exp", 30000);
	set("attitude", "friendly");
	set("max_kee",1000);
	set("max_force",1000);
	set("force_factor",20);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 120);

	set("sell_all_day",1);

	set("vendor_goods", ({
		__DIR__"obj/armor",
		__DIR__"obj/hands",
		__DIR__"obj/head",
		__DIR__"obj/waist",
		__DIR__"obj/wrists",
	}));

	setup();
	add_money("silver", 5);
	carry_object(__DIR__"obj/armor")->wear();
	carry_object(__DIR__"obj/hands")->wear();
 //       carry_object(WEAPON_DIR"sword")->wield();
}

void init()
{
	object ob;
	::init();
		add_action("do_buy", "buy");
	add_action("do_list", "list");
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() )
		return;

	switch( random(4) )
	{
		case 0:
			command(sprintf("say 这位%s挑一件称手的兵器吧。", RANK_D->query_respect(ob)));
			break;
		case 1:
			command("say 本店全天营业，敬请随时光临。");
			break;
	}
}
