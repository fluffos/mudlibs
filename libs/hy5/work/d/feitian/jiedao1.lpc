// Room: /d/feitian/jiedao1
inherit ROOM;

void create()
{
  set ("short", "街道");
  set ("long", @LONG
街道左右两边都是商店，向左走就是京都广场了。前方不远处通往神古活心流道场
下方有一家药铺，据说在这里很有一番名气。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yaopu",
  "east" : __DIR__"jiedao2",
  "north" : __DIR__"jiedao",
  "west" : __DIR__"guangchang",
]));
  set("outdoors", "feitian");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/baixing" : 1,
]));
  setup();
  replace_program(ROOM);
}
