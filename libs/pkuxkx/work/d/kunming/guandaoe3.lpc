// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是昆明城东的山路，东面是一片遮天蔽日的老林子。
LONG );
	set("outdoors", "kunming");
	set("no_clean_up", 0);
	set("exits", ([
		"westdown"     : __DIR__"guandaoe2",
		"eastup" : "/d/miaojiang/miaolingin2",
	]));
	setup();
	
}

int valid_leave(object me,string dir) //npc不许通向苗岭
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