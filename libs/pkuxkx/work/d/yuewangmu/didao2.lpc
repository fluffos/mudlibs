// 挖的地道
// by male
inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", HIB"挖的地道"NOR);
	set("long", @LONG
    这里光线很暗,身后传来微弱的亮光把你的身影投射到前方潮湿的泥土上,
你觉得你离岳王的墓室更近了，你的心跳开始加速，看来你只有继续<dig 
岳王墓>了
LONG
	);

	set("exits", ([
                "out" : __DIR__"didao1",

	]));


        set("no_task",1);
	setup();
}
void init()
{
object me;
me=this_player();
me->set_temp("digcount",0);
   add_action("do_dig","dig");
}

int do_dig(string arg)
{
object me;
object qiao;
me=this_player();
if(!arg||arg!="岳王墓")
 {
 tell_object(me,HIR"你要挖什么呀?\n"NOR);
return 1;
}
if(!me->query("asked包"))
{
message_vision(HIR"你乱挖什么呀?这是岳王爷的墓!\n"NOR,me);
return 1;
}
if(!objectp(qiao=me->query_temp("weapon"))||(string)qiao->query("id")!="tie qiao")
{
 tell_object(me,HIW"怎么,你准备用手挖啊?想盗墓也要找一个好工具呀!\n"NOR);
  return 1;
}
if(me->is_busy())
{
tell_object(me,HIR"你正忙着呢,待会再挖!\n"NOR);
 return 1;
}
if(me->query("neili")<40)
{
  tell_object(me,HIR"你内力已消耗殆尽,无力继续了!\n"NOR);
 return 1;
}
if(me->query_temp("digcount")<20)
{
tell_object(me,HIW"你像做贼般的挖了起来......\n"NOR);
qiao->add("usetime",-1);
if(qiao->query("usetime")<0)
{
tell_object(me,HIR"由于你连番的挖掘,铁锹在你手中竟然断成两截!\n"NOR);
        destruct(qiao);
}
me->add_temp("digcount",1);
me->start_busy(6);
me->add("neili",-20);
}
else
{
message_vision(HIW"$N挖了良久,在里面又挖了一个很深的地道出来,看来,你必须进去继续挖.\n"NOR,me);
me->set_temp("dig4",1);
 set("exits/enter", __DIR__"didao3");
me->add("neili",-100);
message_vision(HIR"同时，一阵内疚感也袭上了$N的心头...\n"NOR,me);
me->add("shen",-1000);
if(me->query("neili")<0)
  {
   message_vision(HIR"虽然$N又挖出了一节地道,但是$N的内力也在最后消耗殆尽,$N眼前一黑......\n"NOR,me);
delete("exit/enter");
   me->unconcious();
}
        remove_call_out("close");
        call_out("close", 30, this_object());
}
 return 1;
}
void close(object room)
{
object me;
me=this_player();
me->add_temp("digcount",-5);
  message_vision(HIW"地道里的一些泥土又落了下来封住了往里进来的路.\n"NOR,me);
    room->delete("exits/enter");
}

int valid_leave(object me, string dir)
{
        if (dir == "out")
message_vision(HIW"$N刚一出去，里面的泥土就塌了下来，封住了洞口。\n"NOR,this_player());
	return 1;
}
