// Room: /d/hainan/tohaitan
inherit ROOM;

void create()
{
  set ("short", "石路");
  set ("long", @LONG
一条碎石子小路,南边直通向大海,阵阵波涛声随风吹来,路边开始
出现大片的黑色岩石,几只海鸟在你视线中掠过.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"haitan",
  "north" : "/d/quanzhou/haigang",
]));
  set("outdoors", "/d/hainan");
  setup();
  replace_program(ROOM);
}
