// Room: /u/kiss/quanzhen/yutang.c
// Made by: kiss
// Modify by: hongdou 98.12.7

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"男浴室"NOR);
	set("long",
"这是扬州城里一家最著名的浴室了,听说这里从城外的
温泉引水来给客人洗澡，凡是在这里沐浴过后，客人的
体力和精力都可以得到最大限度的恢复，真是很神奇啊:
你一进浴室，看见一个大理石砌成的大池，池子边立着
个大牌子：
 
      ※   "HIC"浸        龙        堂"NOR"   ※   

里面有几个男子在沐浴，水中泛起腾腾的热气，令你忍
不住也想跳进去痛痛快快洗个澡(bath)。\n"                
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bathroad",
]));
       set("objects",([
         ]));
	set("no_clean_up", 0);

	setup();

}

void init()
{
   add_action("do_bath","bath");
}


int do_bath()
{ 
    object me;
    me=this_player();
    if(me->query("gender")=="无性")
    {
	message_vision(HIY"$N脱光衣服准备洗澡，突然发现所有的眼光都注视着$N的下体，\n
随即四周骂声不断:“阉贼！快滚开！”\n"NOR,me);
	message_vision(HIC"\n$N被人打得遍体鳞伤，逃了出来！\n\n"NOR,me);
	me->move(__DIR__"bathroad");
	me->unconcious();
	return 1;
    }
    if((string)me->query("gender")=="女性" )
    {
	message_vision(HIY"\n$N摆动着腰身，慢慢脱下衣服，媚笑着跳进了浴池。\n"NOR,me);
	message_vision(HIY"\n无数双眼睛已经喷出了欲火，$N立刻被人按倒在地上，随即失去了知觉。\n"NOR,me);
	message_vision(HIC"\n$N昏迷中被人抬了出来。\n"NOR,me);
	me->add("shen",-3);
	me->move(__DIR__"bathroad");
      me->set("qi",-1);
	return 1;
    }
	
    if(me->query_temp("have_bath"))
    { 
       return notify_fail("你不是刚刚洗过澡了么?多洗澡会脱皮的，可别成瘾了。\n");
    }
    else {
	me->set_temp("have_bath",1);
    	if( me->is_busy() )
       		return notify_fail("你上一个动作还没有完成呢。\n");       
	message_vision(HIY"$N扑通一声跳进水里，开始洗澡！\n"NOR,me);
    	me->start_busy(2); 
    	call_out("finish",10,me);
    	return 1;
    }
}

void finish(object me)
{
	if (!me) return;
    me->set("eff_qi",(int)me->query("max_qi"));
    me->set("qi",(int)me->query("max_qi"));
    me->set("eff_jing",(int)me->query("max_jing"));
    me->set("jing",(int)me->query("max_jing"));
    message_vision(HIY"$N只感觉身心舒畅、精神焕发,整个人仿佛脱胎换骨似的。\n"NOR,me);
}

int valid_leave(object me, string dir)
{
    if((string)me->query("gender")=="女性" && dir=="west")
   {
	tell_object(me,HIY"你想离开这里，却被几个浑身精光的男子挡住了去路，
并色迷迷地道：“小妞，既然来了就和大家一起洗吧，
干什么急着走呢？咱们来个群龙戏凤如何！”\n");
	message_vision(HIY"\n$N又羞又急，大喊道：“救命啊！救命啊！”可是根本没人理会。\n"NOR,me);
	me->add("jing",-20);
	if(me->query("jing")<=20)
	{
	     tell_object(me,HIY"你的身子被人摸来摸去，已经被整得精疲力尽。\n"NOR);
	     message_vision(HIC"\n$N昏迷中被人抬了出来。\n"NOR,me);
	     me->move(__DIR__"bathroad");
	     me->unconcious();
	}
	return notify_fail(HIY"\n你被浴室里的男人们东拉西拽，弄得衣衫不整。\n"NOR);
   }
   return ::valid_leave(me,dir);
}
