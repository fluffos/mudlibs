
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"tengtiao"
#define FROM __DIR__"shanyabei"
#define TO __DIR__"shanyanan"

int do_yell(string arg);
void create ()
{
  set ("short","山崖");
  set ("long", @LONG
这里是一道山崖，位于黄河的北岸。因为地势险要，所以没有船家
在这里摆渡过河的客人。山崖之间飘荡着一根根长长的藤条，据说武功
高强的人可以拉着藤条从这里直接悠荡到对面的山崖去，也不知道是真
是假，你可以yell tengtiao试试看。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shanlu4",
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}

void init()
{
	
	add_action("do_yell","yell");
	
}  

int do_yell(string arg)
{
	object ship,here,me;int force;
	ship=find_object(SHIPDIR);
	ship=load_object(SHIPDIR);
		
	me=this_player();
	
	if(me->is_busy())
	return notify_fail("你正忙着呢！\n");
	if(me->is_fighting())
	return notify_fail("你先打完仗吧！\n");
		
	here=environment(me);
	force=me->query("neili");
	if(!arg||arg!="tengtiao") return notify_fail("你要喊叫什么?\n");
	if(force<200||me->query_skill("force",1)<20){
	 tell_object(here,me->name()+"使足了力气喊道：有人吗？帮帮忙把藤条扔过来啊！\n远处只是传来你的回声。\n");
	 return 1;
	}
	if(force<=1000) tell_object(here,me->name()+"用力喊道:有人吗？帮帮忙把藤条扔过来啊！\n");
	else if(force<=2000) tell_object(here,me->name()+"鼓足中气用力喊道:有人吗？帮帮忙把藤条扔过来啊！\n");
	else tell_object(here,me->name()+"高声喊道:有人吗？帮帮忙把藤条扔过来啊！声音悠扬,经久不息。\n");
	if(ship->query("yell"))
	 return notify_fail("\n有人正在使用腾条，等等吧！\n");
	
	ship->set("yell",1);	
	message_vision("对面隐约有人叫道：好了，注意接住了！一根藤条悠了过来，$N连忙抓在手里！\n",me);
	me->move(SHIPDIR);
	remove_call_out("do_flying");
	call_out("do_flying",10,me,ship);
	return 1;
}

void do_flying(object me,object ship)
{
   message_vision("$N觉得身形一顿，双脚接触到了实地，已经安全的荡到了这边山崖！\n",me);
   ship->delete("yell");
   me->move(TO);
}

