// Room: /u/cass/hg/neishi.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
帐子低垂，看不到里面有什么。床的旁边，放有一个衣柜。西首摆有几个木箱
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dafotang",
]));
	set("objects", ([
		__DIR__"npc/real-queen":1,
	]));

	setup();
	replace_program(ROOM);
}
