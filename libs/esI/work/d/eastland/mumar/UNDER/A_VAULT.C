#pragma save_binary
#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("地下装备库");
  set_long( @CLong
你走进了一间放满了装备的大库房，四面的墙上钉满了各式的架子，而架子上则
整齐地挂著胄甲和头盔。这儿可以算是牧马关的战备库房，大量的装备不禁让你幻想
在原野上双方大军嘶杀的情景。在房间中央狭小的空间里，一张小木桌上放满了各种
工具和待修的装备，看来这儿的工匠的工作也不轻松。东边的一扇小门可以回到密道
中。
CLong
);
set("light",1);
set("exits",([
               "east": UNDER "path04"
             ]));
set("objects",([
               "smith": MOB"armor_smith",
               ]));
reset();
#include <replace_room.h>
}
