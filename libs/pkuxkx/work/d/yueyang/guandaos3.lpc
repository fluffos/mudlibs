// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是一段蜿蜒的山路，北面通向岳阳城。南面通向苗岭。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown"     : __DIR__"guandaos2",
		"southup"     : "/d/miaojiang/miaolingin",
	]));
	setup();
	
}

int valid_leave(object me,string dir) //npc不许通向苗岭
{  
	if (dir=="southup")
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
    }
	return ::valid_leave(me, dir);
}