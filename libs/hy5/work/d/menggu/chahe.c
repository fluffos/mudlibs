// Room: /d/menggu/chahe.c

inherit ROOM;

void create()
{
	set("short", "察合台营帐");
	set("long", @LONG
察合台是铁木真的二子,生性残忍好杀,蒙古人性喜打猎,酋长贵人无
不畜养猎犬猎鹰.察合台尤其爱狗,不但在营帐外面拴了獒犬,营帐中还有
獒犬的笼子.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/menggudog.c" : 1,
  __DIR__"npc/chahetai.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}
