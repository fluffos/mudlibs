// Room: /d/huashan/npc/baichi.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "百尺峡");
	set("long", @LONG
走过千尺幢，前面又见另一要命的百尺峡，百尺峡不似千尺幢般险峻，但
亦十分陡峭，岩壁两侧设有铁索以作扶拦。
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"qianchi",
		"eastup" : __DIR__"laojun",
	]));
	set("objects", ([
		__DIR__"npc/monkey" : 1,
		NPC_D("tiao-fu") : 1,
	]));
	set("outdoors", "华山" );
	setup();
}