#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "院子");
        set("long", @LONG
这里堆放着上百堆的石头。这些石头有大有小，大如一间房屋，小如
一个鸭蛋，形状大多都呈圆柱形。你发现从有些石头之间的缝隙(fengxi)
中飘出一股股的腥臭味，使你快要做呕了。
LONG);
        set("exits", ([
              "southeast" : __DIR__"yuanzi2",
              "northeast" : __DIR__"yuanzi5",
              "east" : __DIR__"yuanzi3",
        ]));
         set("item_desc", ([                    
                "fengxi": "\n缝隙里面漆黑一片，隐隐约约有沙沙的声响。\n",
        ]));
        set("outdoors", "白陀山");
        setup(); 
}

void init()
{   
	object me = this_player();
      	if(me->query_skill("poison", 1) < 50)
      		me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
      	if(me->query_temp("baituo_stone") > 2){
          	me->delete_temp("baituo_stone");
          	me->set_temp("baituo_wait", 1);
          	call_out("do_wait", 90, me);
        	}     
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");                   
}

int do_enter(string arg)
{
        object me = this_player();

        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙着呢。\n");
        if( !arg || arg=="" ) return 0;

        if (arg == "fengxi" ){   
        	message_vision("$N刨开缝隙口的乱石子，一弯腰往缝隙里钻了进去。\n",me);
                me->move(__DIR__"fengxi2");
                message("vision",me->name() + "从外面钻了进来。\n",environment(me), ({me}) );
                return 1;
        }     
}

void do_wait(object me)
{
	object room;
	if(!me || environment(me) != this_object()
	|| !living(me) || !me->query_temp("baituo_wait")) 
		return;
        message("vision","\n石柱忽然发出轧轧的声音，向一侧缓缓移开，向下露出一个黑洞洞的入口。\n\n", this_object() );
        set("exits/down", __DIR__"midao");
        if( room = load_object(__DIR__"midao") ) {
                room->set("exits/up", __FILE__);
                message("vision","\n头顶上的石柱忽然发出轧轧的声音，露出一个光亮亮的洞口。\n\n",room );
                } 
        remove_call_out("close_door");
        call_out("close_door", 5);
}


void close_door()
{
        object room;

        if( !query("exits/down") ) return;
        message("vision","\n石柱发出轧轧的声音，缓缓地移回原处，将向下的洞口盖住了。\n\n", this_object() );
        if( room = load_object(__DIR__"midao") ) {
                room->delete("exits/up");
                message("vision", "\n头顶上发出轧轧的声音，石柱又缓缓地收了回去，阶梯消失了。\n\n", room );
                }
        delete("exits/down");
}

int valid_leave(object me, string dir)
{        
       me->delete_temp("baituo_wait");
      
        return ::valid_leave(me, dir);
}
