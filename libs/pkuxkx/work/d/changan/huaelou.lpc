//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "花萼相辉楼");
        set("long", @LONG
这是龙池西南角的花萼相辉楼，为盛唐五大名楼之首，相传唐
玄宗用来与民同乐，交流同欢之所，和东南面的勤政务本楼合围出
一个巨大的广场，节日时节举行大型的游艺活动，与百姓同欢。
LONG);
        set("exits", ([
           "northeast" : __DIR__"longchi-1",
           "southeast" : __DIR__"qinzhenglou"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}