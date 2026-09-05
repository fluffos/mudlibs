//lane.c -- 僻静小巷
//Zone: 汝阳王府
//Create by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"僻静小巷"NOR);
  set("long", @LONG
这里是一条僻静的小巷，一个人也没有。西边是汝阳王府内宅的后门
，但是大门(door)紧闭，关的严严实实。
LONG
  );
	
	set("item_desc", ([
		"door" : "两扇大门确实关得很死，但仔细查看，门边的墙(wall)上似乎有几个浅浅的脚印。\n",
	]));

  set("exits", ([     
      "northeast" : "/d/luoyang/hutong1",   
  ]));

  set("outdoors", "luoyang");
  set("no_clean_up", 0);
  setup();
}

void init()
{
	add_action("do_jump", "climb");
	add_action("do_jump", "pa");
	add_action("do_jump", "tiao");
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
        int n = this_player()->query_skill("dodge",1);
        me = this_player();
        
	if (!arg || (arg != "wall"))
		return notify_fail("你要干什么？\n");
	
	if( arg=="wall" ) 
	{
		if( n > 100 ) 
		{
			message_vision(
			"\n$N踮步拧腰、挺身上纵，轻而易举地跃上了墙头，\n\n$N四下一望，见院内无人，接着使了一个“乳燕穿林”，悄无声息地落下地来。\n\n", me);
			remove_call_out("moveme");
			call_out("moveme", 1, me);
		}
		else
		{
			message_vision(
			"\n$N踮步拧腰、挺身上纵，结果一头撞在墙上，跌了下来，落地的时候，脚也崴了……\n$N悻悻地揉着瘸了的脚，心中似有无数苦楚，但脸上却拼命忍着不露出来。\n\n", me);
		}
	}

return 1;
}

int moveme(object me)
{
	me->move(__DIR__"houmen");
	return 1;
}