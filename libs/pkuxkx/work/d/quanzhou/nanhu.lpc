// Room: /d/quanzhou/nanhu.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖");
	set("long", @LONG
这里是嘉兴南湖。节近中秋，荷叶渐残，莲肉饱实。一阵轻柔
婉转的歌声，飘在烟水蒙蒙的湖面上。湖边一个道姑在一排柳树下悄
立已久。
LONG
	);
	set("outdoors", "quanzhou");
	set("objects", ([ /* sizeof() == 1 */
		  __DIR__"npc/limochou" : 1,
		]));
	set("exits", ([ /* sizeof() == 5 */
		  "north" : __DIR__"qianzhuang",
		  "northdown" : __DIR__"wuminggudi",
		  "west" : __DIR__"jiaxing",
		  "south" : __DIR__"tieqiang",
		  "southeast" : __DIR__"nanhu1",
                  "east" : __DIR__"jiang",
		]));
    set("couldfish",1);
	set("main_dir", __DIR__"");
	set("no_clean_up", 1);
	setup();
	replace_program(ROOM);
}

