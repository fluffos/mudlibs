// Room: /d/tiezhang/sslin-3.c
#include <room.h>

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "松树林");
	set("long", @LONG
你走进一片黑压压的松树林，这里的松树枝繁叶茂，树冠相叠，遮天蔽日。
几素阳光从树梢间照射下来，在淡淡的雾气中，形成条条白色的光柱，煞是好
看。你走着走着，忽然发现自己已迷失在这片松林中，找不到出去的路了。
LONG
	);

	set("exits", ([ 
  		"west" : __DIR__"sslin-4",
  		"east" : __FILE__,
  		"south" : __DIR__ "sslin-2",
  		"north" : __FILE__,
	]));
    	set("objects",([
            	__DIR__"npc/laohu"  :1,
    	]));
	set("outdoors", "铁掌山");
	set("no_clean_up", 0);
	setup();

}

void init()
{
	add_action("do_fa","fa");
}

int do_fa(string arg)
{    
        object me,weapon,obj;
        int costj, costq;
        me = this_player();

        if(me->query_temp("job_name")!="伐木") 
             return notify_fail("你必须跟帮主领了这工作才能在这里干! \n");
        if (me->is_busy())
             return notify_fail("你现在正忙着呢!\n");
        if (me->is_fighting())
             return notify_fail("你正在战斗中,无法专心干活!\n");
        weapon = me->query_temp("weapon");
        if( !weapon || weapon->query("id") != "tie fu")
             return notify_fail("你想用什么来伐木？\n");
        if ( !arg || !(arg == "mu" || arg == "木"))
           return notify_fail("你想要干什么？\n");
             
        costj = random((int)me->query("con")/2);
        costq = random((int)me->query("str")/2);

        if ((int)me->query("jingli") < costj 
         || (int)me->query("qi") < costq){
		message_vision(HIR"正好一棵大树倒在$N身上，$N一下子被砸晕了过去。\n"NOR,me);
		me->unconcious();
		return 1;
	}        
	me->receive_damage("jingli", costj);
	me->add("qi", -costq);       
	if (((int)me->query_temp("mark/伐木") > 20 + random(5))){
		me->set_temp("mark/伐完",1);
		write(HIW"你发现地上的木头正好可以挑一担了，应该回去覆命了!!\n"NOR);
		return 1;
	}  
	write ("你挥起手中铁斧，朝松树上一下下砍去。\n");
	me->add_busy(1);
	me->add_temp("mark/伐木",1);
	if ( me->query("combat_exp", 1) > 30000 
	 && !me->query_temp("mark/meet_gf")
	 && random(10) > 7){
		obj = new(__DIR__"npc/gfbing");
		me->set_temp("mark/meet_gf", 1);
		obj->set_temp("guanfu", me->query("id"));
		obj->move(environment(me));
	}
	if ((int)me->query_skill("axe", 1) < 31 && random(10)> 6 ){
		write(HIM"你对于基本斧法有了些体会!\n"NOR);
		me->improve_skill("axe", (int)(me->query("int") / 10));
	}
	return 1;
}
