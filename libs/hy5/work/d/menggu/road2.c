// Room: /d/menggu/road2
inherit ROOM;

void create()
{
  set ("short", "营帐间");
  set ("long", @LONG
举目所见,那都是密密麻麻的营帐,一个连着一个,蒙古部落游牧为生,
平时所住就是蒙古包,拆解方便.南边是亲卫营,北面的营帐前拴了几条獒犬
东面的营帐是术赤的住处.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road1",
  "east" : __DIR__"shuchi",
  "north" : __DIR__"chahe",
  "south" : __DIR__"qingwei",
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
		dir == "north")
		return notify_fail("蒙古兵拦住了你的去路。\n");
	if ( objectp(present("menggu bing", environment(me))) && 
		dir == "east")
		return notify_fail("蒙古兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}                                                                                                                                                                                                                                                                                                                                     