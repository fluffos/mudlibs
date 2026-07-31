// mafang.c Modify By River
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIG"马厩"NOR);
	set("long", @LONG
这是武馆的马厩，里面臭烘烘的，养了几十匹马，马夫们把马牵到这里好
生照看，将它们喂饱饮足，再洗刷得干乾净净。马厩中堆放著几堆草料，正中
有一口泔槽，里面有些清水。
LONG
	);
        
	set("exits", ([
		"north" : __DIR__"shilu2",
	]));

	set("no_fight",1);

	set("objects", ([
		__DIR__"npc/guanjia3" : 1,
	]));
	set("action_list", ([
		"打扫马房":"clean 马房",
	]));
	setup();
}

void init()
{
	add_action("do_sao", "clean");
	add_action("do_sao", "sao");        
}

int do_sao(string arg)
{
	object me = this_player(), weapon;
	int costj, costq;

	if ( !arg || arg != "马房" )
		return notify_fail("你要打扫什么？\n");

	if(me->query_temp("job_name")!="打扫马房") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干! \n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢!\n");

	if (me->is_fighting())
		return notify_fail("你正在战斗中,无法专心干活!\n");

	weapon = me->query_temp("weapon");
	if( !weapon || weapon->query("id") != "sao zhou")
		return notify_fail("你想用什么来打扫，用手扫吗？\n");

	costj = random( me->query("con")/3);
	costq = random( me->query("str")/3);

	if( me->query("jing") < costj || me->query("qi") < costq){
		message_vision(HIR"$N脚一滑，不小心滑倒在马粪里。"NOR"\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->add("qi", -costq);
	if( me->query_temp("mark/扫") > 15 + random(5) || me->query_temp("mark/完了")) {
		me->set_temp("mark/完了",1);
		write(CYN"马房管事说道：「干的不错，好了，你可以到大师兄鲁坤那里去覆命了！」"NOR"\n");
		return 1;
	}
	write ("你找了个地方开始扫了起来，真够臭的，你不由闭紧了呼吸。\n");
	me->start_busy(1);
	me->add_temp("mark/扫",1);
	if( me->query_skill("club", 1) < 30 && random(10) > 6 ){
		write(HIM"你在扫地中对于棍的用法有些体会!"NOR"\n");
		me->improve_skill("club", me->query("int") / 10 );
	}
	return 1;
}
