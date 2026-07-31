// Room: /d/menggu/guanmu
inherit ROOM;

void create()
{
  set ("short", "灌木丛");
  set ("long", @LONG
脚下走动时掠过长长的茅草,身边是高高矮矮的灌木丛.你叫不出名
目来,也看不清楚四边的景色,只有一条小路在灌木丛中时隐时现地伸
向小土丘的山顶.
LONG);

  set("outdoors", "menggu");
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"guanmu1",
  "westup" : __DIR__"hill",
]));
  setup();
  replace_program(ROOM);
}
