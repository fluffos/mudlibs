//by hehe;//2003.1.15;
#include <ansi.h>
inherit ROOM;

void init();
int do_jump(string);
int do_bo(string);

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
"一把小桨，是划船用的。",
                           ]));
 
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_bo", "bo");
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

int do_bo(string arg)
{    object me;
     me = this_player() ;

     if (!arg )
	{
		return notify_fail("你用力划了几下，小船团团打转，看来你要先要找准一个方向。\n");	
	}

    if (arg != "mantuo" 
    && arg != "shenhe"
    && arg != "tingxiang")
       return notify_fail("没有这个方向。 \n");
    

     me->move("/d/murong/mantuo1");
     return 1 ;
}
