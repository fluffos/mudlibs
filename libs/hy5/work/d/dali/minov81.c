//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "乌弄城");
	set("long", @LONG
此处已到大理的北疆，是乌蒙的珙部的治府，乌蒙属乌夷，居民
多居于高山上。这里正处高山之腰，北临波涛汹涌的大渡河。巷陌皆
用山石垒成，高丈余，延绵全城。此城不大，四面山上分布着些乌蒙
民居，有牧人赶着牛羊穿镇而过。
LONG
        );

	set("exits", ([
		"northdown" : __DIR__"minov82",
		"southdown" : __DIR__"minov83",
		"east" : __DIR__"minov84",
		]));

	set("objects", ([
		__DIR__"npc/wyshang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
