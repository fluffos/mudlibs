//yanling
inherit ROOM;
void create()
{
  set ("short", "平安西路");
  set ("long", @LONG
从市中心往西走就到了平安西路，这里平安城的一条老街。两边的房屋
看上去已经很陈旧了。街道的北面的一间房子看上去象一个店铺。南面就是
顶顶大名的神针世家.
LONG);

set("outdoors","/d/pingan");

        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

  set("exits", ([  
    "north" : __DIR__"shop3",
    "south" : __DIR__"shenzhen/shenzhen",
    "east"  : __DIR__"west1",
    "west"  : __DIR__"west3",
]));
       
//	set("objects",([
//		__DIR__"npc/man4":1,
//	]));
	 setup();
        replace_program(ROOM);
}
