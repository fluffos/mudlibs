 // zhaitang.c 斋堂

#include <ansi.h>
inherit ROOM;


void create()
{
        set("short",HIG"斋堂"NOR);
        set("long",@LONG 
这里整整齐齐地码放着几溜长条桌子和凳子，一阵阵食物的香气传来，原
来这里是大轮寺的斋堂，现在不是吃饭的时间，大堂里空荡荡的，只有几个杂
役喇嘛有的在收拾桌子，有的在扫地，一切看来井井有条。
LONG);
	set("no_fight", 1);
        set("no_sleep_room",1);
        set("exits",([
                "northwest" : __DIR__"rimulundian",
                "north" : __DIR__"chufang"
        ]));
        set("objects", ([__DIR__"npc/zayilama1" : 1,]));
        setup(); 
}

int valid_leave(object me, string dir)
{
	if ((dir == "northwest")
	 && present("suyou cha", this_player())
	 && objectp(present("zayi lama", environment(me))) )
	switch ( random(2)) {
		case 0:
			message_vision("杂役喇嘛伸手拦住了$N：“别着急，还是先把东西吃完了再走吧。”", me);
			return notify_fail("\n");
			break;
		case 1:
			message_vision("杂役喇嘛拦住$N道：“不准连吃带拿，还有别人没吃饭呢。”", me);
			return notify_fail("\n");
			break;
	}
	return ::valid_leave(me, dir);
}
