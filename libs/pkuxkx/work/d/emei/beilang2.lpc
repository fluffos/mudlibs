// Room: /u/cuer/emei/beilang2.c

inherit ROOM;

void create()
{
	set("short", "北廊");
	set("long", @LONG
这里是千佛庵北边的回廊，是东廊和北廊的交汇处，
成天人来人往不绝，往东是千佛庵的膳房，往西就可以到
神灯阁了。      
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"dlang1",
  "west" : __DIR__"beilang1",
  "east" : __DIR__"shanfang",
  "north" : __DIR__"chfang13",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
