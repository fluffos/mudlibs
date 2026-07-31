// Room: /open/killer/room/r0u.c
inherit ROOM;

void create ()
{
  set ("short", "训练室");
  set ("long", @LONG
如果，想成为独当一面的杀手就好好的在这里向前辈们讨教吧！！
他们有许多经验，可以成为你们的参考对象。好好加油吧！
如果是新进杀手，还是乖乖的到楼下练习吧。
有一对联：
      暗器对敌用，快速又方便。
      背刺太取巧，基础不稳固。
LONG);

  set("exits", ([ /* sizeof() == 1 */
   "down" : __DIR__"r0.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/npc/train_a.c" : 2,
]));
  set("light_up", 10);

  setup();
}