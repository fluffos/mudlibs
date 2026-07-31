// zjb /2002/3/16/
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "地室");
        set("long", @LONG  
这是个宽约二十步的正方形地室，空气流畅，令你觉 
得找对地方。
LONG
        );     
        set("exits", ([  
                              ]));
              set("no_clean_up", 0);
        setup();
}
void init()
{
    object me;
    me = this_player(); 
    add_action("do_push", "push"); 
}
 void check_pushwall()
{
    object room; 
  object me = this_player(); 
 if( query("zuobian") &&query("youbian"))
{
message_vision(HIR"左边的墙壁慢慢的打开了。\n"NOR, this_player());          

        set("exits/west", __DIR__"changlang");
           delete("zuobian");
        delete("youbian"); 
me->delete_temp("pushzuo");
me->delete_temp("pushyou");
      call_out("on_guan", 8);
    }
}


int do_push(string arg)
{
        object me; 
      string dir;
             me = this_player();
       if( !arg || arg=="" ) return notify_fail("你要推什么东西!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="wall") {
   message_vision(HIR"$N想推墙的哪一边？\n"NOR, this_player());          
          return 1;
} 
    if( sscanf(arg, "wall %s", dir)==1 ) {
   if( dir=="right" ) {  
if(me->query_temp("pushzuo"))  return notify_fail("你已经在推左边的墙了，还想来推右边的，你当自己是神仙呀!\n");
            message_vision("$N推向了右边的墙壁。\n", this_player()); 
set("youbian",1);
me->set_temp("pushyou",1); 
check_pushwall();
return 1;
}
 else if( dir=="left" ) { 
if(me->query_temp("pushyou"))  return notify_fail("你已经在推右边的墙了，还想来推左边的，你当自己是神仙呀!\n");
  message_vision("$N推向了左边的墙壁。\n", this_player()); 
set("zuobian",1);
me->set_temp("pushzuo",1); 
check_pushwall();
return 1;
}         else {
            write("你想推什么东西?\n");
            return 1;
        }
}
} 
}

void on_guan(object room)
{
      message_vision(HIB"突然出现咔咔的响声，墙壁又合上了!\n"NOR, this_player());
delete("exits/west");
}

