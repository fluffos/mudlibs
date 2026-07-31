// Room: /d/menggu/road3
inherit ROOM;

void create()
{
  set ("short", "营帐间 ");
  set ("long", @LONG
举目所见,那都是密密麻麻的营帐,一个连着一个,蒙古部落游牧为生,
平时所住就是蒙古包,拆解方便.两边有道通向几个帐幕,分别是亲卫和大将
们的住所.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"road1",
  "north" : __DIR__"boershu",
  "south" : __DIR__"qinwei2",
]));
	set("objects", ([
		__DIR__"npc/bing"   : 4,
	]));

  set("outdoors", "menggu");
  setup();
  //replace_program(ROOM);
}
int valid_leave(object me, string dir)
{

	if ( objectp(present("menggu bing", environment(me))) && 
		dir == "south")
		return notify_fail("蒙古兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}
                                                                                                                         