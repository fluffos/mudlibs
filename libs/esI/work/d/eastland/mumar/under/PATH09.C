#pragma save_binary
#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("坑道");
  set_long( @CLong
你走到了坑道的末端，一队工兵正在这里辛勤地向前挖掘。这儿看起来十分潮□
而泥泞，而地上则散落著一些工具。就坑道的长度看来，这里的上方距离牧马关已有
一段距离，不过就工兵们的工作情形看来，他们似乎还打算继续往前挖，真不知到底
他们打算挖到那里。
CLong
);
set("light",1);
set("exits",([
               "southeast": UNDER "path08"
             ]));
set("objects",([
               "master": MOB"worker1",
               "soldier#1": MOB"worker2",
               "soldier#2": MOB"worker3" ]));
reset();
#include <replace_room.h>
}
