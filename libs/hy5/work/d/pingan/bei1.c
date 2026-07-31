//yanglingdong2

inherit ROOM;

void create ()
{
  set ("short", "平安北街");
  set ("long", @LONG
这是平安城的一条老路平安北街。它南北横跨平安城。这里
是衙门和守城兵营的所在地。
LONG);

  set("outdoors", "pingan");
  set("no_beg", 1);
//  set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/man3" : 1,
//  __DIR__"npc/man4" : 1,
//]));
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan", 1);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yamen",
  "north" : __DIR__"bei2.c",
  "west" : __DIR__"bingyin",
  "south" : __DIR__"guangchang",
]));
  set("no_steal", 1);

  setup();
  replace_program(ROOM);
}
