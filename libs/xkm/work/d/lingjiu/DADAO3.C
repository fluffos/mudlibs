//room: dadao3.c
inherit ROOM;

void create()
{
  set("short","山间小道");
  set("long",@LONG
这是一条青石铺成的小道。道旁是郁郁葱葱的松树林，不时可以看到一
两只松鼠蹦蹦跳跳地跃向树林深处。远远传来阵阵水声。
LONG
     );
  set("outdoors", "lingjiu");
  set("exits",([
      "northup" : __DIR__"dadao4",
      "southdown" : __DIR__"ya",
     ]));
  set("objects",([
    __DIR__"npc/songshu" : 2,
    ]));
 setup();
 replace_program(ROOM);
}