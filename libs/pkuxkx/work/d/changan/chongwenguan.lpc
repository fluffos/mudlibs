
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "崇文馆");
        set("long", @LONG
这是太子读书所在崇文馆，也是皇家贵族学校，每年从皇族和一品
大员子弟中招收二十名馆生陪太子读书。馆中收藏了皇家从全国各地收
集来的珍贵典籍，有专人负责修缮校理图书。
LONG    );
        
        set("exits", ([
           "southeast" : __DIR__"chongjiaodian"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}