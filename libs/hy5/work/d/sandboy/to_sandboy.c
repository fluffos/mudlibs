// Room: /d/sandboy/to_sandboy
inherit ROOM;

void create()
{
  set ("short", "大道");
  set ("long", @LONG
大道朝南,一路平坦,远观丘岭起伏,农田绿树,别有江南风味道.再向
南去有个三叉路口.
LONG);

  set("outdoors", "/d/sandboy");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"river",
  "north" : "/d/wudang/wdroad4",
  "south" : __DIR__"to_sandboy2",
]));
  setup();
}
