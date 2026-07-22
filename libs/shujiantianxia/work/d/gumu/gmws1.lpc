// gmws1.c By River 98/08/30
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"卧室"NOR);
	set("long", @LONG
这里是小龙女以前居住的卧室，房中空空洞洞，还保持着以前老模样。一
块长条青石作床（bed)，床上铺了张草席，一幅白布当作薄被，此外除了一根
人高的绳索横过室中，别无他物。
LONG        );
          
	set("item_desc", ([
		"bed" : HIC"一张由普通青石铺成的床，床角落处，有一块突起的石板。\n"NOR, 
	]));

	set("exits", ([
		"south" : __DIR__"gmht",
	]));
                    
	setup();
}

void init()
{
	add_action("do_tang", "tang");
	add_action("do_ban", "ban");
	add_action("do_ban","move");
}

int do_tang(string arg)
{
	object me=this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ( arg == "bed"){
		message_vision(HIC"$N附身躺在青石制成的石床上面。\n"NOR,me);
		me->set_temp("marks/床", 1);
		return 1;
	}
	return notify_fail("你要躺在地上，小心着凉哦！\n");
}  

int do_ban(string arg)
{  
	object me, *inv;
	me = this_player();

	if (!me->query_temp("marks/床")) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");          
	if ( arg == "shiban" ){
		if (me->query("neili") < 500)
			return notify_fail("你使出吃奶的劲力，但石板却纹丝不动。\n");
		if( me->query("combat_exp", 1) < 100000 && ! me->query("gmpass"))
			return notify_fail("你发现什么地方好象卡住了，怎么也扳不动石板。\n");

		inv = filter_array(deep_inventory(me), (: userp :));
		if (sizeof(inv)) 
			return notify_fail(HIR"你身上背负一人，只觉得在床上腾挪都十分困难。\n"NOR);

		message_vision(HIY"$N用力扳动突起的石板，只听得轧轧几响，石床已落入下层石室。\n"NOR,me);
		me->receive_damage("neili",200);
		me->delete_temp("marks/床");
		me->move(__DIR__"ss0");
		if( ! me->query("gmpass")) me->set("gmpass", 1);
		tell_object(me,HIY"室顶石壁又慢慢自行推上了。\n"NOR);
		tell_room(environment(me), me->name() + "从上面翻身倒下来到这里。\n", ({ me }));
		return 1;
	}
	return notify_fail("你要扳什么？\n");
}
