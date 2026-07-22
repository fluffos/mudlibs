//room: sleeproom.c
//sleeproom
inherit ROOM;

void create()
{
  set("short","玫瑰阁");
  set("long",@LONG
这里是移花宫弟子睡觉的地方，一进门就闻到一阵悠悠的香气，仔细一看
才发现里面的床全是由鲜花扎成，你不由得佩服扎这个花床的工人的手艺简直
是巧夺天工。
LONG
     );

  set("exits",([
      "west" : __DIR__"yihua_ge",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);

 setup();
 replace_program(ROOM);
}
