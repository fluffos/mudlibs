// /d/yazhang/xiaolu2.c
// Room in 牙帐
// modify by yang

inherit ROOM;

void create()
{
	set("short", "草原小路");
	set("long", @LONG
这里是一条去大草原的必经之路，小路两旁杂草众多，路上行人也
很少。
LONG 
        );
	set("exits", ([
		"west" : __DIR__"xiaolu2-1",
		"east" : __DIR__"xiaolu2-3",
	]));
	set("objects",(["/clone/npc/man":1,]));	
	
 	set("outdoors", "yazhang");
	setup();
	replace_program(ROOM);
}

