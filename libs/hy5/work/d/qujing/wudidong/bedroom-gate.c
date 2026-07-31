// Room: /d/qujing/wudidong/bedroom-gate.c

inherit ROOM;

void create ()
{
  set ("short", "彩楼");
  set ("long", @LONG

好一间齐楚阁儿！白墙灰瓦，爬满了种种奇花，一扇紧闭的小小朱门，
也是藤萝掩映，更显得郁郁葱葱。门口站了两个小妖，打扮得倒也齐
整，看来这里正是洞主的绣房。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kanmen" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"houdong",
  "east" : __DIR__"inner-bedroom",
]));

  setup();
}
