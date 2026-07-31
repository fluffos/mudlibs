// Room: /d/feitian/xiaodao
inherit ROOM;

void create ()
{
  set ("short", "林间小道");
  set ("long", @LONG
穿过黑漆漆的森林终于到了一块明亮的地方，小道前方是一间简陋的小屋。
左边不断的冒着黑烟，好象是有人在烧什么东西似的。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shulin4",
  "north" : __DIR__"xiaowu",
  "west" : __DIR__"taoyao",
]));
  set("outdoors", "feitian");

  setup();
  replace_program(ROOM);
}
