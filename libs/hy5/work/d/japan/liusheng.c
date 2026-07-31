// Room: /d/japan/liusheng
inherit ROOM;

void create()
{
  set ("short", "剑室");
  set ("long", @LONG
一间空荡荡的房间,柳生英雄就在房间中间,他的面前放着一张矮几,
上面是一局未下完的围棋,脚边放着一把剑,有于经常使用,所有看来已经
很旧了.
LONG);
  set("objects",( [ /* sizeof() == 1 */
    __DIR__"npc/li":1,
]));

  set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"zoulang",
]));
  setup();
}
