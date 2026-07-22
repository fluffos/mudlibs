// Room: /d/yandang/wulonggu.c

inherit ROOM;

void create()
{
	set("short", "卧龙谷");
	set("long", @LONG
卧龙谷内高爽清幽,奇景罗列,飞尘不到,恍若桃源.此谷位于小龙湫
之上,因而名为卧龙.谷内有湖,名龙口湖,湖水从崖端飞流直下,形成瀑
布,常年不断.从此向下就是小龙湫了.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"tianzhu.c",
  "westdown" : __DIR__"xiaolongq.c",
]));

	setup();
	replace_program(ROOM);
}
