inherit ROOM;
#include <ansi.h>
#include <combat.h>
void create()
{
        set("short", "山顶");
        set("long", @LONG
这里就是杀手帮后山山顶，从这里可以俯视整个杀手帮的情况.
旁边有一块巨石形状怪异，引人注目.

LONG
        );
        set("outdoors", "pker");
        set("exits", ([
                
                "eastdown" : __DIR__"shanlu24",

                ]));
         
        set("count",1);
        set("no_task",1);
        setup();
        
       
}


void init()
{
   add_action("push","push");
}


int push(string arg)
{
     object me=this_player();
     object ob;
     int i,damage;
     if(!arg||arg!="stone")
      {       
        write("你要推什么?\n");
        return 1;
      }
       if(objectp(present("hu fa", environment(me))))
     {
        write("护法们就在面前，小心点吧\n");
        return 1;
     }
     if(!me->query_temp("aping")||!present("ling",this_player()))
      {
          message("vision",HIR"石头下突然飞出一把铁蒺藜，速度惊人的向"+me->name()+"逼来!\n"NOR,environment(me));
        
          for(i=0;i<random(6)+4;i++)
           {
             if(random(2))
               {
                  message("vision",HIR""+me->name()+"一个移行换位，从容避过!\n"NOR,environment(me));
                  break;            
                  
               }
             message("vision",HIR""+me->name()+"急急忙忙的想要躲开这些暗器，谁知道心神已乱，反而挨上一颗了!\n"NOR,environment(me));
           
             damage=0-((250-(int)me->query_skill("dodge", 1))/4+random(10));
             if(damage>0) 
                damage=0;
             me->add("qi",damage);
           }
        for(i=3;i>0;i--)

{
              ob=new(__DIR__"npc/hufa"+i);
              message("vision",HIY""+ob->name()+"向"+me->name()+"大声喝道：哪个大胆狂徒，竟敢擅闯我帮禁地!?\n"NOR,environment(me));
              ob->move(environment(me));
              ob->kill_ob(me);
            }
       return 1;
       }
       message("vision","你刚刚推开巨石，里面飞出来三个人影，定神一看，原来是杀手帮的护法\n",me);
       for(i=3;i>0;i--)
           {
              ob=new(__DIR__"npc/hufa"+i);
              ob->move(environment(me));
              message("vision",""+ob->name()+"向你抱拳行了个礼\n",me);
           }
       message("vision",HIR"金刀护法向你点头道：你是阿萍她什么人啊？是来要丐帮的棒法秘籍的吧?\n"NOR,me);
       ob=this_object();
       if(!ob->query("count")) 
       {
           write("你来得不巧，秘籍已经让别人拿走了，哼，阿萍这个小贱人！\n");
           me->delete_temp("aping");
       }
       else
       {
           ob=new(__DIR__"obj/staff_book");
           ob->move(me);
           this_object()->add("count",-1);
           write("这本杖法秘籍你拿回去吧!\n");
           me->delete_temp("aping");
       }
       return 1;      
}
 

 