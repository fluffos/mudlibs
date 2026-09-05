//米市 /d/jinyang/eaststreet2
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "东大街");
        set("long", 
"一条繁华的大街，也是横穿晋阳的主干道了。南面是一家镖局，已经经营了\n几代。你可以敲(knock)敲门(gate)。\n"

        );
        set("exits", ([
                "west" : __DIR__"eaststreet1",
                "east" : __DIR__"eaststreet3",
                "northeast" : __DIR__"machehang",
                 
        ]));
        
        set("outdoors", "jinyang");
        setup();
   
}


void init()
{ 
	add_action("do_qiao","knock"); 
}

int do_qiao(string arg)
{
	object room;
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
	if(!arg)
		{
			return notify_fail("你要敲什么？\n");
		}
    if(arg != "gate")
		{
            return notify_fail("你要敲什么？\n");
		}
    if (query("exits/south"))
		{
			return notify_fail("门已经开了，你还要怎么敲？\n");
		}
    if(!( room = find_object(__DIR__"biaoju")) )
		{
			room = load_object(__DIR__"biaoju");
		}
    if(objectp(room))
        {
			set("exits/south", __DIR__"biaoju"); 
			message_vision("$N使劲拍打大门，里面出来一个人把门打开了。\n",me);
			remove_call_out("close_door");
			call_out("close_door",3); 
		}
    return 1;
}

int close_door()
{
	delete("exits/south",);
    tell_room(this_object(),"镖局里面的人把门又关上了。\n");
	return 1;
}