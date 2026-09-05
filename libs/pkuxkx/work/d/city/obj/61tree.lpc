// dumpling.c 包子

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("愿望树", ({"wishing tree", "tree"}));
	set("long","这是一棵参天大树，据说在儿童节的时候对着她许愿(wish)，愿望就会实现！\n");
set("value",1);
set("unit","棵");
	set_weight(80);
	set("no_get",1);
	setup();

}

void init()
{
	add_action("do_wish","wish");
}

int do_wish(string arg)
{
	if(!arg||arg=="")
	{	write("你可以wish exp neili jingli。\n");
		return 1;
	}
	if(this_player()->query("61mark"))
	{write("今年的六一节你已经许愿了啊。\n");
	return 1;
	}
	if(arg=="exp")
	{
		this_player()->add("combat_exp",20000);
		this_player()->set("61mark",1);
		write("你心中默默许下愿望。。。。\n");
		return 1;
	}

        if(arg=="neili"){
		this_player()->add("max_neili",500);
		this_player()->set("61mark",1);
		
	   write("你心中默默许下愿望。。。。\n");
	                   return 1;
	}
	if(arg=="jingli"){
		this_player()->add("max_jingli",500);
this_player()->set("61mark",1);
    write("你心中默默许下愿望。。。。\n");
          return 1;
	       }

	       write ("你要许什么愿望呢？\n");
	       return 1;

}	
