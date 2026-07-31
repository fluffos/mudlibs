// Room: /d/feitian/changlewu.c
inherit ROOM;

void create()
{
  set ("short", "长乐屋");
  set ("long", @LONG
左之助的家就是这里了，在屋子中聚集了一群无所事事的人。
大家都在吆喝着进行着赌博，在桌子中站着一个身穿白衣，
背心印了一个恶字的人，那大概就是左之助了。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zuo.c" : 1,
  __DIR__"npc/dugun.c" : 4,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luorencun",
]));
  setup();
  replace_program(ROOM);
}
