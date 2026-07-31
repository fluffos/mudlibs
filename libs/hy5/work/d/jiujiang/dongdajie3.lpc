
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是九江的东大街。北面有一家兵器店，这里可以听到兵器店乒
乓的打铁声，远远望去，可以看到兵器店门前挂着一些刀剑等兵器，用
来招揽生意。东边是九江的东门了，有几个官兵正在那里检查着来往的
百姓。
LONG);

  set("exits", ([ 

 "east":__DIR__"dongmen",
  "west":__DIR__"dongdajie2",
  "north":__DIR__"bingqidian",
  "south":__DIR__"ygrestroom1",
        ]));
     
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

