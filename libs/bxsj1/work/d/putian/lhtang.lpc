// Room: /d/putian/lhtang.c 罗汉堂
// lklv 2001.9.12

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "罗汉堂");
        set("long", @LONG
这里是罗汉堂，面前是一座很大的院落，周围用高墙围住，院门匾额上写
着『罗汉堂』三个大字。这里是少林弟子练习本门基本武功的所在。有很多年
轻的僧人进进出出，院内传来阵阵呼喝练功的声音。
LONG
        );

        set("exits", ([
                "east" : __DIR__"dc-dian",
        ]));

        set("objects",([
                __DIR__"npc/wuseng" : 2,
                CLASS_D("putian") + "/yuantong" : 1,
        ]));

        setup();
}
