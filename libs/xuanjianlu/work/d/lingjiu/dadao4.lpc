//room: dadao1.c
inherit ROOM;

void create()
{
  set("short","山间小道");
  set("long",@LONG
这是一条青石铺成的小道。道旁是郁郁葱葱的松树林，不时可以看到一
两只松鼠蹦蹦跳跳地跃向树林深处。北边传来震耳欲聋的流水声，依稀
可以看到飞溅的水花。
LONG
     );
  set("outdoors", "lingjiu");
  set("exits",([
      "northup" : __DIR__"pubu",
      "southdown" : __DIR__"dadao3",
     ]));
  set("objects",([
    __DIR__"npc/songshu" : 2,
    ]));
 setup();
 replace_program(ROOM);
}