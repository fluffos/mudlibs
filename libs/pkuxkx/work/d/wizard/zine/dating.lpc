#include <room.h>
#include <ansi.h>
#include <localtime.h>
inherit ROOM;
string forbidden();
void create()
{
        set("short", "铜雀大厅");
        set("long", @LONG
这是铜雀台后的大厅，分别通向几间不同的房间。

LONG
        );
        set("exits", ([
             "north" : __DIR__"book-room",
             "west" : __DIR__"secret-room",
             "northwest" : __DIR__"money-room",
			 "northeast" : __DIR__"liangong",
             "east" : __DIR__"the-room",
			 "south" : __DIR__"safari",
 
        ]));
        set("item_desc",
        ([
			"northeast": (:forbidden:),
        ]));
        
        setup();
      
}

string forbidden()
{
	string msg="你刚向东北面的静室探头探脑的张望，立刻被铜雀台主人阻止了。\n";
	return msg;
}

