//dong1

inherit ROOM;

void create()
{
  set ("short", "平安东路");
  set ("long", @LONG
这是平安城的一条老路。它东西横跨平安城。路南面有一家
书店,听说专卖武功书,北面有不少人,是一家武馆.前面的东门还
没有开放.
LONG);

set("outdoors","pingan");

        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

  set("exits", ([
    "west" : __DIR__"dong1",
    "north" : __DIR__"wuguan",
    "south"  : __DIR__"shop5",
]));

//	set("objects" , ([
//		__DIR__"npc/man6" : 1,
//	]));
         setup();
        replace_program(ROOM);
}
