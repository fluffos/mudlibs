// Room: /d/huizhu/guandao1
inherit ROOM;

void create()
{
  set ("short", "官道");
  set ("long", @LONG
这是条连接京城与嘉峪关的官道，东边是京城方向，西边通往嘉峪
关。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east":__DIR__"guandao3",
  "west":__DIR__"guandao1",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
