
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","衙门");
  set ("long", @LONG
这里是九江的衙门。现在战局混乱，各路英雄竟相称豪，所以衙门
形同虚设。有几个衙役无精打采地站在那里，还有几个在那里打着盹。
LONG);

  set("exits", ([ 

  "west":__DIR__"nandajie2",
        ]));
  set("objects",([
    __DIR__"npc/yayi":2,
    ]));
  
  set("valid_startroom", 1);
  setup();
 
}

