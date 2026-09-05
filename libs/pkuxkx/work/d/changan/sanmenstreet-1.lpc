//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "三门大街");
        set("long", @LONG
长安皇城城墙下的一条大街，东面就是皇城，北面通向通化门大街，
南面通向金光门大街。
LONG);
        set("exits", ([
           "north" : __DIR__"tonghuastreet-4",
           "south" : __DIR__"weststreet-1",
        ]));

        set("outdoors", "changan");
        setup();
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙   
}