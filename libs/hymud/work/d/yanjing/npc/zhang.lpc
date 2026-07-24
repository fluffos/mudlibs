// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("张铁匠", ({ "zhang tiejiang", "zhang", "tiejiang" }));
	set("title", "燕京铁匠铺");
	set("shen_type", 1);

	set("str", 40);
	set("gender", "男性");
	set("age", 55);
	set("combat_exp", 5800);
	set("attitude", "friendly");

	set("rank_info/respect", "伙计");
	set("vendor_goods", ({
               __DIR__"obj/hammer",
                __DIR__"obj/sword",
                __DIR__"obj/blade",
                __DIR__"obj/whip",
                __DIR__"obj/banfu",
                __DIR__"obj/changdao",
                __DIR__"obj/gangdao",
	}));

	setup();
   carry_object(__DIR__"obj/changpao")->wear();
}

void init()
{	
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

