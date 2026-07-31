// Room: /open/dt/huaandao2.c

inherit ROOM;

void create()
{
	set("short", "华安道");
	set("long", @LONG
这是一条比较偏避的小道，路两旁种着一排白杨树，高大的
白杨使这条路显得更加的狭窄，给人一种幽静深远的感觉，路上
行人行色匆匆，好像都有很多心事的样子。北面是巡捕头领李洪
三的家，南面是一家当铺。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huaandao1",
  "east" : __DIR__"huaandao3",
  "south" : __DIR__"dangpu",
  "north" : __DIR__"lihongsanjia",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
