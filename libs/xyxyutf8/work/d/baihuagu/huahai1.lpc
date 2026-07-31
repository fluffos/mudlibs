inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "花海");
        set("long", @LONG
放眼望去，但见天地间仿佛已被鲜花充满，但却是无人认得出的花
朵，只觉得这些花无比的鲜艳，无比的美丽。真是令人想不到，荒漠之
中，竟有这样的花海。
LONG
        );
        set("exits", ([
		"north" : __DIR__"huahai",
  		"south" : __DIR__"huahai2",
	]));
        set("objects", ([
                __DIR__"npc/ningmou" : 1,
       	]) );
	setup();
}

void init()
{
	add_action("do_hear","hear");
	add_action("do_niang","niang");
}

int do_hear()
{
 	object me=this_player();
 	if( !query("jiangjing") )
 		return 0;
	if((string)me->query("family/family_name")!="百花谷")
      		return 0;
	if(me->is_busy())
      		return notify_fail("你正忙着呢。\n");
	if(me->query("faith")<10 )
		return notify_fail("你的门派贡献度不够。\n");
	if( me->query("kee")<30 || me->query("sen")<30 )
		return notify_fail("你现在太累了。\n");	
	me->add("faith",-10);
	tell_object(me,"你在旁边听着，听着。不禁对明玉神功有所领悟。\n");
   	me->start_busy(5);
   	me->improve_skill("brightjade-force",random((int)(me->query("spi")+me->query("int"))/2));
   	me->improve_skill("baihua-xianfa",random((int)(me->query("spi")+me->query("int"))/2));
   	me->receive_damage("kee",20);
   	me->receive_damage("sen",20);
   	return 1;
}