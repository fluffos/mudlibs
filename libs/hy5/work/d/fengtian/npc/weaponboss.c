// weaponboss.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("兵器铺老板", ({ "weapon boss", "boss" }) );
	set("gender", "男性" );
	set("age", 40);

	set("long", "兵器铺老板个脸上有一道伤疤中年人，
一笑起来份外诡异。\n");

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

	set("inquiry", ([
		"兵器坊" : "本店专卖各种长短兵器", 
]) );
	set("attitude", "friendly");
        set("vendor_goods",({
                   "/d/city/obj/changjian",
                   "/d/city/obj/hammer",
                   "/d/city2/obj/tudao",
               		"/d/city/obj/dagger",
                  "/d/xingxiu/obj/tiegun",
                  "/d/city/obj/gangdao",
        //__DIR__"obj/armor",
        }));


	setup();
        carry_object("/clone/weapon/gangjian")->wield();
}

void init()
{
	object ob;
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
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
