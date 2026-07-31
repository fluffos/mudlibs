
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangnan"
#define TO __DIR__"jiangbei"
#include "shiproom.c";
void create ()
{
  set ("short","南江南岸");
  set ("long", @LONG
这里是南江的南岸。有很多行人在这里乘船，非常热闹。许多小商
小贩在这里叫卖，向即将登船展示自己的货物。货船的监工正在打骂着
搬货的工人，催促的声音不绝。只听一声“开船！”又一艘船驶出了港
口。
LONG);

  set("exits", ([ 

  "southwest":__DIR__"caodi2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

