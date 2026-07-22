
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山间小路");
  set ("long", @LONG
这里是一条山路。北边是就是长城，南面一眼望去是一片树林，树
林看起来很大。这里已经是山西的境地了。四周怪石嶙峋，几乎辨认不
出前面的道路。
LONG);

  set("exits", ([
 "northup":__DIR__"shanlu1",
 "southeast":__DIR__"shanlu3",
        ]));
  set("outdoors","mayi");

  set("valid_startroom", 1);
  setup();

}

