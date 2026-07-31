// mafu.c 马夫
#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("马夫", ({ "ma fu", "mafu", "ma"}));
	set("age", 32);
	set("gender", "男性");
	set("long", "这是马厩驯马和小伙计，平时打理照料马匹。\n");
	set("attitude", "friendly");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 400000);
	set("shen_type", 1);
	set("icon", "05009");
	set("chat_chance",1);
	
	setup();
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && ! is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment())
		return;

	say("马夫点头哈腰地说道：这位客官，您好，打算去哪儿啊？\n");
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id"))
	{
		message_vision("$N对$n，你想去(goto)哪儿？先告诉小的再付钱。\n",
			       this_object(), who);
		return 0;
	}

	return 0;
}
