// liuzhuang.c
#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
	set("short", "刘庄");
	set("long", @LONG
庄园的大匾上是“刘庄”两个大字。大门(gate)紧闭，里面静悄
悄的一点声音都没有。
LONG);
	set("exits", ([
	    	"east"  : __DIR__"dadao3",
		"south" : __DIR__"liuzhuang1",
		"north" : __DIR__"liuzhuang2",
	]));
	set("item_desc", ([
	   	"【大门】" : "朱红的大门紧闭着，敲敲(knock)看吧。\n"
			ZJOBACTS2+ZJMENUF(2,2,8,30)"敲门:knock\n",
	]));
	set("objects", ([
		__DIR__"npc/guanjia" : 1,
		__DIR__"npc/jiading" : 2,
	]));
	setup();
}

void init()
{
	add_action("do_knock", "knock");
}

int do_knock(string arg)
{
	object me;

	me = this_player();
	message_vision("$N“咚，咚，咚，。。。”地敲着门，可里面却一点动静都没有。\n", me);
	return 1;
}

