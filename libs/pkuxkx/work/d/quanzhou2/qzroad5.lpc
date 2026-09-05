// Room: /d/quanzhou/qzroad5.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "武夷山路");
	set("long", @LONG
你走在东南第一山脉武夷山上。海风从东面吹来，带着几分寒意。
南边就是著名的海港泉州了。
LONG
	);

	set("exits", ([
                "north" : __DIR__"qzroad4",
                "south" : __DIR__"beimen",
                "northwest" : "/d/nanchang/guandaos4",
//                "westup" : "/d/nanchang/milinout",
	]));

        set("objects", ([
        "/d/quanzhou/npc/xiaofan" : 1,
		"/d/wudang/npc/yetu" : 2, ]));

	set("outdoors", "quanzhou");
	setup();
	
}

int valid_leave(object me,string dir)
{  
	if (dir=="westup")
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}

