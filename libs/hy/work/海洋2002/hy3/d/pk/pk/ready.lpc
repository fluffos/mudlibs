// Room: /d/pk/ready.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "屠人场休息室");
	set("long", @LONG
这里黑乎乎的，地上还有一些粘满了血迹的布条，偶然也看得到断
了的长剑、钢刀什么的。北面的门紧紧的锁着，里面散发出一阵阵血腥
的气味。
[1;31m在这里可以用duihuan来对换你屠人大会中获得得奖励。
如果你的自造武器坏了，可以用ask ouye zi about 修理来免费修理武器
如果没事了，你就可以用out来离开场地
LONG
	);
	set("exits", ([
		"out" : "/d/city/wumiao",
	]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/ouyezi" : 1,
]));


        set("no_fight", 1);
	setup();
}

void init()
{
        add_action("do_start", "duihuan");
}

int do_start()
{
       object me;
       object room,npc,room2;
int a,b,c;
       me = this_player();       
       if (!userp(me))
          return notify_fail("非玩家不得使用！\n");
       if (!me->query_temp("bwdhpk"))
          return notify_fail("你一个玩家也没有屠到！\n");
a=(int)me->query_temp("bwdhpk");
b=a*500;
c=a*300;
        me->add("combat_exp", b);
        me->add("potential",c);
message_vision(HIG"一阵光包围了$N,$N消失不见了。\n"NOR, me);
tell_object(me, "你被奖励了"+chinese_number(b)+"点经验值！\n"+chinese_number(c)+"点潜能\n");
message("channel:chat", HIC"【屠人战况】"HIR + " "+me->query("name")+"共屠人:"+chinese_number(a)+"人   "+HIG"所得"+chinese_number(b)+"经验和"+chinese_number(c)+"点潜能\n"NOR,users() );
me->set_temp("bwdhpk",0);
me->delete_temp("bwdhpk");

           return 1;
 
}
