// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。大道两旁有一些小货摊，似乎是一处集市。
东面就是建康府的地界了。
LONG );
	set("outdoors", "jiangzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown"     : "/d/yingtiannorth/qingliang",
		"westup" : __DIR__"guandaoe4",
	]));
	setup();
	
}

int valid_leave(object me,string dir)
{  
	if (dir=="eastdown")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee") )
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}