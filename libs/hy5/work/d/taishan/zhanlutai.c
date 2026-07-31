// Room: /d/taishan/zhanlutai.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "瞻鲁台");
	set("long", @LONG
爱身崖上有巨石突兀，高约丈许，石旁大书“瞻鲁台”，俗称幡杆
石。传孔子曾登此瞻鲁都曲阜。
LONG );
	set("exits", ([
		"down" : __DIR__"aishen",
	]));
	set("objects", ([
		__DIR__"npc/houjian" : random(2)+1,
		__DIR__"npc/daopao" : random(2)+1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 760);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
