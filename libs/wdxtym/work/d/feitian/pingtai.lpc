// Room: /d/feitian/pingtai
inherit ROOM;

void create()
{
  set ("short", "瀑布平台");
  set ("long", @LONG
这里是瀑布里面的一个小平台。一个剑客正对着瀑布发呆。
平台外的瀑布犹如一道水帘，瀑布的冲击声一阵接一阵。
LONG);
      set("valid_startroom", "1");

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"anshi",
  "out" : __DIR__"pubu",
]));
  set("outdoors", "/d/feitian");
  set("objects", ([ /* sizeof() == 1 */
  "/quest/menpaijob/feitian/jianxin" : 1,
]));
  setup();
  replace_program(ROOM);
}
