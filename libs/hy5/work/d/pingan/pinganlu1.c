// Room: /d/pingan/pinganlu1
inherit ROOM;

void create ()
{
  set ("short", "平安大道一");
  set ("long", @LONG
宽阔的大街，和气的居民，处处是一片升平景象，平安城的大道就和它
的名字一样，给人平实的感觉。
LONG);

  set("outdoors", "pingan");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pinganlu2",
  "south" : __DIR__"pinganmen",
]));
  set("pingan", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);

  setup();
  replace_program(ROOM);
}
