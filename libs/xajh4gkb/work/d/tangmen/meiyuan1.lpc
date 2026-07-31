// Room: /d/tangmen/meiyuan1.c
// xws 1998/11/05

inherit ROOM;

void create()
{
	set("short", "梅园");
	set("long", @LONG
	这是唐门中的一大片梅林，每逢满园梅花绽放，幽香袭人，令人觉得神清气
爽。堪称唐门一大美景。
LONG
	);
	
set("outdoors", "tangmen");
	set("exits", ([
		
		"south" : __DIR__"xiouxishi",
		"east" : __DIR__"meiyuan2",
	]));

	setup();
	replace_program(ROOM);
}

