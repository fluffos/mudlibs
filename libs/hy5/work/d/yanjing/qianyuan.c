// Room: /d/yanjing/qianyuan.c

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
一排白玉石石阶从大门直通向北面的厅堂,两边是扶疏花木,淡淡的
清香飘浮在空气中,几株梅花的横枝别致地伸到石阶旁,花木深处的积雪
尚未溶化,点点的泛着银光.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"qianting",
  "south" : __DIR__"wangfu",
]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
