// Room: /d/japan/zhongxin
inherit ROOM;

void create ()
{
  set ("short", "市中心");
  set ("long", @LONG
这里是神户的中心.有四条街道从此分别通向四个方向.你一眼望去.
街道两边的商店招牌高低起伏.组成了一道奇特的风景.
LONG);

  set("outdoors", "japan");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiedaos2",
  "east" : __DIR__"jiedaoe1",
]));

  setup();
       replace_program(ROOM);
}
