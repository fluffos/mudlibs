// Room: /d/huashan/place.c
// Date: Look 99/03/25

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山路");
	set("long", 
HIW"你紧跟着哑巴在一条几乎不是路的陡峭崖壁上走着。\n"NOR
);
	setup();
}
void init()
{ 
	object me = this_player();
       add_action("do_action", "");                             
	call_out("do_go", 5, me);
}
int do_action(string arg)
{
       string action = query_verb();

       switch (action) {
               case "look":
               case "exercise": 
               case "lian":
               case "tuna":       
               case "quit":
               case "l" :
	        case "dazuo" :
	        case "save" : 
               case "practice":
               write(HIW"你紧跟着哑巴在一条几乎不是路的陡峭崖壁上走着。\n\n"NOR);
                       return 1;
       }
       return 0;
}	

void do_go()
{
	object me = this_player();
	write("你气喘嘘嘘的跟在哑巴后面，实在是跟不上了，只好把木桶扔掉。\n", me);
	call_out("do_go1", 5, me);
}
void do_go1()
{
	object me = this_player();
	write("不一会儿，哑巴带你来到了一处空地前。\n", me);
	me->move(__DIR__"kongdi");
	message_vision("哑巴朝北面的松林走去。\n", me);
	call_out("do_back", 0, me);
}

void do_back(object me)
{
	if( present("shui tong", me))
	destruct(present("shui tong", me));
}
