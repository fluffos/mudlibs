//caidi.c
//by mask 99/11


#include <ansi.h>
inherit ROOM;

void create()
{

         set("short", "菜地");
         set("long", @LONG                              
这里是武当山的菜地，地里长满了绿油油的蔬菜，让人看着就觉得
舒服。几个道人正在地里摘菜(zhaicai)。
LONG
         );
         set("no_fight",1);
         set("exits", ([
                 "east" :__DIR__"guangchang",
         ]));

         setup();
         //replace_program(ROOM);
}
void init()
{
add_action("do_sa","zhaicai");
}
int do_sa(string arg)
{
         
         object me,ob,fish;
         int n;
         n = 0;         me=this_player();

         if (!me->query_temp("job")||me->query_temp("job")!=1)
         {
         tell_object(me,"你要干嘛？\n");
         return 1;
         }
         if(me->is_busy())
         return notify_fail("你正忙着呢。\n");

         if(me->query_temp("cai",1))
         {
         write(HIR"快把菜送到火工道人那里去吧。\n",NOR);
         return 1;
         }
else
{       
  if(me->query("jing")<10)
  return notify_fail("你今天太累了，应该休息一下了。\n");
         message_vision(HIG"$N伏下身开始挑选最嫩的蔬菜。\n"NOR,me); 
         n++; 
         me->receive_damage("jing",10);
        
 if (random(5)>=3||n >= 8)
{    
         message_vision(HIC"$N摘满了一把鲜菜，快给火工道人送去吧！\n"NOR,me);
         fish=new("/d/wudang/obj/cai");
         fish->move(me); 
         n=0;
         me->set_temp("cai",1);
         return 1;
}
else
{
         me->start_busy(5);
         return 1;
}
return 1;
}
return 1;
}

