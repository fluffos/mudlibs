// Room: /d/sandboy/yuanzi.c

inherit ROOM;

void create()
{
	set("short", "小院子");
	set("long", @LONG
一道高高的门槛把院子和堂屋隔了开来.东西两面各有两间小茅屋,从
东面的屋子中传来饭菜的香味,西面的茅屋中不时传出两声猪的啼叫.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cook",
  "west" : __DIR__"pigroom",
  "south" : __DIR__"home",
  "north" : __DIR__"room1",
]));

	setup();
	replace_program(ROOM);
}
