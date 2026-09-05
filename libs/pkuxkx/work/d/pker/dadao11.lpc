inherit ROOM;
void create()
{
        set("short", "大道");
        set("long", @LONG
一条宽阔的大道伸向远方，两边是都是杀手帮的产业，可见其势力之盛
难怪会成为近年来武林中最兴旺的帮派
LONG
        );
        set("outdoors", "pker");
        set("exits", ([
                "west" : __DIR__"guangchang",
                "east" : __DIR__"dadao12",
                "north":__DIR__"bathroom1",
                "south":__DIR__"bathroom2",
                ]));
          set("objects", ([
         
           ]));
        setup();
       //replace_program(ROOM);
}



int valid_leave(object me, string dir)
{        

	if (me->query("gender")=="男性" && dir == "south")
	return notify_fail("小子，那边是女浴室，想偷窥啊!?\n");

	if ( me->query("gender")=="女性"&& dir == "north")
	return notify_fail("嘿，那边可是男浴室啊，你进去干什么？唉....\n");


	return ::valid_leave(me, dir);
}
