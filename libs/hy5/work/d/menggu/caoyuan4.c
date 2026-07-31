// Room: /d/menggu/caoyuan4
inherit ROOM;

void create()
{
  set ("short", "蒙古草原");
  set ("long", @LONG
乌云从西面的天空快速地移动过来,乌云中有闪点在不住闪动,乌云
下就是广袤的蒙古草原,远处的闪电照亮了一片连绵的营帐,那就是铁木
真的部落.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"caoyuan5",
  "south" : __DIR__"caoyuan",
  "east" : "/d/fengtian/out_fengtian_w",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
