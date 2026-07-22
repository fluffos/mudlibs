//room: xianchou.c
inherit ROOM;

void create()
{
  set("short","小径");
  set("long",@LONG
你滑落谷地,突然一阵香气避人,使人陶醉其中,似乎有两个美
貌如花的女子站在路中,你不竟想起了天使.你往前看去之间在
鲜花从中似乎有座城堡!
LONG
     );
  set("outdoors", "yihua");
  set("exits",([
      "south" : __DIR__"yihua_in",
      "up" : __DIR__"juebi",
     ]));

 setup();
 replace_program(ROOM);
}