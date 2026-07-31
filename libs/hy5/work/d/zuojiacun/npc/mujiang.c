// mujiang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("李木匠", ({ "zhang mujiang", "mujiang", "zhang" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 43);
	set("long", "他是个手艺高超的木匠。\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");

	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
		"/clone/weapon/club",
	}));
	setup();
	setup();
	carry_object("/clone/misc/cloth")->wear();
//	carry_object("/d/city/npc/obj/cloth/male-shoe")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

