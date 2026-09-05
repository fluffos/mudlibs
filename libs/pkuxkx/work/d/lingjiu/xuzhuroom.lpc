#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "卧房");
  set ("long", @LONG
一间淡湖绿色的房间,对湖的一面开了一扇竹窗, 窗前放着一架五弦琴,
墙边有一张牙玉色的软榻，三面是书架, 上面居然摆满了佛经，显得很不协
调.
LONG);

  set("no_fight", 1);

  set("exits", ([ /* sizeof() == 1 */
 
 "east" : __DIR__"zoulang2",
"west":__DIR__"huayuan"]));

  setup();
}
