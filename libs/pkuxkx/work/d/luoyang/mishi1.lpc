//room /d/luoyang/密室
//Zine 11 Oct 2010
inherit __DIR__"mishiconfig";
#include <ansi.h>




void create()
{
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	set("short", color[random(sizeof(color))]+"密室"NOR);
	set("long", @LONG
这是一间密室。黑漆漆的什么都看不清楚。
LONG
	);

	set("exits", ([
		
		"north" : __DIR__"mishi2",
        "west" : __DIR__"mishi4",
        "northwest" : __DIR__"mishi5",
		
	]));
    

	
   setup();
   ::create();
}

int valid_leave(object me,string dir)
{  
	if (dir=="out") 
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        else
        {
            this_player()->delete_temp("tiejiangjob");
            this_player()->set("tiejiangjob_last_time",time());
            return 1;
        }
    }
	return ::valid_leave(me, dir);
}