// zhou_ju.c
//
// Created by pretty (09/17/98)

#include <room.h>

inherit ROOM;

int do_get(string arg);

void create()
{
	set("short", "小屋");
	set("long", @LONG
这是一间宽敞明净的小屋，里面的家具很少，只有一张桌子，两个椅
子和一张床。但屋里的玩具却不少，什么风筝呀，陀螺呀，风车呀，摆的
到处都是，似乎是个爱玩的孩子住的地方。
LONG
	);

        set("exits", ([
                "south" : "/d/quanzhen/fengchang",
        ]) );
		create_door("south", "竹门", "north", DOOR_CLOSED);
	set("objects", ([
                 "/d/dali/yideng/npc/zhou" : 1,
		"/u/pretty/obj/table"   : 1,
		"/u/pretty/obj/chair"   : 1,
	]) );

	setup();
}

void reset()
{
	object con, ob;

	::reset();
	if ( objectp(con = present( "桌子", this_object() )) )
	{
		if ( !objectp(ob = present( "feng zheng", con )) )
		{
			ob = new(__DIR__"obj/fengzheng");
			ob->move(con);
		}
		if ( !objectp(ob = present( "tuo luo", con )) )
		{
			ob = new(__DIR__"obj/tuoluo");
			ob->move(con);
		}
	}

	if ( objectp(con = present( "椅子", this_object() )) )
	{
		if ( !objectp(ob = present( "feng che", con )) )
		{
			ob = new(__DIR__"obj/fengche");
			ob->move(con);
		}
	}
}
