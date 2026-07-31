//shanmen.c.承天寺山门
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"承天寺山门"NOR);
    set("long",@LONG
承天寺是西夏最大的寺院，始建于天佑重圣元年，历五年完工. 一条驿道直
通向远方, 面前是山门。山门用厚厚的杉木制成，上面包铜，镶满巨大的铜钉。
山门正上方悬着一块黑漆大匾，上面写着<<承天寺>> 三个大字，乃始帝元昊所
题。由于这是西夏皇家寺院，所以有铁鹞军前来巡逻。
LONG);
   
    set("exits",([
        "north"   : __DIR__"road27",
        "south"   : __DIR__"qiandian1",
    ]));
    set("outdoors","xingqing");
    setup();
}

