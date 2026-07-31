// Room: /d/changan/ca34.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
    这里便是长安城的西大街，四条大街交汇于此。一座巍峨高大的
钟楼耸立于前，很是有些气势。每到清晨，响亮的钟声便会伴着淡
淡雾气传向长安城的大街小巷。路口车水马龙，来往人潮不断。
LONG
);
	set("no_clean_up", 0);
	set("outdoors", 1);
	set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/city4/kedian",
  "north" : __DIR__"ca13",
  "east" : "/d/city4/center",
  "west" : "/d/city4/westgate",
//  "northwest" : __DIR__"ta1",
]));

	setup();
	replace_program(ROOM);
}
