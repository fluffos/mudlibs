// 山林
// edit: by zine Oct 19 2010

inherit __DIR__"shanlinconfig";

void create()
{
	set("short", "山林");
	set("long", @LONG
这里是一座毒虫出没的山林，千年的古树却是制作兵器的上佳材料。
LONG
	);
    set("normaldesc", @LONG
这里是一座毒虫出没的山林，千年的古树却是制作兵器的上佳材料。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"shanlinqian",
        "north" : __DIR__"shanlin4",
        "west" : __DIR__"shanlin1",
        "east" : __DIR__"shanlin2",
		
    ]));
	//set("objects", ([(__DIR__"npc/qinjun") : 1,
    //]));
	setup();
	::create();
}

int valid_leave(object me,string dir)
{  
	if (dir=="south") 
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}
