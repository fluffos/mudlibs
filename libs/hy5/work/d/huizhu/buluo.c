// Room: /d/huizhu/buluo.c

inherit ROOM;

void create()
{
	set("short", "回族部落");
	set("long", @LONG
此处三面是树林，一面的斜坡下，是一望无边的草原，远处高山在云
雾中闪现，各种鸟儿在枝头鸣叫。斜坡的这边是老大一片空地，几个帐篷
就扎在空地的中央。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"buluo1",
  "east" : __DIR__"shulin",
  "west" : __DIR__"shulin1",
  "south" : __DIR__"shulin2",
]));

	setup();
	replace_program(ROOM);
}
