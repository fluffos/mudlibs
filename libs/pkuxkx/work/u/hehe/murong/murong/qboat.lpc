//qboat.c
//by hehe
//2003.3.13

#include <ansi.h>
inherit ROOM;

void init();
int do_jump(string);
int do_row(string);

void create()
{
	set("short", "小船");
	set("long", @LONG
小船就在听雨居的下边，离岸(bank)不远，看来是有人精心安
排好的逃生工具。因为船小，仅能容纳二三人。船仺内放着一把
浆(jiang)，
LONG
 );

	set("cost", 1);
	set("outdoors", "murong");
        
         set("item_desc", ([
              "bank" :
"岸不远，你可以试着跳(jump)上去。",
              "jiang" :
"一把小桨，是划船(row)用的。",
                           ]));
 
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_row", "row");
}
 
int do_jump(string arg)
{
	object me;
        me = this_player() ;

	if (!arg || (arg != "bank" ))
	{
		return notify_fail("你往哪儿跳？\n");	
	}
	
	me->move("/d/murong/road");
        message_vision("$N从船上跳了过来，脸色有点苍白。\n",me);
        
        return 1 ;
}

int do_row(string arg)
{    object me;
     me = this_player() ;

     if (!arg )
	{
		return notify_fail("你用力划了几下，小船团团打转，看来你要先要找准一个方向。\n");	
	}

    if (arg == "mantuo")
	{
        message_vision("$N拿起船桨用力划了起来。\n",me);
		me->move("/d/murong/dahu");
		call_out("waitmt", 10 , me );
		return 1 ;
	}
	else if (arg == "yanziwu")
	{
        message_vision("$N拿起船桨用力划了起来。\n",me);
		me->move("/d/murong/dahu");
		call_out("waityz", 10, me);
		return 1;
	}
	else if (arg == "tingxiang")
	{
        message_vision("$N拿起船桨用力划了起来。\n",me);
		me->move("/d/murong/dahu");
		call_out("waittx", 10, me);
		return 1;
	}
	else
	{
        message_vision("没有这个方向，$N想好方向再走吧。\n",me);
		return 1;
	}
}
void waitmt(object me)
{
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
    message_vision("不知过了多久，船终于靠岸了，$N累得满头大汗。\n",me);
	me->move ("/d/murong/mbank") ;
}
void waityz(object me)
{
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
    message_vision("不知过了多久，船终于靠岸了，$N累得满头大汗。\n",me);
	me->move ("/d/murong/ybank") ;
}
void waittx(object me)
{
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
    message_vision("不知过了多久，船终于靠岸了，$N累得满头大汗。\n",me);
	me->move ("/d/murong/tbank") ;
}