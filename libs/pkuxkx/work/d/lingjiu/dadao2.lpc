inherit ROOM;

void create()
{
  set("short","青石大道");
  set("long",@LONG
这是一条青石铺成的宽敞大道，每块青石都是长约八尺，宽约三尺，甚
是整齐，堪称巧夺天工。要铺成这样的大道，工程浩大之极，似非童姥
手下诸女所能。道旁是郁郁葱葱的松树林，不时可以看到一两只松鼠蹦
蹦跳跳地跃向树林深处。再向北，就是灵鹫宫的独尊厅的大门了。
LONG );
  set("outdoors", "lingjiu");
  set("exits",([
      "south" : __DIR__"dadao1",
      "north" : __DIR__"damen",
  ]));
  set("objects",([
      __DIR__"npc/songshu" : 2,
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
