//pkroom2.c by becool, 2008-11-21
#include <ansi.h>
inherit ROOM;
int do_onlykill();
int do_nohalt();
void create()
{
        set("short", HIR"群殴室"NOR );
        set("long", @LONG
这是一间阴森森的大屋子，昏暗的灯光被墙上的排气扇吹得摇曳不定。
角落里有两个侏儒模样的小人跪在地上慢腾腾的擦着什么，阵阵的血腥味
让你直想吐。
LONG);
        set("exits", ([
                "out" : "/d/pvp/entrance",
        ]));
        set("no_die", 1);
        set("no_clean_up", 0);
        set("outdoors", "xx" );
        set("max_user", 7);
        setup();
}
void init()
{
        add_action("do_onlykill","hit");
        add_action("do_onlykill","fight");
        add_action("do_onlykill","hitall");
        add_action("do_onlykill","killall"); 
        add_action("do_nohalt","halt");
        add_action("do_cancelbusy","huajie");
}
int valid_leave(object me, string dir)
{
        if ( dir =="out" && me->is_fighting())
                return notify_fail("想逃？恐怕晚喽！\n");
        return ::valid_leave(me, dir);
}
int do_onlykill()
{
        message_vision("在这个地方，你还是动真格的吧！\n",this_player());
        return 1;
}
int do_nohalt()
{
        if (!wizardp(this_player()))
        {
        message_vision("没有人倒下，战斗是永远不会结束的。\n",this_player());
        return 1;
        }
}
int do_cancelbusy(string arg)
{       
	      object target;
	      object me = this_player();
	      if (!arg)
	      return notify_fail("你想化解谁的危机？\n");
	      target = present(arg,environment(me));
	      if( !objectp(target) )
	      return notify_fail("这里没有"+ arg +"。\n");
	      if(me->is_busy())
	      return notify_fail("你正忙着呢，根本无暇化解别人的危机。\n");
	      else
	      message_vision(HIC"$N眼见$n被攻的毫无反击之力，挺身加入战团，化解了$n的困境，可是自己却被敌人牵制了住，无法脱身。\n"NOR, me,target);
        this_player()->start_busy(10+random(11));
        target->start_busy(random(3));
        return 1;
}