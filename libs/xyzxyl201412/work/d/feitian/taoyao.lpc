// Room: /d/feitian/taoyao
inherit ROOM;

void create()
{
  set ("short", "陶窑");
  set ("long", @LONG
你一走进来就被一股热气所笼罩，前方的陶窟正冒出滚滚黑烟，窟的左边
搭了个小架子上面放置了一些陶器。陶窟周围散落着一些松枝木材。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xiaodao",
]));
  set("outdoors", "/d/feitian");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tianfeng" : 1,
]));
  setup();
  replace_program(ROOM);
}
