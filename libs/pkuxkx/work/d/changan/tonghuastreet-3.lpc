//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "通化门大街");
        set("long", @LONG
这里是长安交通主干道通化门大街，南来北往地车队连绵不绝。
两边都是皇亲国戚的官邸，南面相传是唐玄宗入住的宫殿兴庆宫。
LONG);
        set("exits", ([
           "east" : __DIR__"tonghuamen",
           "west" : __DIR__"tonghuastreet-2",
           "south" : __DIR__"yuelongmen",
           "north" : __DIR__"changlefang"
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}