// Room: /d/feitian/jiedao2.c
inherit ROOM;

void create()
{
  set ("short", "街道");
  set ("long", @LONG
京都的一条普通的街道，往右边走不了多远就可以见到一个很大的树林了。
在街道下面有个普通的武器店。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jiedao1",
  "south" : __DIR__"wuqidian",
  "east" : __DIR__"jiedao3",
]));
  set("outdoors", "feitian");
  setup();
  replace_program(ROOM);
}
