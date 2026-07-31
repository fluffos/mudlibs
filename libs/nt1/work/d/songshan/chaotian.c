// Room: /d/songshan/chaotian.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "朝天门");
	set("long", @LONG
陡见双峰中断，天然出现一个门户，疾风从断绝处吹出，云雾
随风扑面而至，这里就是朝天门了。
LONG );
	set("exits", ([
		"northup"   : __DIR__"shandao6",
		"southdown" : __DIR__"shandao5",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

