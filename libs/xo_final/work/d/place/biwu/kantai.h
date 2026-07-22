inherit ROOM;
#include <ansi.h>

void init()
{
    add_action("do_leave",({"leave","back"}));
    add_action("do_accept","accept");
}

int do_leave(string arg)
{
    string DestRoom;
    object me=this_player();
    
   if(me->query("xli_marks/have_baoming"))
    return notify_fail("你已经报名参加本次比武大会了，怎么能随便离开呢？\n");
   DestRoom=me->query("startroom");
    message_vision("$N向大家挥了挥手，急速离开了。\n",me);
    me->move(DestRoom);
    return 1;
}

int do_accept(string arg)
{
    tell_object(this_player(),"你想接受什么啊？\n");
    return 1;
}
