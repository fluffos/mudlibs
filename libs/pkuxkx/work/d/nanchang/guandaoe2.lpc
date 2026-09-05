// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "城东山路");
	set("long", @LONG
这里是南昌城东的山路，东面是一片遮天蔽日的老林子。
LONG );
	set("outdoors", "nanchang");
	set("no_clean_up", 0);
	set("exits", ([
		"westdown"     : __DIR__"guandaoe1",
		"eastup" : __DIR__"milinleft",
	]));
	setup();
	
}

int valid_leave(object me,string dir)
{  
	if (dir=="eastup")
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}
