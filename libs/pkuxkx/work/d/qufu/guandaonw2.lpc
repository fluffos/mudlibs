// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。东南方向是通往曲阜曲阜，西北面不远就是
黄河渡口了。
LONG );
	set("outdoors", "zhongyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast"     : __DIR__"guandaonw1",
		"northwest" : "/d/huanghe/dkn1",
        
	]));
	setup();
	
}

int valid_leave(object me,string dir)
{  
	if (dir=="northwest")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}