//Create by jason@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;
int do_jump(string arg);

void create()
{
        set("short", "峡谷");
        set("long", @LONG
你的面前是一个深深的峡谷，对面比这边高出甚多，你可以试着跳过去。(jump valley)
LONG    );
        set("exits", ([ 
        "west": __DIR__"shidi",
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();        
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object p = this_player();
	if(!arg || arg != "valley")
	{
		return 0;
	}
	if(random(p->query_skill("dodge")) > 100)
	{
		message_vision("$N提起真气，纵身一跳，越过了悬崖，稳稳的落在了对面的地上。\n",p);
		p->move(__DIR__"pingdi");
	}
	else
	{
		if(random(p->query("kar")) > 15)
		{
			message_vision("$N勉强跳起一丈来高，眼看就要达到对面，却差了那么一点点，一声惨叫，摔下深渊。\n",p);
			p->move(__DIR__"xiagudi");
			p->unconcious();
		}
		else
		{
			message_vision("$N看着深不可测的峡谷，吓的两脚发软，晕倒在地上。\n",p);
			p->unconcious();
		}
	}
	return 1;
}