// seller.c

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
        set_name("杂货贩子", ({ "zahuo fanzi" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "卖杂货的是个年轻汉子，面带微
笑，据铜山村的人说他以前也是一位江湖人。\n");
        set("combat_exp", 100);

	set("sell_all_day",1);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);

	set("vendor_goods", ({
		"/d/city/npc/obj/mabudai",
		"/d/city/npc/obj/beixin",
		"/d/city/npc/obj/toukui",
		"/d/city/npc/obj/cycle",
		"/d/city/npc/obj/surcoat",
		"/d/city/npc/obj/shield",
		"/d/city/npc/obj/huwan",
		"/d/city/npc/obj/zhitao",
		"/d/city/npc/obj/huyao",
		"/d/city/npc/obj/caoxie",
		"/d/city/npc/obj/pixue",
		"/d/city/npc/obj/shoutao",
		"/d/city/npc/obj/tieshou",
		"/d/city/npc/obj/jinsijia",
		"/d/xingxiu/obj/fire",
		"/clone/misc/chema",
	}));

        setup();
        carry_object("/clone/misc/cloth")->wear();
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
        if( !ob || environment(ob) != environment() ) return;
	if( !random(4) )
		say( "杂货贩子笑脸相迎，道：这位"
			+ RANK_D->query_respect(ob)
			+ "，要买什么？\n");
}
