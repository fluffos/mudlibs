//dahu3.c
//by hehe
//2003.3.5

#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "渔船");
        set("long",@LONG
这是一艘典型的在湖行驶的小型渔船，船两边
是茫茫的太湖。
LONG);   
        set("no_task",1);
        setup();
}

int use_boat(object me)
{
	if ( !objectp(me) )
		return 0;
	
	tell_object(me, "你划着浆将小船开向了湖中央的小岛。\n");
	call_out("use_end", 10, me);
	return 1;
}

void use_end(object me)
{
	delete("in_use");
	if ( !objectp(me) )
		return;
		
	tell_object(me, "你将小船划到了一个小岛上，偷偷地停在小岛码头的一边，上了码头。\n");
	me->move("/d/murong/tbank");
}