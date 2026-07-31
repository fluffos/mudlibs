// Room: /d/china/junying/xiaozhen/enter_hole.c

inherit ROOM;

void create()
{
	set("short", "山洞中");
	set("long", @LONG
这是一个阴森森的大山洞，里面洞套洞、洞连洞，简直像一
个迷魂阵。石壁上渗出点点水珠，地上非常泥泞。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xianjing_entry",
  "south" : __DIR__"enter_hole",
]));

	set("objects",([
"/d/linzhi/npc/mob" : 3,
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}


