// Room: /u/cuer/emei/beilang.c

inherit ROOM;

void create()
{
	set("short", "北廊");
	set("long", @LONG
这里是千佛庵北边的回廊，连接着西廊和神灯阁，成
天人来人往不绝，往西是千佛庵的北侧门，往东就可以到
神灯阁了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"beilang4",
  "east" : __DIR__"shendeng",
  "north" : __DIR__"chfang15",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
