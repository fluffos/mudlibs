//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "国子学");
        set("long", @LONG
国子学有五名博士，面向国公以上级别爵位子弟，教授四书五经和
君子六艺的一般知识。
LONG);
        set("exits", ([
           "east" : __DIR__"guozijian",
           "southwest" : __DIR__"guozi-boshi1",
           "south" : __DIR__"guozi-boshi2",
           "north" : __DIR__"guozi-boshi3",
           "west" : __DIR__"guozi-boshi4",
           "southeast" : __DIR__"guozi-boshi5",
        ]));
        
        set("locate_level",7);
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}