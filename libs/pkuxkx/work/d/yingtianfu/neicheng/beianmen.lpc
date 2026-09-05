//城门
// By Zine 23 Nov 2010

inherit "/d/yingtianfu/neicheng/gate";
#include <ansi.h>
int check_Bing();
void create()
{
        set("short", "北安门");
        set("long", 
"这里皇城的北门，很多御林军在巡弋。\n"

        );
        set("exits", ([
                
              
                
                "north" : __DIR__"shilu",
                "south" : __DIR__"jiaotai",
                
                
                
        ]));
		set("no_reset",1);
        set("no_clean_up", 1);
        set("objects", ([
                __DIR__"npc/bing1" : 2,
               
        ]));
		set("forbid_dir","south");
        set("outdoors", "yingtianfu");
        setup();
		call_out("check_Bing",1);
}
int check_Bing()
{
	object bing;
	remove_call_out("check_Bing");
	call_out("check_Bing",60);
	if (!present("yulin jun",this_object()))
	{
		bing=new(__DIR__"npc/bing1");
		bing->move(this_object());
		bing=new(__DIR__"npc/bing1");
		bing->move(this_object());
	}
}
