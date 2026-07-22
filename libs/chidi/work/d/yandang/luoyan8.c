// Room: /d/yandang/luoyan8.c

inherit ROOM;

void create ()
{
  set ("short", "客厅");
  set ("long", @LONG
客厅是庄主招待贵客的地方,里面装点得朴实而不富贵,却处处显落
出精致不凡,地面上铺设的是天蓝色的大理石,正中是一张红木盘龙桌
旁边伺候的是几个丫鬟.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yahuan.c" : 2,
]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luoyan11",
  "south" : __DIR__"luoyan7",
  "north" : __DIR__"luoyan12",
]));

  setup();
}
