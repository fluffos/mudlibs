// Room: /d/huizhu/guandao1
inherit ROOM;

void create()
{
  set ("short", "官道");
  set ("long", @LONG
这是条连接京城与嘉峪关的官道，东边是京城方向，西边就是天下
闻名的嘉峪关了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east":__DIR__"guandao2",
  "west":__DIR__"jiayuguan",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
