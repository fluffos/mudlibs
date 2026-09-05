// wdroad8.c 黄土路
// by Xiang
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "山谷口");
	set("long", @LONG
这是一个山谷口，向西隐约通向一个山谷，山谷里面黑压压的，
什么都看不清，向东通向一条乡间小路。
LONG	);
  
	set("exits", ([
		"eastdown" : __DIR__"vroad1",
//		"westup" : __DIR__"jueqingroad1",
	]));
	set("objects", ([
		"/clone/npc/gongsun":1,
	]));
  set("outdoors", "wudang");
	
	setup();
}
