// Room: /d/yanjing/tiejiang.c

inherit ROOM;

void create ()
{
  set ("short", "铁匠铺");
  set ("long", @LONG
墙角砌了个大炉子,小学徒正吃力地拉着风箱.一面墙边依着几把大
小不同的锤子,一只铁皮桶中装了半桶水,里面插了几把铁器,还未成形,看
不出是什么.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhang.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"street4",
]));

  setup();
}
