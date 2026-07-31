// Room: /d/japan/sleeproom
inherit ROOM;

void create()
{
  set ("short", "睡房");
  set ("long", @LONG
一间不大的房间,中间摆着榻榻米,收拾得还挺干净.墙脚的花瓶中还
插了枝花.墙上糊的是干净的白纸.
LONG);
   set("sleep_room",1);
   set("no_fight",1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"lvdian",
]));
  setup();
         replace_program(ROOM);
}
