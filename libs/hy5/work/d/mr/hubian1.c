// /u/beyond/mr/hubian1.c 
// this is made by beyond 
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",GRN"湖边"NOR);
         set("long", @LONG
俗话说 : 上有天堂, 下有苏杭。这里正是大大有名的太湖。 湖面绿波
上漂着一叶叶的小舟, 一阵阵悦耳的小曲儿随着湖上的轻风不时漂入你的耳
中。
LONG
      );
       set("outdoors","mr");
       set("exits", ([
           "west" : __DIR__"hubian",
           "east" : __DIR__"hubian2",
]));
       setup();
       replace_program(ROOM);
}
