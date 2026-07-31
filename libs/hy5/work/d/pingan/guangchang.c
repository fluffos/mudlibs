// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

void create ()
{
  set ("short", "平安广场");
  set ("long", @LONG
这儿是平安城的中心广场，由于最近的发展！这儿变大了许多。一如平
安城其它的地方一样！这儿也是一片和平的景象，平安城的居民们在周围走
来走去，对江湖人物并不回避。广场四周由于最近的发展变的繁荣起来了，
四周有很多房屋和街道。
LONG);

  set("no_beg", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nan1",
  "west" : __DIR__"west1",
  "east" : __DIR__"dong1",
  "north" : __DIR__"bei1",
]));

  set("pingan", 1);
  set("outdoors", "pingan");
  set("no_sleep_room", 1);
  set("no_steal", 1);

  setup();
  replace_program(ROOM);
}
