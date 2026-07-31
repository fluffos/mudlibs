// Room: /d/jindezheng/street2.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
这是一条青石板铺成的街道,全国各地的瓷器商人都到此处来批货, 
偶然在人群中,你还能见到金发碧眼的老外.街道的西面有一家茶馆,来 
来往往的人还挺多. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tea-room",
  "north" : __DIR__"center",
  "south" : __DIR__"street3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dadao.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
