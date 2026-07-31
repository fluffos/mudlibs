// void.c (re-created after Elon screwed it up on 07-24-95)

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","最後乐园");
	set("long",@LONG	
这里就是传说中的 VOID -- 大神和巫师的最後乐园. 你看到四周一片
白茫茫的, 不一会从虚无中冒出一只企鹅, 递给你一罐「可口可乐」(tm), 
然後站在一旁很邪恶地笑著. 又过了一会, 一只北极熊走了过来, 一掌拍扁
了那只企鹅并从你手上抢走那瓶可乐, 大笑三声後就从你眼前消失了.
你摇摇头, 这种地方还是不要待太久的好.
LONG
	);
	setup();
}

void init()
{
	call_out("greeting", 5, this_player());
}

void greeting(object who)
{
	object ob;

	if( environment(who)!=this_object() ) return;

	// It seems we'll stay here for a while ...
	message_vision(HIY"嘿嘿 ..."HIR"$N"HIY"因为某种原因来到这个乐园了\n"NOR,who);
	message_vision(HIB"系统给了"HIR"$N"HIB"一瓶可乐当做安慰奖。\n"NOR,who);
	ob = new("/u/t/tnn/obj/cola");
	ob->move(who);

	return;
}
