// Room: /d/feitian/xuanguan.c
inherit ROOM;

void create()
{
  set ("short", "玄关");
  set ("long", @LONG
在往里去就快到了活心流的道场了。到了这里就要脱下鞋子才能
进去了，日本人通常叫这里为玄关。左边的墙边放着一些木屐。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhongting",
  "north" : __DIR__"zoulang",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/muji.c" : 1,
]));
  setup();
  replace_program(ROOM);
}
