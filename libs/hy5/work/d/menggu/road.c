// Room: /d/menggu/road.c

inherit ROOM;

void create()
{
	set("short", "营帐间");
	set("long", @LONG
举目所见,那都是密密麻麻的营帐,一个连着一个,蒙古部落游牧为生,
平时所住就是蒙古包,拆解方便.北面的一个营帐前一杆高高的长杆上飘
着几缕白毛,此旗所在处就是大汗居处.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qingwei1.c" : 3,
]));
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yinzhang",
  "south" : __DIR__"road1",
]));

	setup();
	replace_program(ROOM);
}
