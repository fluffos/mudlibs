//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "太学");
        set("long", @LONG
太学有六名博士，面向郡县公两个级别爵位官员子弟，教授四书五经和
君子六艺的一般知识。
LONG);
        set("exits", ([
           "south" : __DIR__"guozijian",
           "northeast" : __DIR__"taixue-boshi1",
           "northwest" : __DIR__"taixue-boshi2",
           "southeast" : __DIR__"taixue-boshi3",
           "southwest" : __DIR__"taixue-boshi4",
           "east" : __DIR__"taixue-boshi5",
           "west" : __DIR__"taixue-boshi6",
        ]));
        
        set("locate_level",5);
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}