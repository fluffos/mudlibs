// File		: stonew1.c
// Created By	: iszt@pkuxkx, 2006-08-16

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条平整宽阔的石板路，路边就是积雪，稀稀疏疏的长着几根草茎。西南方
向是内城的角门，几个腰间悬剑的人匆匆向北走去。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"east" : __DIR__"datingw",
		"southeast" : __DIR__"bingwest5",
		"southwest" : __DIR__"jiaomenw",
		"north" : __DIR__"stonew2",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}