#include <room.h>
inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这里是翰林府的花园。院子里种了各色名贵的菊花。黄菊有都胜、
金芍药、报君知。白菊有月下白、一团雪、貂蝉拜月。紫菊有双飞燕、
紫玉莲、玛瑙盘。红菊有美人红、醉贵妃、绣芙蓉。。。院中有几盆
颜色特别娇艳的黄花，花瓣黄得像金子一样，花朵的样子很像荷花。那
就是从天竺传来的金波旬花。
LONG
        );

        set("exits", ([
                "east" : __DIR__"dongxiang",
        ]));


        set("cost", 2);
        setup();
}

