// Room: /d/city/xiaozhou2.c 华山小舟
// Date: netkill /98/8/18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小舟");
	set("long", @LONG
一叶小舟，最多也就能载两三个人。一名年轻的艄公手持
长竹篙，缓缓的驾着船。
LONG
	);

	setup();
}

void init()

{	object me=this_player();
	me->delete_temp("ok");me->delete_temp("ok1");
	tell_object(me, CYN "\n\n\n船在大河上一路缓缓而行。两岸的风景尽收眼底...\n\n\n" NOR ) ;
	call_out("goto",10, me);
}
void goto(object me)
{   
	int i;
	i=(int)me->query_temp("exit");
	find_object(__DIR__"xiaozhou2")->delete("yell_trigger");
	if (i<20) {
		me->move (__DIR__"yunhe3");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	if (i>30) {
		me->move (__DIR__"yunhe5");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	}