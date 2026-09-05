// Room: /d/diaoyudao/jiaoshi.c 大礁石
// hongdou 98.09.20

#include <ansi.h>
inherit ROOM;

void init()
{
        add_action("do_climb", "climb");
	add_action("do_bo","bo");
}


void create()
{
	set("short", "大礁石");
	set("long", @LONG
你转到大礁石的东南侧，如果从这里爬上去不会比那边容易。
这里的野草(cao)更加旺盛，一直向东南面延伸生长。
LONG
	);

	set("item_desc", ([
               "cao" : "野草有什么好看的，你无聊不无聊啊！！！\n",	
       ]));

	set("exits", ([
                "southwest" : __DIR__"jiaoshi",
           "southeast" : __DIR__"caodi5",
	]));

	set("objects", ([

	]));

	set("outdoors", "diaoyudao");
	setup();
}



int do_bo(string arg)
{
	object ob;
	object me = this_player();
	if( !arg || arg!="cao" ) 
	{
	     if ( !arg ) return notify_fail("你要拨开什么？\n");
             if ( arg!="cao" )  return notify_fail("那个东西不能拨开！\n"); 
        }
	if (arg=="cao")
	{
		if (this_player()->query_temp("jiao2/拨1") ) 
		{
		   message_vision(HIY "$N小心翼翼地拨开野草......。\n" NOR,me);
		   set("exits/enter", __DIR__"caocong");
		   remove_call_out("close");
		   call_out("close", 5, this_object());
		   return 1;
		}
		   message_vision(HIY "$N小心翼翼地拨开野草......" + HIR +"突然！"+HIY+"跳出一只巨海蟹。\n" NOR,me);
		   ob = new(__DIR__"npc/haixie2");
             ob->move("/d/diaoyudao/jiaoshi1");
		   this_player()->set_temp("jiao2/拨1", 1);
		   return 1;
	}
}

void close(object room)
{
	message("vision","只见分开的野草自动收拢，恢复原状了。\n", room);
	room->delete("exits/enter");
}	




