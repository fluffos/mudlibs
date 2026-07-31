// Room: /d/jindezheng/street1.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
这是一条石板铺成的街道,街道挺宽敞,来来往往的人群,商吏,脚夫, 
差役,不绝于缕,时常有拉了满车陶瓷的骡马车奔驰而过,街道北面是一家 
药铺,信誉挺好. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/maolu.c" : 1,
  __DIR__"npc/silang.c" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"center",
  "east" : __DIR__"jindezhen",
  "north" : __DIR__"doctor-room",
]));
	set("outdoors", "/d/jindezheng");

	setup();
	replace_program(ROOM);
}
