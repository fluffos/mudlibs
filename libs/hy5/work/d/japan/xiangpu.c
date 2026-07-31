// Room: /d/japan/xiangpu
inherit ROOM;

void create()
{
  set ("short", "土肥原相扑屋");
  set ("long", @LONG
这是一间相扑屋.专门教授相扑的技巧.不过据说成为高手的关键是
首先成为一个大胖子.$#%^^&@#.....这里也时常举行相扑比赛.有兴趣你
也可以下场.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jiedaos2",
]));
  setup();
}
