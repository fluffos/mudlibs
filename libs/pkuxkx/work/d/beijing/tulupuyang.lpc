//Zine Dec 1 2010

inherit ROOM;

void create()
{
        set("short", "土路");
        set("long", @LONG
这里是一段土路，往北不远就是濮阳了，南面是黄河北岸。
LONG
        );
        set("outdoors", "beijing");
        set("exits", ([
		"southwest" : "/d/huanghenorth/hhb3",
		"northwest" : __DIR__"puyang",
        ]));
	set("cost", 2);

        setup();
        
}
int valid_leave(object me,string dir)
{  
	if (dir=="southwest" && !userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
    {
           return notify_fail("!!!!\n");
        
    }
	return ::valid_leave(me, dir);
}