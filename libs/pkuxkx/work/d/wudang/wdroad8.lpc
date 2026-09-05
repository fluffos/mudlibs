// wdroad8.c 黄土路
// by Xiang
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", 
"你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。\n"
"西边是一座高山，南面是双井子。\n"
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"wdroad7",
    //"northwest" : "/d/emei/shijie10",  //峨嵋将由成都进入，而不是武当 Zine 2010 Nov 26
		"west" : __DIR__"shanmen",
		"south" : __DIR__"cunkou"
	]));
	set("objects", ([
		__DIR__"npc/yetu" : 2 ]));
    
  
	setup();
}
