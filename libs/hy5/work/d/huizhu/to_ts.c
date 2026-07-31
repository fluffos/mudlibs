// Room: /d/huizhu/huanglu1
inherit ROOM;

void create()
{
  set ("short", "荒路");
  set ("long", @LONG
这是条荒野小路，路上几乎看不见什么人。阴风四起，让你觉得后
颈发凉。西边看去，已可见天山的轮廓。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west":__DIR__"to_ts",
  "east":__DIR__"huanglu3",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
