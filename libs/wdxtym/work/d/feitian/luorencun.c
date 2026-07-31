// Room: /d/feitian/luorencun
inherit ROOM;

void create()
{
  set ("short", "落人村");
  set ("long", @LONG
破破烂烂的地方，墙角边蹲着一些衣着破烂的人，一见到你进来都用仇恨的眼神盯着你。
在村庄下面有一条还算干净的小路通往下边，隐约可以听到有人叫嚣的声音。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luoren.c" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jiedao3",
  "south" : __DIR__"changlewu",
]));
  set("outdoors", "feitian");
  setup();
  replace_program(ROOM);
}
