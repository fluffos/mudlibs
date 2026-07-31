// jiulaodong.h
// 九老洞
#include <ansi.h>
void init()
{
        add_action("do_use", "use");
        add_action("do_leave", "leave");
}

int do_use(string arg)
{
    object room, ob, me;
   me = this_player();
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n");

        if(!objectp(ob = present("fire", me)))
        return notify_fail("你手中没有火折，怎么能进的了山洞？\n");

	if( !arg || arg=="" ) return 0;

	if( arg == "fire" ) {
        message_vision(BLU"$N点燃火折，把洞内照亮了一些。
洞内亮了一些，微弱的火光一闪一闪的。\n"NOR, me);
        destruct(ob);
        if(!(room = find_object(__DIR__"jiulaodong1")))
            room = load_object(__DIR__"jiulaodong1");
            set("exits/north", __DIR__"jiulaodong1");
            set("exits/south", __DIR__"jiulaodong1");
            set("exits/west", __DIR__"jiulaodong1");
            set("exits/east", __DIR__"jiulaodong1");
            set("exits/southwest", __DIR__"jiulaodong1");
            set("exits/southeast", __DIR__"jiulaodong1");
            set("exits/northwest", __DIR__"jiulaodong1");
            set("exits/northeast", __DIR__"jiulaodong1");
            call_out("delete_exit", 4, room); 	
            return 1; }
}
void delete_exit(object room)
{       
        delete("exits/south");
        delete("exits/north");
        delete("exits/west");
        delete("exits/east");
        delete("exits/northwest");
        delete("exits/northeast");
        delete("exits/southwest");
        delete("exits/southeast");
}

int do_leave()
{
        object me = this_player();

        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n");
        
        if(present("fire", me) )
        return notify_fail("你手里还有火折，为什么不用他照照路？\n");

        if(!present("fire", me) ){
        if(random(30) >= 20) {
        write("你转来转去，终于转到了洞口。\n", me);
        me->move(__DIR__"dongkou");
        message_vision("$N从九老铜里走了出来。\n", me);
	return 1;
        }
        else {
        message_vision("$N像没头苍蝇一样在洞里瞎钻，结果一头撞在洞壁上。
你觉得你晕乎乎的，似乎撞傻了。\n", me);
        me->move(__DIR__"jiulaodong1");
        me->receive_damage("jingli", 20);
        me->delete_temp("marks/east");
        me->delete_temp("marks/west");
        me->delete_temp("marks/north");
        me->delete_temp("marks/south");
        me->delete_temp("marks/northwest");
        me->delete_temp("marks/northeast");
        me->delete_temp("marks/southwest");
        me->delete_temp("marks/southeast");
        return 1; }
     }
}

int valid_leave(object me, string dir)
{
	object room;
       if (dir == "north")
          me->add_temp("marks/north",1);
       if (dir == "south")
          me->add_temp("marks/south",1); 
       if (dir == "east")
          me->add_temp("marks/east", 1); 
       if (dir == "west")
          me->add_temp("marks/west", 1); 
       if (dir == "northeast")
          me->add_temp("marks/northeast",1);
       if (dir == "southeast")
          me->add_temp("marks/southeast",1); 
       if (dir == "southwest")
          me->add_temp("marks/southwest", 1); 
       if (dir == "northwest")
          me->add_temp("marks/northwest", 1); 

       if (me->query_temp("marks/east") == 1 && 
           me->query_temp("marks/west") == 1 &&
           me->query_temp("marks/northwest") == 1 &&
           me->query_temp("marks/southwest") == 1 &&
           me->query_temp("marks/north") == 1 &&
           me->query_temp("marks/northeast") == 1 &&
           me->query_temp("marks/south") == 1 &&
           me->query_temp("marks/southeast") == 1) {
       if(!(room = find_object(__DIR__"jiulaodong1")))
           room = load_object(__DIR__"jiulaodong1");
           set("exits/out", __DIR__"shanpo");
        me->delete_temp("marks/east");
        me->delete_temp("marks/west");
        me->delete_temp("marks/north");
        me->delete_temp("marks/south");
        me->delete_temp("marks/northwest");
        me->delete_temp("marks/northeast");
        me->delete_temp("marks/southwest");
        me->delete_temp("marks/southeast");
	call_out("delete_exits_1", 3, room);
	return 1; }
        return ::valid_leave(me,dir);

}
void delete_exits_1(object room)
{       
        delete("exits/out");
}