// Room: /d/jindezheng/center.c

inherit ROOM;

void create()
{
	set("short", "镇中心");
	set("long", @LONG
这里是镇中心,街道至此向南拐,此处来往的人就更多了,叫卖的商 
贩,提着花蓝的卖花女,等着人雇的脚夫......喧闹声声. 
LONG
	);
	set("no_clean_up", 0);
	set("valid_startroom", "1");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"street1",
  "south" : __DIR__"street2",
]));
	set("outdoors", "/d/jindezheng");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/renfanzi.c" : 1,
  __DIR__"npc/kid.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
