
#include <ansi.h>
inherit ROOM;
int do_zhong(string arg);

void create ()
{
  set ("short","菜园");
  set ("long", @LONG
这里是净念禅院的菜园。这里种了很多蔬菜水果，有白菜、黄瓜、
土豆、萝卜等。有几名僧人正在那里辛勤地干活，有的在锄草，有的在
浇水，有的在施肥。静念禅院的僧人就是在普通的劳动中来逐步提高自
己的武学修为。
LONG);

  set("exits", ([ 
	  "south":__DIR__"caodi4",
     ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_zhong","zhong");
}

int do_zhong(string arg)
{
	object me;
	me=this_player();
	if(!arg||arg!="菜") return notify_fail("你想种什么?\n");
	if(!me->query_temp("budian_job/2"))
		return notify_fail("你在这里忙什么呢?\n");
	if(me->is_busy()) return notify_fail("你正忙着呢!\n");
	if((int)me->query("sen",1)<=5) return notify_fail("你太累了,已经不能再干活了!\n");
	if(me->query_temp("budian_job/ok"))
		return notify_fail("好了,你可以回去交工了!\n");
	if(me->query_temp("budian_job/count"))
		me->add_temp("budian_job/count",1+random(1));
	else me->set_temp("budian_job/count",1);
	if((int)me->query_temp("budian_job/count",1)>=10+random(5))
		me->set_temp("budian_job/ok",1);
	me->receive_damage("sen",10+random(2));
	call_out("return_job",2,me);me->start_busy(1);
	message_vision("$N认真地种起菜来.\n",me);
	return 1;
}

void return_job(object me)
{
	message_vision("$N擦擦头上的汗,觉得自己又为佛家圣地做了件好事.\n",me);

	return;
}