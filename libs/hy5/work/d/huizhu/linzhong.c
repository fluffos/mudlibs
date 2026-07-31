// Room: /d/huizhu/linzhong
inherit ROOM;

void create()
{
  set ("short", "树林中");
  set ("long", @LONG
这是树林中的一片空地,给人为的打扫整理过,空地的中央一堆篝火
已经熄灭,边上散落着一些牛羊的骨头,几块大石块散落在篝火的四周.
草地上留下许多人践踏过的痕迹.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shulin2",
  "north" : __DIR__"shulin1",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
