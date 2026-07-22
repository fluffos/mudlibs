//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "大殿");
        set("long", @LONG
这里是蜀山剑派的大殿，是会客的地点。供着元始天尊、太上道
君和天上老君的神像，香案上香烟缭绕。靠墙放着几张太师椅，地上放着
几个蒲团。东北是掌门休息室，南边是练武的广场，北边是后殿。
LONG);

        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"square",
                "north" : __DIR__"houdian",
                "northeast" : __DIR__"zhmroom",
        ]));

        set("objects", ([
                __DIR__"npc/jiansheng" : 1,
        ]));

        setup();
//      replace_program(ROOM);
}

void init()
{
   add_action("do_hear","hear");
}

int do_hear()
{
	object me=this_player();
  	if( !query("jiangjing") || (string)me->query("family/family_name")!="蜀山派" )
     		return 0;
	if(me->is_busy())
      		return notify_fail("你正忙着呢。\n");
      	if( me->query("kee")<30 || me->query("sen")<30 )
      		return notify_fail("你现在太累了。\n");
	if(me->query("faith")<10 )
		return notify_fail("你的师门贡献不够。\n");
	tell_object(me,"你在旁边听着，听着。不禁对飞仙之术有所领悟。\n");
  	me->start_busy(5);
	me->improve_skill("xianfeng-yunti",1+random(me->query_spi()+me->query_int())/2);
	me->improve_skill("tianshi-fufa",1+random(me->query_spi()+me->query_int())/2);
	me->add("faith",-10);
	me->receive_damage("kee",20);
   	me->receive_damage("sen",20);
  	return 1;
}