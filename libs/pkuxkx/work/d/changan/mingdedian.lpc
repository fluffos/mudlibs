
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "明德殿");
        set("long", @LONG
这是太子接见朝臣和举办重大政治获得的宫殿明德殿，
北面是太子寝宫崇教殿。
LONG    );
        
        set("exits", ([
           "north" : __DIR__"chongjiaodian",
           "southwest" : __DIR__"tongxunmen"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}