// caiyuan.c Modify By River
#include <ansi.h>
inherit ROOM;

int do_jiao(string arg);

void create()
{
	set("short",HIG"菜园"NOR);
	set("long", @LONG
这里是一座极大的菜园，种满了油菜，萝卜，茄子，丝瓜之类。周围的篱
笆都破了，看来要整修了。菜园旁有几口大缸，里面盛满了水，可是菜地看起
来都干裂了，几棵菜蔫蔫的长着，是缺水太多了。
LONG
	);
 
	set("exits", ([
		"west" : __DIR__"houyuan",
	]) );

	set("no_fight",1);

	set("objects", ([
		__DIR__"npc/guanjia6" : 1,
	]));
	set("action_list", ([
		"浇水":"jiao 水",
	]));
	setup();
}

void init()
{
	add_action("do_jiao", "jiao");
	add_action("do_jiao", "浇");        
}

int do_jiao(string arg)
{
	object me = this_player(), weapon;
	int costj, costq;

	if ( !arg || arg != "水" )
		return notify_fail("你要浇什么？\n");

	if(me->query_temp("job_name") != "灌溉菜地") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干! \n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢!\n");

	if (me->is_fighting())
		return notify_fail("你正在战斗中,无法专心干活!\n");

	weapon = me->query_temp("weapon");

	if( !weapon || weapon->query("id") != "piao")
		return notify_fail("你想用什么来舀水浇，用手吗？\n");

	costj = random(me->query("con")/3);
	costq = random(me->query("str")/3);

	if( me->query("jing") < costj || me->query("qi") < costq){
		message_vision(HIR"$N弯腰到大缸里舀水，结果失足栽到缸里。"NOR"\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->add("qi", -costq);       
	if( me->query_temp("mark/浇") > (15 + random(5)) || me->query_temp("mark/完了")){
		me->set_temp("mark/完了", 1);
		write(CYN"菜园管事说道：「干的不错，好了，你可以到大师兄鲁坤那里去覆命了！」"NOR"\n");
		return 1;
	}  
	write("你用瓢从缸里舀起水，在菜地里浇起水来。 \n");
	me->start_busy(1);
	me->add_temp("mark/浇",1);
	if( me->query_skill("force", 1) < 30 && random(10) > 6 ){
		write(HIM"你在浇水中对于内功的用法有些体会!"NOR"\n");
		me->improve_skill("force", me->query("int") / 10);
	}
	return 1;
}
