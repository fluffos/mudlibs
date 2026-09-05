// Room: quanshui.c 泉水中

inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "泉水中");
        set("long", @LONG
及膝深的泉水在你身边缓缓流过，清澈见底，水中不时有小鱼在鹅卵石中
游来游去。
LONG
        );
        set("objects", ([
         __DIR__"npc/liefuyu" : 2, 
        ]));
        setup();
}

 void init()
  {
        int time;
        object me;
        me = this_player();

        add_action("do_tiao", "tiao");
        add_action("do_tiao", "jump");
        if (me->query("id")!=("liefu yu"))
         {
        time = me->query("con")*10;
        message_vision( 
        HIW"$N嗵地跳进泉水中，水花四溅，澈骨冰冷的泉水让$N直想快点离开。\n"NOR,me);
        remove_call_out("jumpout");
        call_out("jumpout",time,me);
     }
  }


int do_tiao(string arg) 
   {
        object me;
        me = this_player();

        if(arg != "out" ) 
             return notify_fail("你试着跳了跳，发现在水里你的轻功大打折扣。\n");
        message_vision(HIW"$N觉得水太凉了，实在受不了，只好跳出泉水。\n"NOR,me);
        remove_call_out("jumpout");
        me->move(__DIR__"xuelingquan");
        tell_room(environment(me),HIW"只听“哗”的一声水响，"+me->query("name")+HIW"湿漉漉的从泉水中跳了出来。\n"NOR);
        return 1;
}

void jumpout(object me)
        {
        if (!me) return;
        message_vision(HIW"$N觉得水太凉了，实在受不了，只好跳出泉水。\n"NOR,me);
        remove_call_out("jumpout");
        me->move(__DIR__"xuelingquan");
        tell_room(environment(me),HIW"只听“哗”的一声水响，"+me->query("name")+HIW"湿漉漉的从泉水中跳了出来。\n"NOR);
        me->start_busy(2);
}

