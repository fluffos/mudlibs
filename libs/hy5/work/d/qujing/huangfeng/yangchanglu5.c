// created by angell 1/1/2001
// room: /d/qujing/huangfeng/yangchanglu5.c

inherit ROOM;

void create ()
{
  set ("short", "羊肠小道");
  set ("long", @LONG

小路崎岖难行，只在林间蜿蜒，似乎永无尽头。一路上但见古
木参天，香花烂漫。路上没什么行人，连鸟兽也不见一只。你
不觉得加快了步子。

LONG);

  set("exits", ([
        "south" : __DIR__"yangchanglu4",
        "north" : __DIR__"yangchanglu6",
      ]));
        set("outdoors", "xy6");
       
  setup();
}
