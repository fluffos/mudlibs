// Room: /u/cuer/emei/yhrkou.c

inherit ROOM;

void create()
{
	set("short", "云海");
set("outdoors","emei");
	set("long", @LONG
这里就是峨嵋著名的云海了，放眼望去，漫山遍野都
是云雾，根本就弄不清自己身在何出。在雾中隐隐约约有
一条小道通向前方，还是回去吧。
LONG
	);
	set("exits", ([ 
  "south" : __DIR__"yunhai10",
  "west" : __DIR__"yunhai"+random(3), 
  "north" : __DIR__"yhrkou",
  "east" : __DIR__"yunhai"+random(3),
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
