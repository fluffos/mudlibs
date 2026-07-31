// Room: /d/huizhu/xiaoxi
inherit ROOM;

void create()
{
  set ("short", "小溪流");
  set ("long", @LONG
在差刺交错的岩石之间流淌的一条小溪流。清澈的河底是光滑的鹅
卵石。流淌的溪水微微带着香气，溪水中无数小块碎冰互相撞击，发出
清脆声音，叮叮咚咚，宛如仙乐。西边是条直通西方的山路。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westup":"/d/mingjiao/westroad1",
  "northup" : __DIR__"xiaoxi1",
  "east" : __DIR__"gebi1",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
