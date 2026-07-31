// Room: /d/feitian/xiuxishi
inherit ROOM;

void create()
{
  set ("short", "休息室");
  set ("long", @LONG
神古活心流道场休息室。门下弟子练习累了后可以在这里休息。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiulianshi",
]));
  set("no_clean_up", 1);
set("sleep_room",1);
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
  replace_program(ROOM);
}
