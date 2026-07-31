//ROOM:/d/suzhou/kezhan2.c
//by dwolf
//97.11.7

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG "客店后院" NOR);
	set("long", @LONG
	这是客栈的后院，里面树影婆娑，一些青年男女正依偎在一起窃窃私语，让
单身的你眼红不已。左边是专门为男人可的客房，右边是为女人开的。北边是为情人
们开的，呵呵。
LONG
	);

	set("no_fight", 0);
	set("valid_startroom", 0);
        set("no_sleep_room",1);

	set("exits", ([
		"north" : __DIR__"kefang1",
		"south" : __DIR__"kefang2",
		"east" : __DIR__"kefang3",   
		"west" : __DIR__"kezhan",
	]));

	setup();
}       
  

int valid_leave(object me, string dir)
{
    object *inv;
    mapping mygen;
    int i;
        
	   if (dir == "south" && ((string)me->query("gender") =="男性") && !wizardp(
me))
                return notify_fail("你个大老爷们儿去那干嘛！！\n");
        return 1;       

   if (dir == "north" && ((string)me->query("gender") =="女性") && !wizardp(
me))
                return notify_fail("你个小女孩儿去那干嘛！！\n");
        return 1;
	                                                    
}


