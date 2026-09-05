//Create by jason@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;
int do_push(string arg);
int close_door();

void create()
{
        set("short", "峡谷底");
        set("long", @LONG
这里十分幽暗，抬头望去，可以看到斑斑点点的阳光透过密实的树林投射下来。一股腐臭的气息让你心中慌乱。
有一块光滑的岩石上没有任何的植被，看来有些古怪。
LONG    );

        set("no_clean_up", 0);
        set("outdoors", "tiezhang");
        setup();        
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object p = this_player();
	if(!arg || arg != "stone")
	{
		return 0;
	}

	if(random(p->query("kar")) > 15 && p->query("neili") > 1000)
	{
		message_vision("$N大喝一声，双手用力，岩石居然被推开了。\n",p);
		set("exits",([
			"enter":__DIR__"yandong",
			]));
		remove_call_out("close_door");
		call_out("close_door",15);
	}
	else
	{
		message_vision("$N试了试，岩石纹丝不动。\n",p);
	}
	p->add("neili",-1000);
	return 1;
}

int close_door()
{
	delete("exits");
}