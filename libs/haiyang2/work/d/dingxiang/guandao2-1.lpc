// /d/yazhang/guandao2.c
// Room in 牙帐
// modify by yang

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
你走在一条官道上，几米宽的大道可并行三四辆马车而不显拥挤。
路上三俩成群的行人都是往来贩盐的生意人。偶尔有官兵骑马飞驰而过。
LONG 
        );
	set("exits", ([
		"north" : __DIR__"guandao2",
		"south" : __DIR__"guandao2-2",
	]));
	set("objects",(["/clone/npc/man":2,]));	
	
 	set("outdoors", "yazhang");
	setup();
	replace_program(ROOM);
}

