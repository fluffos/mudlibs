// /u/beyond/mr/hc4.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"花丛中"NOR);
         set("long",@long
你信步观赏, 只见花林中除山茶花外更无别样花卉, 连最常见的牵牛花,
月月红, 蔷薇之类也是一朵都无。走出数十丈后, 只见山茶品种渐多, 偶而
也有一两本还算不错, 却也栽种不得其法。南面就是前院。
long);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"qianyuan",
             "west" : __DIR__"hc1",
]));
         setup();
//         replace_program(ROOM);
}
void init()
{
        add_action("do_dig","jiaoshui");
}

int do_dig(string arg)
{    
        mapping fam;
        object me,ob,weapon;
        int costj, costq;
        me = this_player();
        if(me->query_temp("mr_job")!="浇花") 
             return notify_fail("这事与你和干? \n");
        if (me->is_busy())
             return notify_fail("你现在正忙着呢!\n");
        if (me->is_fighting())
             return notify_fail("你正在战斗中,无法专心干活!\n");
        weapon = me->query_temp("weapon");
        if( !weapon || weapon->query("id") != "shui hu")
             return notify_fail("你想用什么来浇花啊？\n");
        if ( !arg || !(arg == "花" || arg == "hua"))
           return notify_fail("你想要干什么？\n");
             
        costj = random((int)me->query("con")/2);
        costq = random((int)me->query("str")/2);

        if ((int)me->query("jing") < costj 
         || (int)me->query("qi") < costq){
          message_vision(HIR"由于$N太疲倦了，$N一个不小心昏了过去。\n"NOR,me);
          me->unconcious();
          return 1;
          }        
          me->receive_damage("jing", costj);
          me->add("qi", -costq);       
        if (((int)me->query_temp("mark/浇花") > 10 + random(13)))
          {
          me->set_temp("mark/浇完",1);
          write(HIG"所有的花你都浇了一遍，你看着花笑了笑想道,回去覆命了!!\n"NOR);
          return 1;
          }  
          write ("你拿起水壶，在花丛中一处一处的浇起花来。\n");
          me->start_busy(1);
          me->add_temp("mark/浇花",1);
          return 1;
}