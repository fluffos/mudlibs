// liufugate.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
	set("short", "刘府大门");
	set("long", @LONG
这里是刘府大门。刘府的主人，就是衡山派中的仅次于掌门人莫大
先生的第二号人物刘正风刘老爷子。今天兴许刘府有事吧，大门(gate)
紧闭，管家家丁也异样紧张。只有檐下的写着 "刘府" 二字的大红灯笼
中的烛火忽闪晃动才显出点活人气。
LONG);
	set("outdoors", "hengyang");
	set("exits", ([
	    "south"  : __DIR__"hengyang1",
	]));
	set("item_desc", ([
		"【大门】" : "朱红的大门紧闭着，敲敲(knock)看吧。\n"
			ZJOBACTS2+ZJMENUF(2,2,8,30)"敲门:knock"ZJSEP"推门:push gate\n",
	]));
	set("objects", ([
		__DIR__"npc/xiang" : 1,
		__DIR__"npc/mi" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_knock", "knock");
	add_action("do_push", "push");
	add_action("do_push", "open");
}

int do_knock(string arg)
{
	object me;

	me = this_player();
	message_vision("$N“咚，咚，咚，。。。”地敲着门，可里面却一点动静都没有。\n", me);
	me->set_temp("marks/liufu",1);
	return 1;
}

int do_push(string arg)
{
	int n;
	object weapon,me=this_player();
	mapping fam;

	if (! me->query_temp("marks"))
		return notify_fail("门关得牢牢的，急切打不开！\n");

	if (! arg || arg != "gate" )
		return notify_fail("这是干嘛？\n");

	message_vision(HIY "$N" HIY "走到门前，把门随便一推，居然就推开了大门！"NOR"\n",me);
	set("exits/north",__DIR__"liufudayuan");
	remove_call_out("close");
	call_out("close", 5, this_object());
	return 1;
}

void close_out()
{
	if (query("exits/north")) delete("exits/north");
}

void close(object room)
{
	message("vision","一阵咿咿呀呀门响，里面有人把大门给关上了。\n", room);
	room->delete("exits/north");
}
