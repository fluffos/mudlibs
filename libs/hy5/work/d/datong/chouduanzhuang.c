// Room: /open/dt/chouduanzhuang.c

inherit ROOM;

void create()
{
	set("short", "绸缎庄");
	set("long", @LONG
店内的墙壁上挂满了五颜六色的布匹和成衣，甚至连柜台上
也被成卷的布堆满了。两名年轻女子一面抚摸着一匹江南绵缎，
一面和店主人讨价还价。店主人看见你进来，连忙撇下两名女子
走上前来和你打招呼。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huaandao1",
]));

	setup();
	replace_program(ROOM);
}
