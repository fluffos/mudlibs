// Room: /hangzhou/gongdian5.c
// hubo 2008/4/19

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"翡翠池"NOR);
        set("long", HIC@LONG
豁然开朗，竟是一大片平地。四周群山围绕，就如一只大盆一般，盆子
中心碧水莹然，绿若翡翠，是个圆形的池子，隔了这千百年，竟然并不干枯，
想来池底另有活水源头。你见了这奇丽的景色，惊喜无已。
LONG
NOR);
        set("exits", ([
                "south" : __DIR__"gongdian4",
]));
   
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_search", "search");
}

int do_search()
{
        object me,jian;
        me = this_player();
        jian = new(__DIR__"obj/yusword");

        if( me->query("family/family_name") != "红花会" ) 
                {
                    if (!query("gd_triger1") && random(10)==1)
                       {
                               message_vision(HIY"$N四下仔细搜索不想白来一趟，突然发现角落里有一支明晃晃的东西在闪。\n"NOR, this_player());
                               jian->move(__FILE__);
                   set("gd_triger1", 1);
                   return 1;                    
                 } 
                   message_vision("$N四下仔细搜索不想白来一趟，可是什么也没发现。\n", this_player());
                   return 1;
          }
        
        if( me->query("family/family_name") == "红花会")
                {                         
                          if (me->query("hhh_zhuangzi") == 1)
                                return  notify_fail("对于你来说，这里没什么好搜寻的了。\n");
                          
                          if( !me->query("hhh_zhuangzi")
                          && (int)me->query_skill("zhuangzi-mengwu", 1) < 150 )
                      return  notify_fail("你的修为还不够，什么都没找到。\n");
                      
                    if( !me->query("hhh_zhuangzi")
                          && (int)me->query_skill("zhuangzi-mengwu", 1) >= 150 )
                      
                      write(HIY"你四下仔细搜索不想白来一趟，突然你看到了一本刻在竹子上的书。\n"NOR);
                      write(HIY"你打开书认真一看，发现原来是耳熟能详的《庄子》。\n"NOR);
                      write(HIY"你刚想把书扔掉，突然想到，如果可以临阵杀敌中使用庖丁解牛的工夫，那该多好！\n"NOR);
                      write(HIY"你象疯了一样的手舞足蹈了一阵，终于掌握了庄子梦舞的绕蝶绝技！！\n"NOR);
                      me->set("hhh_zhuangzi",1);
                      return 1;
                 }
}      
        

