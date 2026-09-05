// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
大道两旁有一些小货摊，似乎是一处集市。北边通向扬州城。南面不远处是扬子津
渡口，可以乘船渡过长江。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"northwest" : __DIR__"guandaos1",
		"southup" : "/d/changjiangnorth/dkb1",
	]));
    set("no_task",1);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me,string dir)
{  
	if (dir=="southup")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee")&&!me->query("npc_permit_pass"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}