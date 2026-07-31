// /d/xingxiu/mogaoku.c
// Jay 3/17/96
inherit ROOM;
// can put some book about budism here.
void create()
{
        set("short", "莫高窟");
        set("long", @LONG
这里墙壁上绘制着与佛教相关的画面，有仙女飞天，还有反弹琵琶。洞中
还有很多佛像和经书。你被这些瑰丽的文化之宝惊呆了。
LONG
        );
        set("exits", ([ 
             "out" : __DIR__"yueerquan",
]));
        set("no_clean_up", 0);
	set("item_desc", ([
                "仙女飞天" : "这是一整块巨石雕成的“仙女飞天图”，下面有一行小篆：“xxx鬼谷子xxx”。\n",
	]));

	setup();
}

void init()
{
	add_action("do_study", "study");
}


int do_study(string arg)
{
	object me;
	int    jing_cost;

	me = this_player();

	if ( !arg || ( arg != "仙女飞天图" ) )
		return notify_fail("你要读什么？");

	if ( (int)me->query_skill("literate", 1) < 1){
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}

	if ( (int)me->query_int() < 45){
		write("你的悟性不够，先学点文化(literate)吧。\n");
		return 1;
	}

	jing_cost = me->query("max_jing")/5;
	if((int)me->query("jing") < jing_cost){
		write("你现在眼花缭乱，别给美女图迷惑了。\n");
		return 1;
	}
	me->receive_damage("jing", jing_cost );
	me->delete_temp("stone_learned");

	message_vision("$N正专心研读石壁上的古怪图形。\n", me);
	
	write("你对着石壁琢磨了一回儿，似有所悟。\n");

        if ( (int)me->query_skill("qimen-flee", 1) < 300 && random(10)>3 ){
			me->improve_skill("qimen-flee", me->query_int());
			me->set_temp("stone_learned",1);
		}
	return 1;
}

