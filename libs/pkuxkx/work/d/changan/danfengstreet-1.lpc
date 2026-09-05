//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "丹凤门大街");
        set("long", @LONG
这里是大明宫前的丹凤门大街，相传武则天在位的时候最喜欢
在这条大街上检阅自己的帝国。
LONG);
        set("exits", ([
           "south" : __DIR__"tonghuastreet-2",
           "north" : __DIR__"danfengmen",
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}