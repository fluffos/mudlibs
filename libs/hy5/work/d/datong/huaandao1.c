// Room: /open/dt/huaandao1.c

inherit ROOM;

void create()
{
	set("short", "华安道");
	set("long", @LONG
这是一条比较偏避的小道，路两旁种着一排白杨树，高大的
白杨使这条路显得更加的狭窄，给人一种幽静深远的感觉，路上
行人行色匆匆，好像都有很多心事的样子。西边不远处就是坦皇
路，北面是一家绸缎庄，南面是和记钱庄。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tanhuanglu1",
  "east" : __DIR__"huaandao2",
  "south" : __DIR__"hejiqianzhuang",
  "north" : __DIR__"chouduanzhuang",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
