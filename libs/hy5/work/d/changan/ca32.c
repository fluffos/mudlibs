// Room: /d/changan/ca32.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "大官道");
	set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向武
功镇，往西则直达长安城。
LONG
);
	set("no_clean_up", 0);
	set("outdoors", "changan");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dongmen",
  "east" : __DIR__"ca33",
           "south" : "/d/quanzhen/ximen",
]));

	setup();
	replace_program(ROOM);
}
