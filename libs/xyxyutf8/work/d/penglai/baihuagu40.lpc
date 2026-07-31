
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  set ("short", "百花谷");
  set ("long", @LONG

一片平坦谷地，四周是青山环绕，山腰间白云悠悠，
真是一片神仙福地。谷内四季常春，各色鲜花，竞相
争艳，满目青翠萦目，红紫迎人，好一片锦绣乾坤，
花花世界。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"baihuagu30",
  "south" : __DIR__"baihuagu0",
  "east" : __DIR__"baihuagu41",
  "west" : __DIR__"baihuagu44",
  "southeast" : "/d/baihuagu/flower2",
]));
  set("outdoors",1);
  setup();
}
