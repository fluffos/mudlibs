// Room: /d/huizhu/xianei
inherit ROOM;

void create()
{
  set ("short", "星星峡内");
  set ("long", @LONG
峡内两旁石壁峨然笔立，有如用刀削成，抬头望天，只觉天色又蓝
又亮，宛如潜在海底仰望一般。峡内岩石全系深黑，乌光发亮。道路
弯来弯去，曲折异常。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"gebi",
"east":__DIR__"xingxing",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
