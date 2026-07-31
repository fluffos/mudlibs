// Room: /chengdu/guandao2.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "官道");
	set("long", @LONG
这是条通向成都的官道。由于此外靠近成都城，所以来往行
人不绝。游玩的客人、卖力的青年、叫卖的小贩。人声嘈杂、喧
闹不已。道路两旁的柳树随风摇摆不定。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"guandao1",
                "northwest" : __DIR__"shandao1",
	]));

	setup();
	replace_program(ROOM);
}

