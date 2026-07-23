inherit NPC;
inherit F_VENDOR;

string query_save_file() {return DATA_DIR+"npc/吴四郎";}
void create()
{
	set_name("吴四郎", ({ "wusi", "wusi", "wusi" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位吴四郎正笑咪咪地忙著。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/caoxie",

	}));
set("chat_chance",5);
set("chat_msg",({
"吴四郎叫喊:草鞋,新打的草鞋,谁要买草鞋?\n",
"吴四郎喃喃自语:看来今天的草鞋又卖不出去了.\n",
(:random_move:),
}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	//carry_object("/obj/std/armor/pijia")->wear();
	//carry_object("/obj/std/weapon/wandao")->wield();
}
void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


