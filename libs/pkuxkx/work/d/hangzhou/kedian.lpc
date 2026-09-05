// Room: /hangzhou/kedian.c
// hubo 2008/4/19 
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";

void create()
{
	set("short", "客店");
	set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落脚。
LONG);
       set("no_fight", 1);
		set("valid_startroom", 1);
        set("sleep_room",1);

	set("exits", ([
		"north" : __DIR__"mingqing",
		//"east" : __DIR__"machehang",
	]));
	set("objects", ([
		__DIR__"npc/huoji2" : 1,
        ])); 
	setup();
	replace_program(ROOM);
}