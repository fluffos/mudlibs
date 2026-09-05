// Room: /u/cuer/emei/xilang5.c

inherit ROOM;

void create()
{
	set("short", "北廊");
	set("long", @LONG
这里是千佛庵北边的回廊，是西廊和北廊的交汇处，
成天人来人往不绝，往西是千佛庵的北侧门，往东就可以
到神灯阁了。				
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"beicemen",
  "south" : __DIR__"xilang4",
  "east" : __DIR__"beilang3",
  "north" : __DIR__"chfang16",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
