// caidi.c Modify By River

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"菜地"NOR);
	set("long", @LONG
这里是一座极大的菜园，种满了油菜，萝卜，茄子，丝瓜之类。周围的篱
笆都破了，看来要整修了。由于长期得不到良好的照顾，菜地里杂草丛生，种
的菜都长势不好，蔫蔫的，地都荒了。
LONG
	);
        
	set("exits", ([
		"south" : __DIR__"houyuan",
	]) );

	set("no_fight",1);
   
	set("objects", ([
		__DIR__"npc/guanjia5" : 1,
	]));
	set("action_list", ([
		"锄草":"chu 草",
	]));
	setup();
}

void init()
{
	add_action("do_chu", "chu");
	add_action("do_chu", "锄");        
}

int do_chu(string arg)
{
	object me = this_player(), weapon;
	int costj, costq;

	if( !arg || arg != "草" )
		return notify_fail("你要锄什么？\n");

	if(me->query_temp("job_name")!="锄草") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干! \n");

	if(me->is_busy())
		return notify_fail("你现在正忙着呢!\n");

	if(me->is_fighting())
		return notify_fail("你正在战斗中,无法专心干活!\n");

	weapon = me->query_temp("weapon");

	if( !weapon || weapon->query("id") != "chu tou")
		return notify_fail("你想用什么来锄草，用手吗？\n");

	costj = random( me->query("con")/3);
	costq = random( me->query("str")/3);

	if( me->query("jing") < costj || me->query("qi") < costq){
		message_vision(HIR"$N手一松，不小心锄在自己的脚上。"NOR"\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->add("qi", -costq);
	if( me->query_temp("mark/锄") > 15 + random(5) || me->query_temp("mark/完了")) {
		me->set_temp("mark/完了",1);
		write(CYN"菜地管事说道：「干的不错，好了，你可以到大师兄鲁坤那里去覆命了！」"NOR"\n");
		return 1;
	}  
	write("你挥起锄头，对着地上的杂草锄了起来。\n");
	me->start_busy(1);
	me->add_temp("mark/锄",1);
	if( me->query_skill("staff", 1) < 30 && random(10) > 6 ){
		write(HIM"你在锄草中对于杖的用法有些体会!"NOR"\n");
		me->improve_skill("staff", me->query("int") / 10);
	}
	return 1;
}
