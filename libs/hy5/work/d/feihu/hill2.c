//天寒山
// by steel 
#include "ansi.h"
inherit ROOM;
//int to_die();
//int to_yun();

void create()
{
	set("short", "天寒山顶");
	set("long", @LONG
        这里已是天寒山的山顶,只见崖缝参差,颇为险恶。就在这山顶之
上，有一座冰崖冲天而起，仔细看看，崖上好象有斧凿的痕迹。似乎可以
顺着爬上去。    
LONG
	);
	
       set("exits", ([
		"southdown" : __DIR__"hill1",
        ]) ); 
	setup();
}
void init()
{
    add_action("do_climb","climb");
}
int do_climb(string arg)
{
    object me;
    object obj;
    int dodge;
    me=this_player();
    if(!arg) return 0;
    if(arg!="bingya")return notify_fail("你要爬什么？\n");
    dodge=me->query_skill("dodge",1);
    if(obj=me->query_temp("armor/boots"))
    {
       message_vision(HIB"$N你抓紧冰崖上的石缝，慢慢爬了上去。\n"NOR,me);

      if(obj->query("id")=="snow boots")
       {
        if(dodge>80){
            me->add("jing",-80);
            me->add("qi",-80);
            tell_room(__DIR__"bingya",me->name()+"平安的从下面爬上来\n");
            me->move(__DIR__"bingya");
            return 1;  
             }
      else
       {
            if(dodge<=60)
             {
               call_out("to_die",2);
               return 1;
             } 
             else
             { 
               call_out("to_yun",2);return 1;
              }
        }
       }
       }
  else
  {
    if(dodge<=60)
             {
               call_out("to_si",5);
               return 1;
             } 
             else
             { 
               call_out("to_yun",5);return 1;
             }
  }    
}

int to_si()
{
     message_vision(HIR"不好!$N手上一滑,从半空中摔了下来。\n"NOR,this_player());  
     this_player()->die();
     return 1;
}
int to_yun()
{
     message_vision(HIR"不好!$N手上一滑,从半空中摔了下来。\n"NOR,this_player());     
     this_player()->unconcious();
     return 1;
}
