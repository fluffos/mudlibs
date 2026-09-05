//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "通化门大街");
        set("long", @LONG
这里是长安交通主干道通化门大街，南来北往地车队连绵不绝。
两边都是皇亲国戚的官邸，北面就是大明宫，南面通向东市。
LONG);
        set("exits", ([
           "east" : __DIR__"tonghuastreet-3",
           "west" : __DIR__"tonghuastreet-1",
           "north" : __DIR__"danfengstreet-1",
           "south" : __DIR__"danfengstreet-2"
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}