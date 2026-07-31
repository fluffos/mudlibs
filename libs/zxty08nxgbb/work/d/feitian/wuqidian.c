// Room: /u/diabio/feitian/feitian/wuqidian.c
inherit ROOM;

void create()
{
  set ("short", "武器店");
  set ("long", @LONG
明治时期曾经很热闹的武器店,不过维新时期过后实行了废刀令.
这里也只好关门了,武器店里面一个人也没有静悄悄的.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jiedao2",
]));
  setup();
  replace_program(ROOM);
}
