//make by yixiang
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "药库");
        set("long", @LONG
这是药房的仓库，你可以用分药(fengyao)命令，帮助药房管事分配
中药，可以增加经验 潜力呀 。
LONG
        );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);

        set("exits", ([
                "south" : __DIR__"yaofang",
                
]));
        setup();
}
void init()
{
        add_action("do_fengyao","fengyao");
        add_action("do_ban","dazuo");
        add_action("do_ban","tuna");
        add_action("do_ban","du");
        add_action("do_ban","study");
        add_action("do_ban","exercise");

}

int do_ban()
{
        write ("你干什么这是别人的药库呀，不要影响别人工作。\n");
        return 1;
}
int do_fengyao()
{
        object me = this_player();
        int bonus,exp,pot;
        object mon;
        if((int)me->query_temp("fengyaoover"))
              return notify_fail("你的药已经分完了，快去找管事要报酬吧。\n");        
        if( (int)me->query_temp("fengyao") ) 
              return notify_fail("你已经在工作了。\n");
       if (!(int)(me->query_temp("fengyaobegin")))
              return notify_fail("你来做什么快走快走。\n");
        message_vision("
$N将袖子一缅，做出一副要大干一场的样子，唉，分个药也要这么样吗？\n\n",me);
        me->set_temp("fengyao",1);
        me->add("qi",-5);
        me->delete_temp("fengyaobegin");
        call_out("del_fengyao", 1, me, mon, bonus, exp, pot);
        return 1;
}
void del_fengyao(object me, object mon, int bonus, int exp, int pot)
{
       int xunhuan;
       xunhuan=random(4);
       xunhuan+=2;
       me->delete_temp("fengyao");
       while(xunhuan > 0) {
       
          if (random (8) <1) {
              message_vision(HIY"哎呀，$N累的满头大汗，一不小心分错了药。\n"NOR,me);
              me->add("qi",-5);
               me->start_busy(1);
              me->set_temp("fengyaow",1);
              }
             else {
               switch(random(3)) {
               case 0: 
                 { message_vision("只见$N随手一扔，药居然刚好扔进药箱，好运气呀。\n",me); 
                  me->add("qi",-1); }
                  break;
               case 1: 
                 { message_vision("$N分的好仔细呀，还要检查一次。\n",me);
                  me->add("qi",-3); }
                  break;
               case 2: 
                 { message_vision("$N看着手上的药材，想了半天终于还是没有找到该放的地方。\n",me); 
                  me->add("qi",-4); }
                  break;
                }
                me->start_busy(1);
              }
              xunhuan--;
             } 
write(HIW"\n 终于完成了，累死人了，好了终于可以去休息一下了.\n对了我还要去拿报酬呢，可不能白干。\n"NOR);
     me->set_temp("fengyaoover",1);
     return ;
}
        
