// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIM"岳阳楼"NOR);
        set("long", "岳阳楼矗立于洞庭湖东岸。岳阳市西门城墙上，西临烟波浩淼的洞庭湖、北望\n滚滚东去的万里长江，水光楼影，相映成趣，素有“洞庭天下水，岳阳天下楼”\n的盛誉。\n");
        set("exits", ([
               //"northeast" : __DIR__"xunyanglou",
               "east" : __DIR__"westgate",
               "up" : __DIR__"yueyang2",
               "south" : __DIR__"dongtinghu",
               
                
        ]));
        set("valid_startroom", 1);
        set("objects", ([
		"/d/city/npc/yywaiter" : 1,
	    ]));  
        //set("outdoors", "yueyang");
        setup();
   
}
