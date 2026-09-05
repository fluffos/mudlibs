//mishi room
#include <ansi.h>
inherit ROOM;
int do_push(string arg);

void create()
{
      set("short", "明教密室");
        set("long", @LONG
    这是一间极大的石室，顶上垂下钟乳，显然是天然的石洞。地下倒着两具骷髅，
骷髅身上衣服尚未烂尽，看得出是一男一女。
LONG
        );

        set("exit", ([
        ]));
        set("item_desc", ([
		"骷髅" : "男骷髅的手旁好像有封信。\n" ,
	    "skeleton" : "男骷髅的手旁好像有封信。\n"
	]));
        set("placefor_qkdny",1);
        set("no_task",1);
        setup();
}

void init()
{
        add_action("do_pick","pick");
        add_action("do_ketou","ketou");
        add_action("do_push","push");
}

int do_pick(string arg)
{
        object me,letter;
        
        me=this_player();

	if (!arg || arg=="")
		return notify_fail("pick <物件>\n");

        if( arg=="letter" ) 
        {
                message_vision(
		"$N走到那个男子的骷髅之前，随手把信拾了起来。\n", me);
                letter = new(__DIR__"obj/letter");
                letter->move(me);
		return 1;
        }

        return notify_fail("你要拿什么？\n");
}


int do_ketou()
{
        object me,book;

        me = this_player();

        message_vision("$N虔诚地跪下来，在骷髅前磕头。\n", me);
        
        if ((int)me->query("jing")<=50) 
        { 
                tell_object(me,"你太累了，休息一下吧！\n");
                return 1;
        }

          if ( random(50) == 37 )
        {
                book = new(__DIR__"npc/obj/skinbook");
                book->move(me);
                tell_object(me, "突然骷髅哗得一声倒下，露出一本羊皮书!\n");
        }

        me->receive_damage("jing", 50);

        return 1;

}

 

int do_push(string arg) 
{                       
	int max;
	int max2;    
	object me;    
	me=this_player();
	max=(int)me->query("max_neili");                  
	max2=(int)me->query_skill("guangming-shenghuogong");
        if( !arg || arg=="" ) return 0;
        if( arg=="无妄石壁")
        {                              
		if( max < 600 || max2 < 40)
                {              
		message_vision("$N提一口气，运劲双臂，在石壁右边用力一推，\n", this_player());
		write("石壁微微一晃。\n");
		return 1;
		}else
		{
		message_vision("$N提一口气，运劲双臂，在石壁右边用力一推，\n", this_player());
		write("石壁缓缓退后，却是一堵极厚、极巨、极重、极实的大石门。\n");
                set("exits/out", __DIR__"midao");
                this_player()->add("neili",-150); 
                remove_call_out("close");
                call_out("close", 10, this_object());

                return 1;
		}
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
		if( inv1->query("id") == "xin fa" ) 
		{
	 	tell_object(me,YEL"你的乾坤大挪移心法突然就不见了。\n"NOR);  
	 	destruct(inv1);
		}
	}      
  return ::valid_leave(me, dir);
}
