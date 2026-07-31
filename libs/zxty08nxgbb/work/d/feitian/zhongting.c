// Room: /d/feitian/zhongting.c
inherit ROOM;

void create()
{
  set ("short", "中庭");
  set ("long", @LONG
这里是日式房间一般都有的中庭了。宽敞的房间摆放着一些家用
必须品，四周的墙壁全是用竹子建成的，让人进来有一股舒适清
凉的感觉。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianting",
  "north" : __DIR__"xuanguan",
]));
  setup();
  replace_program(ROOM);
}
