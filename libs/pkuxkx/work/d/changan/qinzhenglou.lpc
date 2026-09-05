//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "勤政务本楼");
        set("long", @LONG
这是龙池西南角的勤政务本楼，相传唐玄宗用来与民同乐，
交流同欢之所，和东南面的花萼相辉楼合围出一个巨大的广场，
节日时节举行大型的游艺活动，与百姓同欢。东面是兴庆宫的
南大门通阳门。
LONG);
        set("exits", ([
           "northwest" : __DIR__"huaelou",
           "east" : __DIR__"tongyangmen"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}