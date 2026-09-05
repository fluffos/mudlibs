//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"金光门城楼"NOR);
        set("long", @LONG
这是金光门城门上的望楼，一队队壮健的金吾卫盔甲
鲜明，手持陌刀长戟，强弓利箭，警惕的注视着城下过望
行人；城门两边是长长的长安外郭城墙。
LONG        );

        set("exits", ([
                "north" : __DIR__"citywall19",
                "south" : __DIR__"citywall16"
        ]));
        
        set("locate_level",4);

        set("outdoors", "changan");
        set("changan", 4); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}