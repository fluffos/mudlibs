// Room: /d/4world/schoolbook.c
inherit ROOM;

void create()
{
  set ("short", "书房");
  set ("long", @LONG

书房中整理得相当干净，靠窗摆着一张大的红木书桌，上面还铺着
红色的缎布。桌上摆着些书，还有些文房四宝。一个小花瓶里还插
着些采来的小花。靠墙一个大书架上摆满了书籍。南边可以看到天
井及一些来回走动的家人。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"schoolin",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dongfangying" : 1,
  __DIR__"npc/dongfanger" : 1,
]));

  setup();
}
