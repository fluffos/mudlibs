// mufang.c Modify By River

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"木房"NOR);
	set("long", @LONG
刚进屋，你就被巨大的锯木声吵住了，这里堆了好多长的木头，准备要做
柴火用的，但是在送去柴房前先得把长木头锯短成一截截的，才能用柴刀劈开。
不少人正在费力的锯着木头。
LONG
	);
        
	set("exits", ([
		"east" : __DIR__"shilu2",
	]));

	set("objects", ([
		__DIR__"npc/guanjia2" : 1,
	]));

	set("no_fight",1);
	set("action_list", ([
		"锯木头":"ju 木头",
	]));
	setup();
}

void init()
{
	add_action("do_ju", "ju");
	add_action("do_ju", "锯");        
}

int do_ju(string arg)
{
	object me = this_player(), weapon;
	int costj, costq;

	if ( !arg || arg != "木头" )
		return notify_fail ("你要锯什么？\n");

	if(me->query_temp("job_name")!="锯木头") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干! \n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢!\n");

	if (me->is_fighting())
		return notify_fail("你正在战斗中,无法专心干活!\n");   

	weapon = me->query_temp("weapon");
	if( !weapon || weapon->query("id") != "ju zi")
		return notify_fail("你想用什么来锯木头，用手掰吗？\n");
             
	costj = random( me->query("con")/3);
	costq = random( me->query("str")/3);

	if ( me->query("jing") < costj || me->query("jing") < costq){
		message_vision(HIR"木头断了，$N一没留神让掉下来的木头砸在了脚上。"NOR"\n",me);
		me->unconcious();
		return 1;
	}

	me->receive_damage("jing", costj);
	me->add("qi", -costq);       
	if( me->query_temp("mark/锯") > 15 + random(5) || me->query_temp("mark/完了")) {
		me->set_temp("mark/完了",1);
		write(CYN"木房管事说道：「干的不错，好了，你可以去大师兄鲁坤那覆命了！」"NOR"\n");
		return 1;
	}
	write("你摆正一根木头，慢慢锯了起来。\n");
	me->start_busy(1);
	me->add_temp("mark/锯",1);
	if( me->query_skill("hand", 1) < 30 && random(10) > 6 ){
		write(HIM"你在锯木头的推拉中对基本手法有些体会!"NOR"\n");
		me->improve_skill("hand", me->query("int") / 10);
	}
	return 1;
}
