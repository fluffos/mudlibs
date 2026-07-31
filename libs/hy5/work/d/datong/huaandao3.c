// Room: /open/dt/huaandao3.c

inherit ROOM;

void create()
{
	set("short", "华安道");
	set("long", @LONG
这是一条比较偏避的小道，路两旁种着一排白杨树，高大的
白杨使这条路显得更加的狭窄，给人一种幽静深远的感觉，路上
行人行色匆匆，好像都有很多心事的样子。南面是一家豆腐坊，
东面是一座古老的祠堂。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"huaandao2",
  "east" : __DIR__"kongzici",
  "south" : __DIR__"doufufang",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
