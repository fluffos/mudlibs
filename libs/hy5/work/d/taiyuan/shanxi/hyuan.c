#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "荷花园"); 
        set("long", @long
院子里种了各色名贵的菊花。黄菊有都胜、金芍药、报君知。
白菊有月下白、一团雪、貂蝉拜月。紫菊有双飞燕、紫玉莲、玛瑙
盘。红菊有美人红、醉贵妃、绣芙蓉。。。院中有几盆颜色特别娇
艳的黄花，花瓣黄得像金子一样，花朵的样子很像荷花。那就是从
天竺传来的金波旬花。
long); 
       // set("type","waterbody");
        set("exits",([
                "northeast":__DIR__"fang3",
                "northwest":__DIR__"fang4",
                "east":__DIR__"fang1",
                "west":__DIR__"fang2",
                "north":__DIR__"tang",
                "south":__DIR__"yuan4",
        ]) );
                set("objects", ([
      
        __DIR__"npc/begger" : 1,
               
                                        __DIR__"npc/zhanggui" : 1,
                        ]) );
       set("outdoors", "shanxi");
        
        set("coor/x",-500);
        set("coor/y",-330);
        set("coor/z",100);
        setup();
} 