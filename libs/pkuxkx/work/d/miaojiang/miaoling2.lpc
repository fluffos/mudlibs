// 密林
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "苗岭山林");
	set("long", @LONG
这里是一片遮天蔽日的苗岭山林，进来之后，你不由迷失了方向。山林藏在
雾中，雾里似有剧毒。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"miaoling2",	
		"east" : __DIR__"miaoling2",	
		"south" : __DIR__"miaoling2",	
		"north" : __DIR__"miaoling2",
        "southup" : __DIR__"miaoling2",
        "southdown" : __DIR__"miaoling2",
        "northup" : __DIR__"miaoling2",
        "northdown" : __DIR__"miaoling2",
        "westup" : __DIR__"miaoling2",
        "westdown" : __DIR__"miaoling2",
        "eastup" : __DIR__"miaoling2",
        "eastdown" : __DIR__"miaoling2",
		"southwest" : __DIR__"miaoling2",	
		"southeast" : __DIR__"miaoling2",	
		"northwest" : __DIR__"miaoling2",	
		"northeast" : __DIR__"miaoling2",	
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
    object miaoren;
    set("short", color[random(sizeof(color))]+"苗岭山林"+NOR);
    
    if (random(100)>85 && me->query_temp("jn/step4e") && me->query_temp("jn/miaoren"))
        {
            miaoren=new(__DIR__"npc/miaoren");
            tell_object(me,"你定睛一看，一个苗人出现在你面前。\n");
   		    miaoren->set_temp("seeme",me->query("id"));
    	    miaoren->move(this_object());
    		me->delete_temp("jn/miaoren");
        }
    if (me->query_skill("force",1)<400 && !me->query_temp("mlnopoison"))//内功高深免疫
        {
            F_POISON->poison_attack(this_object(),me,"xxfog-poison", me->query_condition("xxfog-poison")+random(10)*2);
            tell_object(me, HIB "山林中的雾气蕴藏着寒毒，你中毒了！\n" NOR );
        }
    
    
    if (me->query_temp("mlpass/count")>random(5)+10)
    {
        
        if (me->query_temp("mlpass/west")>random(5)+5)
        {
            exit=load_object(__DIR__"miaolingin2");
            if(objectp(exit))
            {
                set("exits/out", __DIR__"miaolingin2"); 
                tell_object(me,HIC"在你筋疲力尽之际，终于找到了出路(out)。\n"NOR);
                remove_call_out("close_door");
                call_out("close_door",15);
                return;
		    }
        }
        if (me->query_temp("mlpass/east")>15)
        {
            exit=load_object(__DIR__"miaozhai");
            if(objectp(exit))
            {
                set("exits/out", __DIR__"miaozhai"); 
                tell_object(me,HIC"在你筋疲力尽之际，终于找到了出路(out)。\n"NOR,me);
                remove_call_out("close_door");
                call_out("close_door",15);
                return;
		    }
        }
    }
	if (random(10)>3 || present("si nan", me)|| me->query_temp("jn/step4f"))
    {
        me->add_temp("mlpass/count",1);
    }
    else
	{
		tell_object(me,BLU "你正扶着树干休息，忽然发现所谓的树干竟是一条巨蟒，匆忙之间，你迷失了方向。\n"NOR);
		me->add_temp("mlpass/count",-1);
	}
		
	return;	
}


int valid_leave(object me,string dir)
{  
	if (dir=="eastup"|| dir=="east" || dir=="eastdown")
    {
        me->add_temp("mlpass/east",1);
        me->add_temp("mlpass/west",-1);
    }
    
    if (dir=="westup"|| dir=="west" || dir=="westdown")
    {
        me->add_temp("mlpass/east",-1);
        me->add_temp("mlpass/west",1);
    }
    if (dir!="out"&&dir==me->query_temp("mlpass/lastdir"))
    {
        return notify_fail("你像无头苍蝇一样在老林子里打转，根本不知道该往哪去！\n");
    }
	me->set_temp("mlpass/lastdir",dir);
	if(dir!="out"&&time() - me->query_temp("mlpass/last_go_time") <= 3)
	{
		return notify_fail("你发现前面似乎有人迹，加快了脚步赶过去，却什么也没有发现。\n");
	}
    me->set_temp("mlpass/last_go_time",time());
	return ::valid_leave(me, dir);
}

