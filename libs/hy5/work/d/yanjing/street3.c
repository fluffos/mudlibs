// Room: /d/yanjing/street3
inherit ROOM;

void create()
{
  set ("short", "街道");
  set ("long", @LONG
街道两边各类招牌林立,小贩们摇着鼓,敲着铃,走千家,过万户,大声
吆喝,几个金兵在街道中央大模大样的走过,一些人围在一起讨论着什么,街
道东边是家饭店.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"fandian",
  "north" : __DIR__"street2",
  "south" : __DIR__"gate",
]));
  setup();
  replace_program(ROOM);
}
