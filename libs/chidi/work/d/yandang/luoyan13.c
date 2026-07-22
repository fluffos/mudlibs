// Room: /d/yandang/luoyan13.c

inherit ROOM;

void create ()
{
  set ("short", "书房");
  set ("long", @LONG
这是一间书房,靠窗的书桌上摆着文房四宝,还有一幅没写完的字摊
在上面,靠墙摆着书架,正面的墙上挂了一幅画,上面的一群秋雁展翅欲飞
栩栩如生,屋角的一只景泰炉正冒着青烟.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuan.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luoyan14",
  "north" : __DIR__"luoyan15",
  "south" : __DIR__"luoyan39",
]));

  setup();
}
