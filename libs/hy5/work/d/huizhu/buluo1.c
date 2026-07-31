// Room: /d/huizhu/buluo1
inherit ROOM;

void create()
{
  set ("short", "回族部落");
  set ("long", @LONG
此处三面是树林，一面斜坡直连到大草原。你现在处身在几个大帐篷
之间，东边的一个帐篷看来特别的大一点。南边有条小路通向树林之中。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhangpeng",
  "west" : __DIR__"zhangpeng1",
  "north" : __DIR__"buluo2",
  "south" : __DIR__"buluo",
]));

        set("objects", ([
                __DIR__"npc/qingbing" : 2,
                __DIR__"npc/qingbing2" : 1,
        ]));

  set("outdoors", "huizhu");
  setup();
  //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("qing bing", environment(me))) && 
		dir == "west")
		return notify_fail("清兵拦住了你的去路。\n");


	if ( objectp(present("qing bing", environment(me))) && 
		dir == "east")
		return notify_fail("清兵拦住了你的去路。\n");


	return ::valid_leave(me, dir);
}
                                                                                                                                                            