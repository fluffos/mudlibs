
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "凌烟阁");
        set("long", @LONG
凌烟阁最初是太宗为表彰开国功臣的功绩和辅弼之功而设立的，后来将图像
列入凌烟阁成为褒奖功臣的最好形式之一，将图像列入凌烟阁表示了对你为大唐
作出贡献的一种肯定。
    如今这里陈列了曾经叱诧风云的武林高手的画像。
LONG    );
        
        set("exits", ([
                "west" : __DIR__"ganludian",
                "enter":"/d/wizard/laxiang",                
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        setup();   
}