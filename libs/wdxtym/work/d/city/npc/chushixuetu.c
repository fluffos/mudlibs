// zhu.c 朱熹

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

string ask_job();
int do_answer();

void create()
{
	set_name("厨师学徒", ({ "chushi xuetu" }));
	set("long", "巫师刚刚招来不久的一名学徒。\n");
	set("gender", "男性");
	set("age", 65);
	set("no_get", 1);
	set("teacher",1);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	set("inquiry", ([
	    "工作" : (: ask_job :),
	]));
	setup();

	set("chat_chance", 1);
}

string ask_job()
{
	object me;
	object *obs;

	me = this_player();
	if (me->query("afk/file")=="chaocai")
		return "菜炒好了？";

	if (me->query_temp("pending/afk")||me->query("afk"))
		return "你正忙着呢！";

	if (me->query("jing") < 50) 
		return "你还是休息会儿吧，小心把身子累垮了！";

	if (! interactive(me))
		return "...";

	me->delete("afk");
	me->set("afk/file","chaocai");
	me->set("afk/room",environment(me));
	return "好吧，你就帮我炒菜吧！菜在这儿，灶台在那边。";
}