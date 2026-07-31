// Room: /d/feitian/beijie
inherit ROOM;

void create()
{
  set ("short", "北街");
  set ("long", @LONG
你走到北街，鼻子马上闻到了一股浓浓的牛肉香气，你忍不住使劲的闻了闻
街道左边是一间牛肉馆，在京都可是非常有名的，南面就是京都广场了。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"niurouguan",
  "north" : __DIR__"jingbeisu",
  "south" : __DIR__"guangchang",
]));
  set("outdoors", "feitian");
  setup();
  replace_program(ROOM);
}
