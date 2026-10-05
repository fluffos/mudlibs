#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("地下武器库");
  set_long( @CLong
你走进了一间放满了武器的大库房，四面的墙上钉满了各式的架子，而架子上
则整齐地挂著刀斧剑戟。而最引人注目的，应该是房间角落的几樽大炮了。这儿可
以算是牧马关的战备库房，大量的装备不禁让你幻想在原野上双方大军嘶杀的情景
。在房间中央狭小的空间里，一张小木桌上放满了各种工具和待修的武器，看来这
儿的工匠的工作也不轻松。东边的一扇小门可以回到密道中。
CLong
);
set("light",1);
set("exits",([
               "west": UNDER "path04"
             ]));
set("objects",([
               "artisan": MOB"weapon_smith",
               ]));
reset();
}
