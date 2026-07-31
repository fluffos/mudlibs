// Room: /huanghe/huanghe2.c
// Java. Sep 21 1998
#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", "青枫观");
	set("long", @long
青枫观在青山上，青山已在斜阳外。没有雾，谈谈的白云漂渺，看
来却像是雾一样。阵风吹过，苍松间的昏鸦惊起。青风观那出名而沉重
的大门，刚刚开了一线。道观中出奇幽静，半开的窗子里香烟漂渺淡谈
的随风四散，隐约地掩盖了角落的云床。
long );
	set("exits", ([
  
//  "eastdown" : __DIR__"huanghe3",
//  "westdown" : __DIR__"huanghe2",
  "south" : __DIR__"wutai",
  
	]));
	set("objects", ([
		__DIR__"npc/qingfeng" : 1,
		__DIR__"obj/cup" : 1,
		__DIR__"obj/canqi" : 1,
		
	]));
//	set("no_clean_up", 0);
	        set("indoors", "shanxi");
	        set("item_desc", ([
                "bed": "一张云石雕刻的大床，床身冰冷通透，但令人安神。云床低几上，摆着一副残棋。\n",
                "云床": "一张云石雕刻的大床，床身冰冷通透，但令人安神。云床低几上，摆着一副残棋。\n",
        ]) );

         set("coor/x",-350);
        set("coor/y",-400);
        set("coor/z",30);
	setup();
	//replace_program(ROOM);
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
      gin = (int) me->query("eff_jing");
      kee = (int) me->query("eff_qi");
      sen = (int) me->query("eff_jing");
      me->set("jing", gin);
      me->set("qi", kee);
      me->set("jing", sen);
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