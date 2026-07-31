// make by daniel@jhfy.sd 2001
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "船舱");
        set("long", @LONG
这是货船的船舱，你可以来这里做搬运(banyun)的工作，帮助金老板
搬运货物，当然会有工资的，就是增加经验 潜力呀 。
LONG
        );
        set("no_fight",1);
         set("no_drop",1);
         set("no_get",1);
        set("no_steal",1);
        set("no_beg",1);

        set("exits", ([

                "out" : __DIR__"matou",
                
]));
        setup();
}
void init()
{
        add_action("do_banyun","banyun");
        add_action("do_baned","dazuo");
        add_action("do_baned","tuna");
        add_action("do_baned","du");
        add_action("do_baned","study");
         add_action("do_baned","exercise");
         add_action("do_baned","array");

}

int do_baned()
{
        write ("你干什么呀，这里是船舱，不要乱来。\n");
        return 1;

}
int do_banyun()
{
        object me = this_player();
        int bonus,exp,pot;
        object mon;
        if((int)me->query_temp("banyunover"))
              return notify_fail("你的货已经搬好了，快去找金老板要工资吧。\n");        
        if( (int)me->query_temp("banyun") ) 
              return notify_fail("你已经在工作了。\n");
       if (!(int)(me->query_temp("banyunbegin")))
              return notify_fail("你来做什么？得先去向金老板要工作。\n");
          message_vision(HIY "
$N卷起袖子，接过工头手中的货物，步步艰难的开始搬运,很快的，就搬好了货物。\n\n" NOR,me);
        me->set_temp("banyunover",1);
        me->add("qi",-5);
        me->delete_temp("banyunbegin");
                     me->start_busy(2);
        call_out("del_fengyao", 1, me, mon, bonus, exp, pot);
        return 1;

}

