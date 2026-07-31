// Room: /d/yandang/river
inherit ROOM;

void create()
{
  set ("short", "长江边上");
  set ("long", @LONG
滚滚长江水,奔流入海,北风吹来,带着微微的江水的气息,青青的绿
草把江岸点缀得分外美丽,江的对端就是兵家必争之地---竞陵.
LONG);

  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shulin",
]));
  setup();
}
