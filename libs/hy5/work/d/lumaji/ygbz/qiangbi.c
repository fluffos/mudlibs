// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
int do_jump(string arg);  
void on_sun();
void create()
{
        set("short", "钢壁");
        set("long", @LONG 
这是用钢铸造的钢壁,探察不出他的厚度,但是估计不底,
你在这里用吸壁功吸着是很费内力的!
LONG
        );
        set("exits", ([
                              ]));
        set("no_clean_up", 1);
        setup();
}
void init()
{
    object me;
    me = this_player();
    if (userp(me)){
        call_out("do_sun",1,me);
        }

    
   add_action("do_jump", "jump"); 
}
int do_jump(string arg)
{
        object me; 
               me = this_player();
      if( !arg || arg=="" ) return notify_fail("你要往哪里跳!\n");
     if( arg=="up" ) { 
if (me->query_skill("dodge",1)<200)
{       write("你拼命忘上跳,但是因为轻功不够失败了!\n");
                            return 1;
        }  
  write("你往上一跃,跳回到了密道!\n");
  if (!query("jiadodge")&& me->query_skill("dodge") <220)
{
 write(HIC"你发现这一跃使你发挥出你平时发挥不出水平，你的轻功等级大大提高了!\n");
 me->set_skill("dodge",me->query_skill("dodge",1)+2);
set("jiadodge",1);
}
 write(HIR"你突然发现原来制钮的右边又有个制钮!\n");
this_player()->set_temp("tongguo",1);
        this_player()->move(__DIR__"tongdao5");
 return 1;
   }

        else {
            write("你想往哪里跳?!\n");
            return 1;
        }
       }  
void do_sun(object me)
{
if (!me) return;
  if (environment(me)!=this_object()) return;  
if (me->query("neili")>9)
{  
write(HIR"你感到身上的内力在慢慢消耗!\n"NOR);
me->add("neili",-me->query("max_neili")/100); 
}if (me->query("neili")<10) 
  {    
 write(HIB"你的内力已经耗净,你感到你的气越来越短了!\n"NOR);
  me->receive_wound("qi",me->query("max_qi")/100);  
}    
   call_out("do_sun",3,me);
            }

