// Room: /d/fuzhou/fzroad8.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "闽江");
	set("long", @LONG
自延福门放江而下，两岸青山夹翠，游鱼泛波，小舟穿行险
滩之中，耳畔哗哗水响，自黄岩到福州一百六十里水路，朝发夕
至。
LONG );
	set("exits", ([
		"northwest" : __DIR__"yanping",
		"southeast" : __DIR__"fzroad9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

