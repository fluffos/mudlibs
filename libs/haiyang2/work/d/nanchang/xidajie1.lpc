
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是南昌的西大街。往西走可以到南昌最吸引人的地方鄱阳湖。东
边是南昌的中心了。有很多游客都在往鄱阳湖走去。北边有一家酒楼，传
来了阵阵酒香，喝酒吵闹的声音同时也充斥了整个街头。
LONG);

  set("exits", ([ 
 "north":__DIR__"xihulou",
  "west":__DIR__"xidajie2",
  "east":__DIR__"center",
         ]));
  set("objects",([
	  __DIR__"npc/wushi":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

