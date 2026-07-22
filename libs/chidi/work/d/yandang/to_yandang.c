// Room: /d/yandang/to_yandang
inherit ROOM;

void create()
{
  set ("short", "大路");
  set ("long", @LONG
在一望无际的平野之中,这条大道如同玉带一般,穿过绿色的农田,
向西是中州的东门.东面云际中露出高山的影子.
LONG);

  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"to_yandang2",
  "west" : "/d/zhongzhou/dongmeng",
]));
  setup();
}
