// /d/tiezhang/zhaigou1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","寨沟");
	set("long", @LONG
这是山门二边的寨栏，前面有一条深沟，寨栏是有一排粗木桩用粗麻绳捆
起来的，由于很长时间没有江湖门派和官府对铁掌帮的清剿或寻仇，所以寨栏
的木头有些已经腐烂了，有些已经松动了。
LONG
);
	set("exits",([
		"east": __DIR__"shanmen",
		"west": __DIR__"zhaigou2",
	]));

	set("outdoors","铁掌山");
	setup();
}

void init()
{
        add_action("do_repair","repair");
        add_action("do_repair","bu");
}

int do_repair(string arg)
{    
	object me,weapon, obj;
        int costj, costq;
        me = this_player();
        
        if(me->query_temp("job_name")!="补寨栏") 
        	return notify_fail("你必须跟帮主领了这工作才能在这里干! \n");
        
        if (me->is_busy())
        	return notify_fail("你现在正忙着呢!\n");
        
        if (me->is_fighting())
        	return notify_fail("你正在战斗中,无法专心干活!\n");
        
        weapon = me->query_temp("weapon");
        
        if( !weapon || weapon->query("id") != "tie chui")
        	return notify_fail("你想用什么来补？\n");
        
        if ( !arg ||!(arg == "寨栏" || arg == "zhailan"))
        	return notify_fail("你想要干什么？\n");
             
        costj = random((int)me->query("con")/2);
        costq = random((int)me->query("str")/2);

        if ((int)me->query("jingli") < costj 
         || (int)me->query("qi") < costq) {
		message_vision(HIR"$N由于太疲倦了，一个不留神铁锤砸在自己的脚趾上。\n"NOR,me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jingli", costj);
	me->add("qi", -costq);

        if (((int)me->query_temp("mark/补寨栏") > 20 + random(5))){
		me->set_temp("mark/补完",1);
		write(HIG"你发现基本上已经把寨栏修补得差不多了，应该回去覆命了!!\n"NOR);
		return 1;
	}  
	write ("你挥起手中铁锤，修补起寨栏来。\n");
	me->add_busy(1);
	me->add_temp("mark/补寨栏",1);
	if ( me->query("combat_exp", 1) > 30000 
	 && !me->query_temp("mark/meet_gf")
	 && random(10) > 7){
		obj = new(__DIR__"npc/gfbing");
		me->set_temp("mark/meet_gf", 1);
		obj->set_temp("guanfu", me->query("id"));
		obj->move(environment(me));
	}
	return 1;
}
