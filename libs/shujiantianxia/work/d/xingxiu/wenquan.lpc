// /d/xingxiu/silk8.c
#include <ansi.h>
inherit ROOM;

void remove_effect(object me);
void create()
{
        set("short", HIW"清水温泉"NOR);
        set("long", @LONG
这温泉水在个沟谷内。谷旁杨柳层林，有眼温泉涌出，溪水潺潺，寒冬
不冻，白雾蒸腾，有如沸羹，缓流入谷二、三里到达清水温泉。在清水温泉
洗浴(swim)，可以去风尘，疗病疾。
LONG);
        set("no_fight", "1"); 
        set("outdoors", "yili");

        set("exits", ([
                "northeast" : __DIR__"silk8",
        ]));

        set("coor/x",-300);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-300);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-300);
 set("coor/y",100);
   set("coor/z",0);
   setup();
}
void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{     
        int skill;
        object me;
        me = this_player();   
    
        if((int)me->query_temp("swim") ) 
                return notify_fail("你正在温泉水里呢，是不是热傻了？\n");

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if(me->query("jing") < 300)
                return notify_fail("你现在的精太少了，可能受不了温泉的热能冲击。\n");

        if(me->query("qi") < 500)
                return notify_fail("你现在的气太少了，可能受不了温泉的热能冲击。\n");
       
        if(me->query("max_neili") < 500)
                return notify_fail("你现在的内力太少了，可能受不了温泉的热能冲击。\n");

        if(me->query("neili") < 500)
                return notify_fail("你现在的真气太少了，可能受不了温泉的热能冲击。\n");

        if(me->query_skill("force") < 100 )
                return notify_fail("你的内功根基还不够，在洗温泉有害无益。\n");

        if(me->query_skill("force") > 200 )
                return notify_fail("你目前的内功修为，再洗也无法帮助你提高了。\n");

        if( !stringp(me->query_skill_mapped("force")))
                return notify_fail("没有内功根基，洗温泉水有害无益。\n");
 
        message_vision("$N合衣坐进温泉水里，身体迅速被一阵烟雾所包围。\n",me); 
        write(HIW"你坐进水里，只觉水温急速上升，不由自主地开始运功抵抗。\n"NOR);

        me->add("qi", -250);
        me->add("jing", -250);
        me->add("neili", -250);
        skill = me->query_con()*2;
        me->set_temp("swim", 1);        
        me->start_call_out( (: call_other, this_object(), "remove_effect", me:), skill);
        return 1;
}

void remove_effect(object me)
{
        me->add("qi", -250);
        me->add("jing", -250);
        me->add("neili", -250);
        me->delete_temp("swim");
//      me->improve_skill("force", me->query_skill("force")*5);   
        tell_object(me, HIW "你只觉水温越来越高，你的内功已经发挥到了极限，不行了。。。\n" NOR);
        message_vision("唰地一声，$N从温泉水里站了起来，飞身跃上池边。\n",me);
}

int valid_leave(object me, string dir)
{
  if(me->query_temp("swim"))
               return notify_fail("你正泡在水里呢。\n");

      return ::valid_leave(me, dir);
} 
