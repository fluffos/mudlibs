//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "延喜门城楼");
        set("long", @LONG
这是延喜门城门上的望楼，一队队壮健的金吾卫盔甲
鲜明，手持陌刀长戟，强弓利箭，警惕的注视着城下过望
行人；城门西北面是东宫，西南面是皇城。
LONG        );

        set("exits", ([
                "north" : __DIR__"innerwall3",
                "south" : __DIR__"innerwall5",
                "west" : __DIR__"innerwall11"
        ]));
        
        set("locate_level",4);
        set("changan", 4); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        set("outdoors", "changan");
        setup();   
}