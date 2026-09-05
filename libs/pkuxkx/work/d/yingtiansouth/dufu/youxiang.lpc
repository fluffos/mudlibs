inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "右厢房");
        set("long", 
"这里是都统制府的东侧的厢房。\n"

        );
        set("exits", ([
                
                //"east" : __DIR__"",
                "south" : __DIR__"shuichi",
                //"west" : __DIR__"zuoxiang",
                "west" : __DIR__"houting",
                
        ]));
        set("objects", ([
        //"/d/city/npc/bing" : 1,
        
        ]));
        //set("outdoors", "yingtianfu");
        setup();
   
}

int valid_leave(object me,string dir)
{
	if (dir=="south")
	return notify_fail("你要在都统制府投水自杀吗？\n");
	return ::valid_leave(me,dir);
}