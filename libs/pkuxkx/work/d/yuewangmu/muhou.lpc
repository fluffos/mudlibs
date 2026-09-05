//岳王墓的墓后
// by male
inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", HIG"墓后空地"NOR);
	set("long", @LONG
      这是岳飞墓后的一块空地,这里少有人来,地上涨满了青草,土质松软,
躺在草地上,让人觉得十分舒畅,只是附近的几只麻雀唧唧喳喳叫个不停.
LONG
	);
        set("outdoors", "yuewangmu");

	set("exits", ([
                "southwest" : __DIR__"mubian",

	]));

        set("objects", ([
                __DIR__+"npc/maque":4,
        ]));

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
if(!objectp(qiao=me->query_temp("weapon"))||(string)qiao->query("id")!="tie qiao")
{
  tell_object(me,HIW"怎么,你准备用手挖啊?想盗墓也要找一个好工具呀!\n"NOR);
  return 1;
}
if(!me->query("asked包"))
{
tell_object(me,HIR"你乱挖什么呀?这是岳王爷的墓!\n"NOR);
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
if(me->query_temp("digcount")<40)
{
tell_object(me,HIW"你像做贼般的挖了起来......\n"NOR);
me->add_temp("digcount",1);
qiao->add("usetime",-1);
if(qiao->query("usetime")<0)
{
message_vision(HIR"由于你连番的挖掘,铁锹在你手中竟然断成两截!\n"NOR,me);
        destruct(qiao);
}
me->start_busy(6);
me->add("neili",-20);
}
else
{
message_vision(HIW"$N挖了良久,在地上挖了一个很深的地道出来,看来,你必须进去继续挖.\n"NOR,me);
me->set_temp("dig1",1);
 set("exits/enter", __DIR__"didao");
me->add("neili",-100);
message_vision(HIR"同时，一阵内疚感也袭上了$N的心头...\n"NOR,me);
me->add("shen",-1000);
if(me->query("neili")<0)
  {
   message_vision(HIR"虽然挖出了一个地道,但是$N的内力也在最后消耗殆尽,$N眼前一黑......\n"NOR,me);
   me->unconcious();
delete("exit/enter");
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
  message_vision(HIW"洞口的一些泥土落了下来封住了入口.\n"NOR,me);
    room->delete("exits/enter");
}

/*
int valid_leave(object me, string dir)
{
	if (dir == "east" && (int)me->query("age") < 14 && !wizardp(me))
		return notify_fail("小朋友不要到那种地方去！！\n");
	return 1;
}
*/
