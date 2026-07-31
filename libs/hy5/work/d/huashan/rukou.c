// Room: /d/huashan/canglong.c
// Date: Look 99/03/25

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
        set("short","山洞");
        set("long", @LONG
这里是山洞的入口。山洞里面漆黑一团，你根本分不清东南西北，只好胡
乱瞎闯了。
LONG
        );
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_break", "break");
}

int do_use(string arg)
{
    object room, ob, me;
   me = this_player();
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n");

        if(!objectp(ob = present("fire", me)))
        return notify_fail("你手中没有火折，怎么能在山洞里行动？\n");

        if( !arg || arg=="" ) return 0;

        if( arg == "fire" ) {
        message_vision(HIC"$N点燃火折，把洞内照亮了一些。洞内亮了一些，
微弱的火光一闪一闪的。你发现左边"HIG"(left)"HIC"好象有个小口可以过去。\n"NOR, me);
        destruct(ob);
        if(!(room = find_object(__DIR__"rukou")))
            room = load_object(__DIR__"rukou");
            set("exits/left", __DIR__"cave");
            if (me->query_temp("mb"))
{
tell_object("你似乎发现右方多了一条小路。(right)\n",me);
             set("exits/right",__DIR__"midao"); 
}
            call_out("delete_exit", 4, room);   
            return 1; }
}
void delete_exit(object room)
{       
        message("vision",BLU"只听见扑的一声，火折熄灭了。\n"NOR, room);
        delete("exits/left");
        delete("exits/right");
}

int do_break(string arg)
{
        int n;
        object me = this_player();
        object weapon;
        object room;
//        object ob = this_object();
        n = (int)me->query("neili");
        room = find_object(__DIR__"hole");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你手中无剑，怎能破壁？\n");
     message_vision(
    "$N走到石壁前，拔出腰间所悬长剑，运劲向石壁刺了过去。\n", me);

    if ( n >= 600 ){
    message_vision(
    "$N只听一声轰响，石壁被捅穿了。！\n", me);
    set("exits/out",__DIR__"hole");
    this_player()->add("neili", -200);
    remove_call_out("close");
    call_out("close", 5, this_object());
    
    if(!(room = find_object(__DIR__"hole")))
         room = load_object(__DIR__"hole");
    if( room = find_object(__DIR__"hole") ) {
    message("vision", "你只听外面一声轰响，石洞被人从里面捅穿了，露出了一个洞口。\n", room);
    room->set("exits/enter",__DIR__"rukou");
    room->set("exits/out",__DIR__"siguoya");
    remove_call_out("close1");
    call_out("close1", 5, room);   }
    }
    else {
    message_vision(
    "结果只听一声闷哼，$N被石壁的反弹力震得眼前一黑....\n", me);
    this_player()->unconcious();
    }

    return 1;
}

void close(object ob)
{
        message("vision","崖上忽然掉下来一块巨石，将洞口封了个严严实实。\n", ob);
        ob->delete("exits/out");
}
void close1(object room)
{       
        message("vision","崖上忽然掉下来一块巨石，将洞口封了个严严实实。\n", room);
        room->delete("exits/enter");
        room->set("exits/out",__DIR__"siguoya");
}
