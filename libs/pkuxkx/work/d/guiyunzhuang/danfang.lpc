
//Made By:pingpang
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","炼丹房");
	set("long",@LONG
这里是归云庄的炼丹房,是专门为陆庄主补身子而备的.
每逢陆庄主修心养性之时,这里就非常忙活,赶炼灵丹.
LONG);
	set("objects",([__DIR__"obj/lu":1,__DIR__"obj/peifang":1,__DIR__"npc/danren":1,]));
	set("exits",(["east":__DIR__"zoulang4"]));
	set("no_fight",1);
	set("no_magic",1);
	setup();
}
void init()
{
	add_action("do_stiring","stiring");
}
int do_stiring()
{
	object ob;
	if(this_player()->query_temp("marks/药"))
	 	{
			ob=new(__DIR__"obj/nvwashi");
			ob->move(__FILE__);
			message_vision("$N不停地用药匙搅拌着,终于炼丹炉里炼出了"YEL"女娲石"NOR"来.",this_player());
			this_player()->set_temp("marks/药",0);
		}
}
int valid_leave(object me,string dir)
{
	if( (dir=="east")&&(present("nvwa shi",this_player())||present("shilian dan",this_player()))
	&&objectp(present("liandan ren",environment(me))))
	return notify_fail("炼丹人说道:你怎么能把灵丹拿出去呢?\n");
	return ::valid_leave(me,dir);
}
