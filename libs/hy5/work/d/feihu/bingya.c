// 冰崖
// by steel 
#include "ansi.h"
inherit ROOM;

void create()
{
	set("short", "冰崖");
	set("long", @LONG
	冰崖之上,朔风如刀,吹得你脸上生疼。崖上光秃秃的，似乎什么
都没有。仔细一看，冰崖的中央有一块大石，好象不是天然生成的。    
LONG
	);
        set("objects",([
             __DIR__"obj/bigstone" : 1,
             ]) );
	setup();
	
}
void init()
{
  add_action("do_climb","climb");
 
}
int do_put(string arg)
{

}
int do_climb(string arg)
{
    object me;
    object obj;
    int dodge;
    me=this_player();
    if(!arg) return 0;
     if(arg!="down")
         return notify_fail("你要爬什么？\n");
    message_vision(HIB"$N抓紧冰崖间的石缝,艰难的爬了下去。\n"NOR,me);
    dodge=me->query_skill("dodge",1);
    if(obj=me->query_temp("armor/boots"))
    {
      if(obj->query("id")=="snow boots")
       {
        if(dodge>80){
            me->add("jing",-80);
            me->add("qi",-80);
            tell_room(__DIR__"hill2",me->name()+"平安的从上面爬下来\n");
            me->move(__DIR__"hill2");
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
               call_out("to_die",5);
               return 1;
             } 
             else
             { 
               call_out("to_yun",5);
               return 1;
             }
    }    
}

void to_die()
{
     message_vision(HIR"不好!$N手上一滑,从半空中摔了下来。\n"NOR,this_player());  
     this_player()->die();
}
void to_yun()
{
     message_vision(HIR"不好!$N手上一滑,从半空中摔了下来。\n"NOR,this_player());     
     this_player()->unconcious();
     this_player()->move(__DIR__"hill2");
}    
