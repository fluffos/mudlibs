// Room: /d/sandboy/home.c

inherit ROOM;

void create()
{
	set("short", "民房");
	set("long", @LONG
眼前是一座民房,一圈石头垒起的围墙把屋子围了起来,仔细看时,你能
发现许多青草就在屋顶,围墙上长了起来.围墙的下沿有一圈墨绿色的苔藓.
两扇木板门半掩着.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuanzi",
  "south" : __DIR__"ground",
]));

	setup();
	replace_program(ROOM);
}
