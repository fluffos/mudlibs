// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/northroad7.c

inherit ROOM;

void create()
{
        set("short", "土路");
        set("long", @LONG
这是一条黄土飞扬的路，不算太宽，路上几乎没有行人，给人一种落寞的
感觉，路边零零散散的分布着几片小田地，偶然也能看得见一些炊烟。四周一
片的荒寂。
LONG
	);
	set("outdoors", "长安");

        set("exits", ([
		"northeast"  : __DIR__"northroad8",
		"southup"  : "/d/group/entry/canroad6",
	]));

	set("objects",([
		__DIR__"npc/keshang" : 1,
	]));

	setup();
}
