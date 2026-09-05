// Room: menggubao.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;
string look_hu();
void create()
{
	set("short", "射箭场");
	set("long", @LONG
这里是一块巨大的空地，也是蒙古勇士练习射箭的靶场。靶边一只箭壶(hu)
里装了一些最平常的木箭。
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"menggubao6",
        "southwest" : __DIR__"menggubao1",
		"east" : __DIR__"dahanerduo",
		//"south" : __DIR__"shanqian",
		"north" : __DIR__"7guai",
	]));
	set("item_desc",
        ([
        "hu":(:look_hu:),
        ]));
	set("objects", ([
        	__DIR__"obj/ba" : 1,
	]));
	set("no_robber",1);
    set("arrow",99);
	set("outdoors", "menggu_e");
	setup();
}

string look_hu()
{
	if (query("arrow")>0)
	{
		return "箭壶里还有"+chinese_number(query("arrow"))+"支木箭，你可以把木箭取(qu)出来。\n";
	}
	else
	{
		return "箭壶里的木箭已经被人取完了。\n";
	}
}

void init()
{
	add_action("do_qu","qu");
}

int do_qu()
{
	object me=this_player();
	object arrow;
	object *all_ob;
	int count=0,i;
	if (query("arrow")<=0)
	{
		tell_object(me,"箭壶里的木箭已经被取完了。\n");
		return 1;
	}
	all_ob=deep_inventory(me);
	for (i=0;i<sizeof(all_ob);i++)
	{
		if (all_ob[i]->query("is_arrow"))
		{
			count=count+1;
		}
	}
	if (count>4)
	{
		tell_object(me,"你身上的箭还不够多吗？\n");
		return 1;
	}
	arrow=new("/d/menggu/obj/arrow_s");
	arrow->move(me);
	this_object()->add("arrow",-1);
	message_vision("$N从箭壶中取出一支$n。\n",me,arrow);
	return 1;
}