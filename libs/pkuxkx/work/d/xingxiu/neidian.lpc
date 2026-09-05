// 内殿
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";

void create()
{
	set("short", "内殿");
	set("long", @LONG
这里天秀宫的内殿，几个星宿弟子正在打扫着这里。
LONG
	);
    set("normaldesc", @LONG
这里天秀宫的内殿，几个星宿弟子正在打扫着这里。
LONG
	);
	set("exits", ([ 
		"out" : __DIR__"tianxiugong",
        "north" : __DIR__"zuodian",
        "south" : __DIR__"youdian",
        "east" : __DIR__"yingbi",
		
    ]));
	set("objects", ([(__DIR__"npc/zinenpc") : 1,
    ]));
	setup();
	::create();
}

int valid_leave(object me,string dir)
{  
	if (dir=="out") 
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}
