// Room: /d/zuojiacun/miao.c

inherit ROOM;

void create()
{
	set("short", "龙王庙");
	set("long", @LONG
这是一个小龙王庙，村里的人民出海前都要到这里来祭拜。
香案上摆放着一个香炉，不断飘出袅袅的轻烟。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu9",
]));
  	set("objects",([
	"/clone/npc/man" : 2,
]));
	set("valid_startroom",1);
	setup();
	replace_program(ROOM);
}
