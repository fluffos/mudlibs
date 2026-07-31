// Room: /d/fengtian/s_gate.c

inherit ROOM;

void create()
{
	set("short", "盛京南门");
	set("long", @LONG
盛京南门高三丈，宽约二丈有余，尺许厚的城门上镶满了拳
头般大小的柳钉。门洞长约四丈，大约每隔两个时辰就换官兵把
守。洞侧帖满了悬赏捉拿之类的官府布告。
LONG
	);


	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guanlu3",
  "south" : __DIR__"out_fengtian_s",
]));
	set("objects",([
		__DIR__"npc/city_guard" : 2,
]));

	set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
