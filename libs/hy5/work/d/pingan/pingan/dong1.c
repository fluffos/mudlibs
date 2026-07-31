//dong1

inherit ROOM;

void create()
{
  set ("short", "平安东路");
  set ("long", @LONG
这是平安城的一条老路。它东西横跨平安城。路北面的一片房子看
是虽然不是很新，可一看就知道是一家大的钱庄。两个护卫叉腰守着门口，
东面是一家不小的当铺.

LONG);

set("outdoors","pingan");

        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

set("exits", ([
    "west" : __DIR__"guangchang",
    "north" : __DIR__"bank1",
    "south"  : __DIR__"dangpu",
    "east" : __DIR__"dong2",
]));

//	set("objects" , ([
//		__DIR__"npc/man5" : 1,
//	]));
         setup();
        replace_program(ROOM);
}
