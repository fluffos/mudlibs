// Room: /u/cuer/emei/beilang1.c

inherit ROOM;

void create()
{
	set("short", "北廊");
	set("long", @LONG
这里是千佛庵北边的回廊，连接着东廊和神灯阁，成
天人来人往不绝，往东是千佛庵的膳房，往西就可以到神
灯阁了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shendeng",
  "east" : __DIR__"beilang2",
  "north" : __DIR__"chfang14",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
