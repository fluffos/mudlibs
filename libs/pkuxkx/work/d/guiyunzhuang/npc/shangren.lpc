// shangren.c
// pingpang
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("商人", ({"shang ren","dealer","shang","ren"}));
	set("title",RED"江南"NOR+YEL"名商"NOR);
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 55);
	set("long",
		"他就是江南一带有名的商人，经常来太湖街来做生意。\n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		"/d/guiyunzhuang/obj/pearl",
		"/d/city/obj/goldring",
                "/d/city/obj/necklace",
	}));

	setup();
 	add_money("silver",10);
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
	say(ob->name()+"想买些什么?\n");
}
