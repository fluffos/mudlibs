// 水老板
// pingpang 97/11/7

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("水老板", ({ "shui laoban", "shui", "laoban" }));
	set("title", "太湖酒家老板");
	set("shen_type", 1);

	set("str", 28);
	set("gender", "男性");
	set("age", 55);
	set("long",
		"水老板久居太湖街，据说他年轻时就在此开了如今的太湖酒家.\n");
	set("combat_exp", 8000);
	set("attitude", "friendly");
	set("inquiry", ([
                "归云庄" : "过了前面的太湖桥就是了。\n",
 	]));
	set("vendor_goods", ({
		"/d/city/npc/obj/hdjiudai",
		"/d/taohuadao/obj/feiya",
                "/d/city/obj/tofu",
		"/d/taohuadao/obj/xuntianji",
	}));

	setup();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("水老板笑眯眯地说道：客人来坐。\n");
		break;
	case 1 :
		say("水老板说道：可口的，你要买什么？\n");
		break;
	}
}
