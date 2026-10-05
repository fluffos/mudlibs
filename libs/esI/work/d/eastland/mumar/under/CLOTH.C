#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("晒衣场");
  set_long( @CLong
这里是一片斜坡，被牧马关规划为晒衣场，整片广大的晒衣场上整齐地挂著上百
件的各色衣物，排得像五行八卦似的，让你觉得好像走在一片迷宫之中。南面下坡底
是一道土色的墙，北边上坡则传来阵阵的马骚味。
CLong
);
set("exits",([
               "northdown": UNDER "healroom",
               "southup": MUMAR "stable"
             ]));
set("pre_exit_func",(["northdown":"go_northdown",
                      "southup"  :"go_southup"]));
reset();
}
int go_northdown()
{
        write("你穿过布幕般的墙，走进医务室里。\n。");
        return 0;
}
int go_southup()
{
        write("你绕啊绕啊，绕出了迷宫般的晒衣场。\n。");
        return 0;
}
