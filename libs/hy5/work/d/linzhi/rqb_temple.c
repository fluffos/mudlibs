// Room: /d/linzhi/rqb_temple.c

inherit ROOM;

void create()
{
	set("short", "仁钦崩寺");
	set("long", @LONG
仁钦崩寺是墨脱最大的寺院，位于墨脱村南则玛拉山上。
建寺时间是在门巴东迁后不久，距今约8代人。据传是由甘布
寺中的活佛甘布建筑的，最初是一座有12面墙和东西南北四
门的石木结构三层建筑，内有镀金铜佛像多座。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lin28",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/monk3" : 1,
  __DIR__"npc/monk4" : 1,
  __DIR__"npc/lama2" : 1,
__DIR__"npc/xintu2" : 2,  	
]));
	setup();
	replace_program(ROOM);
}
