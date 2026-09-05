// for xiakedao
// modified by aiai 98/10/27

inherit ROOM;

void create ()
{
   set ("short", "山谷口");
   set ("long", @LONG

    这里突然出现了一道深谷。向上只能看到一段刀削斧劈似的山
崖，往下则是云雾缭绕，什么也看不清了。
LONG);

   set("item_desc", (["north" : "谷中雪雾缭绕，什么也看不清。\n", ]));

   set("exits", 
   ([ 
     "north" : __DIR__"gudi",
     "south" : __DIR__"shangu",
   ]));
   
   set("objects", 
   ([ 
   ]));


   set("outdoors", "xiakedao");

   setup();
}

void init()
{
   add_action("do_climb", "climb");
   add_action("do_climb", "pa");
}

int do_climb(string arg)
{
   object me;

   me=this_player();

   if( !arg || arg != "up" ){
     return notify_fail("你要爬到哪里去？\n");
   }
   message_vision("$N手足并用，攀住山崖向上爬了过去。\n", me);
   me->move(__DIR__"ya-up7");
   message_vision("$N气喘呼呼地从下面爬了过来。\n", me);   
   return 1;    
}

int valid_leave(object me, string dir)
{
   if (dir == "north" )
   {
     message_vision("$N不顾一切地往谷中跳下去．．．\n", me);
     message("vision", "良久，一声杀猪般的惨号从山谷下传了上来。\n", environment(me), ({ me }));

     call_out("do_unconcious", 0, me);
     return notify_fail("完了．．．\n");
   }

   return ::valid_leave(me, dir);
}

void do_unconcious(object me)
{
     me->move(__DIR__"gudi");
     message_vision("只听一声惨叫，$N死猪般地从山谷口上摔了下来！\n", me);
      me->set_temp("xkd/gudi",1);
     me->unconcious();
}
