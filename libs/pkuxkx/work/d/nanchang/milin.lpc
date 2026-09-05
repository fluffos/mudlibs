// 密林
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "老林");
	set("long", @LONG
这里是一片遮天蔽日的老林子，进来之后，你不由迷失了方向。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"milin",	
		"east" : __DIR__"milin",	
		"south" : __DIR__"milin",	
		"north" : __DIR__"milin",
        "southup" : __DIR__"milin",
        "southdown" : __DIR__"milin",
        "northup" : __DIR__"milin",
        "northdown" : __DIR__"milin",
        "westup" : __DIR__"milin",
        "westdown" : __DIR__"milin",
        "eastup" : __DIR__"milin",
        "eastdown" : __DIR__"milin",
		"southwest" : __DIR__"milin",	
		"southeast" : __DIR__"milin",	
		"northwest" : __DIR__"milin",	
		"northeast" : __DIR__"milin",	
    ]));
	set("no_task",1);
    set("real_dark",1);
    set("no_sleep_room",1);
	setup();
	
}

int close_door()
{
	delete("exits/out",);
	return 1;
}

void init()
{
	int i;
	object me=this_player();
    object exit;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
    set("short", color[random(sizeof(color))]+"老林"+NOR);
    
    if (me->query_temp("nlpass/count")>15)
    {
        if (me->query_temp("nlpass/east")>15)
        {
            exit=load_object(__DIR__"milinout");
            if(objectp(exit))
            {
                set("exits/out", __DIR__"milinout"); 
                tell_object(me,HIG"在你筋疲力尽之际，终于找到了出路(out)。\n"NOR);
                remove_call_out("close_door");
                call_out("close_door",15);
                return;
		    }
        }
        if (me->query_temp("nlpass/north")>15)
        {
            exit=load_object(__DIR__"milinin");
            if(objectp(exit))
            {
                set("exits/out", __DIR__"milinin"); 
                tell_object(me,HIC"在你筋疲力尽之际，终于找到了出路(out)。\n"NOR);
                remove_call_out("close_door");
                call_out("close_door",15);
                return;
		    }
        }
        if (me->query_temp("nlpass/west")>15)
        {
            exit=load_object(__DIR__"milinleft");
            if(objectp(exit))
            {
                set("exits/out", __DIR__"milinleft"); 
                tell_object(me,HIC"在你筋疲力尽之际，终于找到了出路(out)。\n"NOR);
                remove_call_out("close_door");
                call_out("close_door",15);
                return;
		    }
        }
    }
	if (random(10)>3 || present("si nan", me))
    {
        me->add_temp("nlpass/count",1);
    }
    else
	{
		tell_object(me,BLU "一只黑色大鸟朝你飞了过来，吓了你一跳，定下神来，你发现失去了方向。\n"NOR);
		me->add_temp("nlpass/count",-1);
	}
		
	return;	
}




int valid_leave(object me,string dir)
{  
	if (dir=="westup"|| dir=="west" || dir=="westdown")
    {
        me->add_temp("nlpass/west",1);
        me->add_temp("nlpass/east",-1);
    }
    if (dir=="eastup"|| dir=="east" || dir=="eastdown")
    {
        me->add_temp("nlpass/east",1);
        me->add_temp("nlpass/west",-1);
    }
    if (dir=="northup"|| dir=="north" || dir=="northdown")
    {
        me->add_temp("nlpass/south",-1);
        me->add_temp("nlpass/north",1);
    }
    if (dir!="out"&&dir==me->query_temp("nlpass/lastdir"))
    {
        return notify_fail("你像无头苍蝇一样在老林子里打转，根本不知道该往哪去！\n");
    }
	me->set_temp("nlpass/lastdir",dir);
	if(dir!="out"&&time() - me->query_temp("nlpass/last_go_time") <= 3)
	{
		return notify_fail("你发现前面似乎有人迹，加快了脚步赶过去，却什么也没有发现。\n");
	}
    me->set_temp("nlpass/last_go_time",time());
    
	return ::valid_leave(me, dir);
}

