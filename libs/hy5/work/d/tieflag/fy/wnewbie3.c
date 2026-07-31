 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "隧道西");
        set("long", @LONG
这是个隧道中提供给新手们小休的床铺。床铺简陋，
但是整个空间倒是挺大，虽然有点潮湿，但还是有不少初
来报道的陌生人夜宿於此。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "enter" : __DIR__"wnewbie4",
  "out" : __DIR__"wnewbie2",


   ]));

        set("objects", ([
       
//        __DIR__"npc/bandit1" : 5,
                        ]) );



        set("no_dazuo",1);
        //set("no_study",1);
        set("no_magic",1);
        set("NONPC",1);
      //set("valid_startroom", 1); 
        set("indoors", "fy");
        set("no_death_penalty",1);
        set("coor/x",-30);
        set("coor/y",0);
        set("coor/z",-10);
        setup();
} 
void init()
{
                        add_action("do_sleep", "sleep");
}
int do_sleep(string arg)
{
   object me, obj, girl;
   int gin, kee, sen; 
   me = this_player();
   obj = this_object(); 
   if (me->is_fighting()) return 1;
   if (this_object()->query_temp("marks/taken")) {
      tell_object(me, "床上有人耶。。。。\n");
      return 1;
   }
      else{
      message_vision("$N揉揉眼、打个哈欠，躺到了床上，", me);
      tell_object(me, "很快你就觉的睡意朦胧。\n");
      message("vision", me->name()+"翻了几个身，找到个舒适的姿势，很快就进入了梦乡。\n", environment(me), me);
      obj->set_temp("marks/taken", 1);
      gin = (int) me->query("eff_gin");
      kee = (int) me->query("eff_kee");
      sen = (int) me->query("eff_sen");
      me->set("gin", gin);
      me->set("kee", kee);
      me->set("sen", sen);
      me->set_temp("disable_inputs",1);
      me->set_temp("block_msg/all",1);
      me->set_temp("is_unconcious",1);
      me->set("disable_type",HIG "<睡梦中>"NOR); 
      call_out("wake", 10, me);
      return 1;
   }
   return 1;
} 
void wake(object me)
{
   object obj; 
   obj = this_object();
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
   me->delete_temp("block_msg/all");
   me->delete_temp("is_unconcious");
   if(!me->is_ghost())
   message_vision("$N睁开了眼睛，一个鲤鱼打挺从床上跳了下来。\n", me); 
   tell_object(me, "你觉得精神好了很多。\n");
   obj->set_temp("marks/taken", 0);  
}  