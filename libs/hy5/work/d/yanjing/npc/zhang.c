// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("ÕÅÌú½³", ({ "zhang tiejiang", "zhang", "tiejiang" }));
	set("title", "Ñà¾©Ìú½³ÆÌ");
	set("shen_type", 1);

	set("str", 40);
	set("gender", "ÄÐÐÔ");
	set("age", 55);
	set("combat_exp", 5800);
	set("attitude", "friendly");

	set("rank_info/respect", "»ï¼Æ");
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

