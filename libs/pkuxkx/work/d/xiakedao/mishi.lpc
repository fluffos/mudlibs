#include <ansi.h>
inherit ROOM;
int do_push(string arg);

void create()
{
        set("short", "侠客岛密室");
        set("long", @LONG

    这是一间极大的石室，四周墙壁为玉石所造，显然不是
天然的石洞。一定隐藏着什么秘密。

LONG
        );
        set("placefor_xksh",1);

        set("exit", ([
        ]));
       
        setup();
}

void init()
{
        add_action("do_search","search");
        add_action("do_push","push");
}

int do_search()
{
        object me,book;

        me = this_player();

        message_vision("$N认真地搜索着什么。\n", me);
        
        if ((int)me->query("jing")<=50) 
        { 
                tell_object(me,"你太累了，休息一下吧！\n");
                return 1;
        }

        if ( random(50) == 10 )
        {
                book=new(__DIR__"obj/xkshfa_book");
                book->move(me);
                tell_object(me, "你不经意间在烛台的一角找到了一张古画。\n");
        }

        me->receive_damage("jing", 30);

        return 1;

}

int do_push(string arg) 
{                       
	int max;
	int max2;    
	object me;    
	me=this_player();
	if( !arg || arg=="" ) return 0;
        if( arg=="石壁")
        {                              
		message_vision("$N提一口气，运劲双臂，在石壁右边用力一推，\n", this_player());
		write("石壁缓缓退后，却是一堵极厚、极巨、极重、极实的大石门。\n");
                set("exits/out", __DIR__"garden");
                remove_call_out("close");
                call_out("close", 10, this_object());

                return 1;
       }
}

void close(object room)
{
        message("vision","石门缓缓合拢。\n", room);
        room->delete("exits/out");
}
int valid_leave(object me, string dir)
{       
	int i;
        object *inv;
	object inv1;
        inv = all_inventory(me);

	for( i = 0; i<sizeof(inv); i++)
	{
		inv1 = inv[i];
		if( inv1->query("id") == "picture" ) 
		{
	 	tell_object(me,YEL"你的古画突然就不见了。\n"NOR);  
	 	destruct(inv1);
		}
	}      
	return ::valid_leave(me, dir);
}
