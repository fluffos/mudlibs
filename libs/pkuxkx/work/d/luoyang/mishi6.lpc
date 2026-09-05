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
		
		"northeast" : __DIR__"mishi2",
        "west" : __DIR__"mishi7",
        "south" : __DIR__"mishi5",
		
	]));
    

	
   setup();
   ::create();
}


