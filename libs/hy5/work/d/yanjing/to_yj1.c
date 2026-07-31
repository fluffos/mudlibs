// Room: /d/yanjing/to_yj1
inherit ROOM;

void create()
{
  set ("short", "盛京大道");
  set ("long", @LONG
大道笔直向北,通向[盛京],冰冷的雪花纷纷而下,道上行人撑着伞,坐
了车,赶车的批着油毡布,一个劲的驱马快走.前面的视线很快就被雪花遮
住,北边依稀是个小湖泊,向西北有个三叉路口.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"hubian",
  "northeast" : __DIR__"to_yj4",
  "southwest" : __DIR__"to_yj",
]));
  setup();
  replace_program(ROOM);
}
