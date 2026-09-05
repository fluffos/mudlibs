// Room: /u/kiss/quanzhen/yutang.c
// Made by: kiss
// Modify by: hongdou 98.12.7

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"女浴室"NOR);
	set("long", 
"这是扬州城里一家最著名的浴室了,听说这里从城外的
温泉引水来给客人洗澡，凡是在这里沐浴过后，客人的
体力和精力都可以得到最大限度的恢复，真是很神奇啊:
你一进浴室，看见一个大理石砌成的大池，池子边立着
个大牌子：
 
        ※   "HIM"浣        凤        池"NOR"   ※  

里面有几个女子在沐浴，水中泛起腾腾的热气，令你忍
不住也想跳进去痛痛快快洗个澡(bath)。\n"                
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"bathroad",
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
   if(me->query_temp("have_bath"))
   { 
       return notify_fail("你不是刚刚洗过澡了么?洗多了皮肤会皱的，影响美观。\n");
   }
   else {
	me->set_temp("have_bath",1);
    	if( me->is_busy() )
       		return notify_fail("你上一个动作还没有完成呢。\n");       
	message_vision(HIY"$N扭动腰身扑通一声跳进水里，开始洗澡！\n",me);
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
