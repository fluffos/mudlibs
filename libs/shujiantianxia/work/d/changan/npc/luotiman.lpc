// Write By Yanyang@SJ 2001.9.26
// NPC: /d/changan/npc/luotiman.c

inherit NPC;
void create()
{
	set_name("裸体男子", ({ "luoti nanzi","nanzi" }) );
	set("gender", "男性" );
	set("age", 26);
	set("per",30);
	set("no_quest", 1);
	set("long","这是一位正在洗澡的裸体男人。\n");

	setup();
}

void init()
{
	add_action("do_look", "look");
}

int do_look(string arg)
{
	object me=this_player();
	if ( arg == "luoti nanzi" || arg == "nanzi") {
		command("say 看什么看，没见过？");
		message_vision("裸体男子狠狠瞪了$N一眼。\n\n",me);
	}
	return 0;
}
