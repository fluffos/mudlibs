// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "城西山路");
	set("long", @LONG
这里是南昌城西的山路，西面就快要到苗岭了。
LONG );
	set("outdoors", "nanchang");
	set("no_clean_up", 0);
	set("exits", ([
		"westup"     : "/d/miaojiang/miaolingin",
		"eastdown" : __DIR__"guandaow2",
        "northup" : __DIR__"shuyuan",
	]));
	setup();
	
}

int valid_leave(object me,string dir) //npc不许通向苗岭
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