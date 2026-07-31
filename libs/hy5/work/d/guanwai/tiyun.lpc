// Room: /d/guanwai/tiyun.c

inherit ROOM;

void create()
{
	set("short", "梯云峰");
	set("long", @LONG
玉柱峰北，有一山峰，峰脊出梯河瀑布，远望如腾白如云，纵列如梯，
故名梯云峰。
LONG
	);
	set("outdoors", "guanwai");
	set("exits", ([ /* sizeof() == 3 */
//  "north" : "/u/skyzxm/huayuan",
  "south" : __DIR__"yuzhu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
