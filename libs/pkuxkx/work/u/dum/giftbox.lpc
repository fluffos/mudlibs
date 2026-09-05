//giftbox(大礼包)
//Made By dum
//2000-5.-6
#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("大礼包",({"giftbox","box"}));
        set("long","这是一个包装精美的大礼包，还不赶紧拆开看看(chai)?\n");
        set("unit","个");
        set("value",1);
        set("weight",1000000);
        set("no_store",1);
       setup();
}

void init()
{
    add_action("do_chai","chai");
}

int do_chai(string arg)
{
    object me;
    me = this_player();
    if (!arg)  return notify_fail("你要拆什么？\n");
    if((arg=="giftbox") || (arg=="box")) 
    {
         object gift;
        if ( (int)me->query("giftbox" ) > 0 ) return notify_fail("你已经拿过礼物了，为人不能贪得无厌，是不是？\n");
         message_vision(HIG"\n$N手忙脚乱地把大礼包打开，从里面掏出来各种各样的礼物，哇...！\n"NOR,me);
         gift=new("/u/dum/zaizaowan");
         gift->move(me);
         gift=new("/u/dum/expdan");
         gift->move(me);
         gift=new("/u/dum/yuebing1");
         gift->move(me);
         gift=new("/u/dum/yuebing2");
         gift->move(me);
	 gift=new("/d/lingjiu/obj/tlbb");
         gift->move(me);
	 gift=new("/d/xiangyang/npc/obj/shediao");
         gift->move(me);
        me->set("giftbox",1);

         destruct(this_object());
     }
     return 1;
}