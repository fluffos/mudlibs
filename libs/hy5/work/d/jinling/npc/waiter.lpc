
// waiter.c

inherit NPC;
inherit F_DEALER;

int on_service = 0;

void create()
{
	set_name("店小二", ({ "waiter", "snow_inn_waiter" }) );

	set("age", 21);
	set("long",
		"一个约二十出头的年轻小伙计，正忙进忙出招呼客人，你可以用\n"
		"list 看可以点什麽菜，用 buy 跟店小二点菜。\n");
	set("chat_chance", 1);
	set("chat_msg", ({
		"店小二闲著无聊，哼起小曲儿来。\n",
		"店小二一屁股做在门槛上，发起呆来。\n",
		"店小二说道：客倌今天怎么有空，最近可有新鲜事能说来听听吗？\n",
	}));
	
		set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/jiudai",
		__DIR__"obj/shuihu",

		__DIR__"obj/songbing",
		__DIR__"obj/cai",
						
	}));
	
	
	setup();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


int accept_fight(object ob)
{
//	do_chat("店小二扮了个鬼脸，说道：客倌要打架的话，小的我可不是对手。\n");
	say("店小二扮了个鬼脸，说道：客倌要打架的话，小的我可不是对手。\n");
	return 0;
}


