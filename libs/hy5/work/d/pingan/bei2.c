//yanglingdong2

inherit ROOM;

void create ()
{
  set ("short", "平安北街");
  set ("long", @LONG
这是平安城的一条老路平安北街。它南北横跨平安城。这里
是菜园和平安武庙的所在地。前面的北门好像还没有开放.
LONG);

  set("outdoors", "pingan");
  set("no_beg", 1);
//  set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/man1" : 1,
//  __DIR__"npc/man2" : 1,
//]));
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan", 1);
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"caidi",
  "west" : __DIR__"wumiao",
  "south" : __DIR__"bei1",
"in" : "/clone/quarry/dong01"
]));
  set("no_steal", 1);

  setup();
  replace_program(ROOM);
}
