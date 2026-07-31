// jiashan.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIM"假山"NOR);
         set ("long",@LONG
这里属于武馆的后花园，里面奇石嶙峋，平时很少有人到这里来。花花草
草有的也已经凋谢了。左首的一块假山上有一条缝隙（feng）大的可以藏下各
把人。南面小路就是通向竹林的，路前挂了一块牌子（paizi）。
LONG
   );
	 set("outdoors","武馆");
	set("no_fight",1);
	 set("exits",([
		"north" : __DIR__"wxting",
	     "south" : __DIR__"zhulin1",
	 ]));

	 setup();
}
