//Create by jason@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "平地");
        set("long", @LONG
这是一篇相当开阔的平地,东边有一座隐蔽的房子。西边则是一条深深的峡谷，你可以试着跳过去。(jump valley)
LONG    );
        set("exits", ([         
        "east": __DIR__"cangku"
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");
		set("objects",([
			__DIR__"npc/busheren":1
		]));
		set("tianmo_book_num",1);
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
	message_vision("$N提起真气，纵身一跳，越过了悬崖，稳稳的落在了对面的地上。\n",p);
	p->move(__DIR__"xiagu");
	return 1;
}
