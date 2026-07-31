// Room: /d/feitian/zoulang
inherit ROOM;

void create()
{
  set ("short", "走廊");
  set ("long", @LONG
道场走廊，地下全用竹子铺成的人走上去脚底下凉凉的很是舒服
在向前走就到了显赫一时的神古活心流道场了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shulin1",
  "south" : __DIR__"qianting",
]));
  setup();
  replace_program(ROOM);
}
