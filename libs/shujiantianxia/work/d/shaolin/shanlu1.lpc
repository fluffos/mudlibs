// Room: /d/shaolin/shanlu1.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是少室山五乳峰下的一条小路，路旁长满的青草。黄土铺就的小路看
起来很齐整，似乎有人经常打扫。不远处就是五乳峰，山势挺拔，景秀境幽
，峰上种满了松树，随着微风拂过，传来阵阵滔声。南面是少林寺，北面可
至初祖庵。
LONG
	);
	
	set("exits", ([
		"north" : __DIR__"shanlu2",
		"south" : __DIR__"qfdian",
	]));

//	create_door("south","木门","north",DOOR_CLOSED);

	set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",440);
   set("coor/z",130);
	setup();
}
/*
void init()
{
	object me = this_player()...
}

*/