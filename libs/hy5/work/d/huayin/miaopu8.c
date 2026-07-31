// Room: /d/huayin/miaopu8.c

inherit __DIR__"yao_tian";

void create()
{
	set("short", "药田");
	set("long", @LONG
这里是一大片肥沃的田地，奇怪的是这里没有一丝农作的痕
迹。据说这里是专门用来培植草药的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"miaopu9",
  "east" : __DIR__"miaopu7",
  "north" : __DIR__"miaopu5",
]));

	set("outdoors","huayin");
	setup();
}
