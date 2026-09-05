#include "setdizi.h"

void create()
{
	setcreate(140);
	add("long", "怒气冲冲的瞪着你。\n");
	add("inquiry", ([
		"here" : "掌门人得到消息说玄铁令在洛阳出现，派我们来此。",
		"rumors" : "掌门人得到消息说玄铁令在洛阳出现，今日竟真的看到了。",
		"玄铁令" : "谢烟客当年发下毒誓，不论从谁手中接过此令，都可依其所求办一件事！",
		"谢烟客" : "谢烟客的武功深不可测，尤其是一路掌法更是出神入化。",
	]));
	set("chat_chance", 1);
	set("chat_msg", ({
		(: command("sigh") :),
	}));
	setfamily(7);
	setup();
	setequip();
	call_out("dest", 60);
}

void init()
{
	setinit();
	::init();
}

void attempt_apprentice(object ob)
{
	setapp(ob);
}

void dest()
{
	object ob = this_object();
	if(!ob)
		return;
	message_vision("$N见无机可乘，离开了这里。\n", ob);
	destruct(ob);
}