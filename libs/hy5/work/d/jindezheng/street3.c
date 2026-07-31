// Room: /d/jindezheng/street3.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
这条街道从北向南,两端的店铺林立,大多是搞瓷器活的,只有你东 
面的这家是个例外,这是一家古董店,从此向南,可就出了镇了. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"gudong-shop",
  "south" : __DIR__"shulin1",
  "north" : __DIR__"street2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qingfuren.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
