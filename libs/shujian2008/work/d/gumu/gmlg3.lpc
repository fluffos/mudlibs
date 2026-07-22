// Modify By River 98/08/29
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIR"练功房"NOR);
	set("long", @LONG
里面又是一室，却和先一间处处对称，而又处处相反，乃是后窄前宽，西圆东
角，室顶也是刻满了无数符号。此处乃是古墓派祖师林朝英的武功之秘。
LONG
     );      

	setup();
}

void init()
{
	add_action("do_xiulian", "xiulian");
	add_action("do_yanxi", "yanxi");
	add_action("do_tui","tui");
}

int do_yanxi(string arg)
{
	mapping fam;
	object me = this_player();
	
	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");

	if ((int)me->query_skill("literate", 1) < 10)
		return notify_fail("你斗字不识,领悟个啥? \n");            

	if (arg == "top"){
		if (me->query("gender") != "女性")
			return notify_fail("玉女素心剑呈阴柔之气，只适合女子练习。\n");
		if ((int)me->query_skill("sword", 1) < 10)
			return notify_fail("你基本剑法太差，无法研习玉女素心剑。\n"); 
		if (me->query_skill("yunu-jianfa", 1) >= 1)
			return notify_fail("你已经学会玉女素心剑，自己好好练吧。\n");      
		message_vision("$N仰视室顶的图纹，心中揣摩玉女素心剑的精妙之处。\n", me);
		me->receive_damage("jing", 5);
		me->receive_damage("jingli",15);
		me->improve_skill("yunu-jianfa", 2);
		return 1;
	}
	return 0;
}

int do_xiulian(string arg)
{
	mapping fam;
	object me = this_player();

	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");          

	if (me->query("jing") < 40)
		return notify_fail("你精力不能集中,去稍作歇息吧. \n");

	if ((int)me->query_skill("literate", 1) < 10)
		return notify_fail("你斗字不识,领悟个啥? \n");

	if (arg == "backwall"){
		write("你抡掌劈向后方窄窄的石壁，蓬一声被震退数步，手臂一阵酸麻。\n");
		if (me->query_skill("strike", 1) < 51)
			return notify_fail("你看了半天只觉莫测高深，什么也没有学会。\n");
		if (me->query_skill("strike", 1) > 100)
			return notify_fail("你掌力雄浑，不该再死练蛮力了。\n");          
		me->receive_damage("jing", 15 + random(20));
		me->improve_skill("strike", (int)(me->query_int()/2)+(int)(me->query_skill("strike")/4));
		return 1;
	}
	if (arg == "frontwall"){
		write("你挥拳直击弧型前壁，石粉四溅,你也被自己的猛劲震退数步。\n");
		if (me->query_skill("cuff", 1) < 51)
			return notify_fail("你看了半天只觉莫测高深，什么也没有学会。\n");
		if (me->query_skill("cuff", 1) > 100)
			return notify_fail("你拳力已刚猛无比，却无甚招数。\n");
		me->receive_damage("jing",15 + random(20));
		me->improve_skill("cuff", (int)(me->query_int()/2)+(int)(me->query_skill("cuff",1)/ 4));
		return 1;
	}
	if (arg == "westwall"){
		write("你绕西面石壁踏着剑步，用心揣摩壁上剑法精髓。\n");
		if (me->query_skill("sword", 1) < 51)
			return notify_fail("你看了半天只觉莫测高深，什么也没有学会。\n");
		if (me->query_skill("sword", 1) > 100)
			return notify_fail("你对石壁上所述剑法已全然掌握,无须再费力了. \n");
		me->receive_damage("jing", 15 + random(20));
		me->improve_skill("sword", (int)(me->query_int()/2)+(int)(me->query_skill("sword", 1)/4) );
		return 1;
	}
	if (arg == "eastwall"){
		write("你虚拈手指,对着东面的三角形石壁,细心操练暗器的收发手势. \n");
		if (me->query_skill("throwing", 1) < 51)
			return notify_fail("你看了半天只觉莫测高深，什么也没有学会。\n");
		if (me->query_skill("throwing", 1) > 100 )
			return notify_fail("你暗器收发随心,再不能提高于此. \n");
		me->receive_damage("jing", 15 + random(20));
		me->improve_skill("throwing", (int)(me->query_int()/2)+(int)(me->query_skill("throwing", 1)/4 ));
		return 1;
	}
	return 0;
}

int do_tui(string arg)
{          
	object me=this_player();
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ( arg == "westwall"){  
		message_vision(YEL"$N伸手到半圆的弧底推了几下，一块大石缓缓移开，现出一扇洞门。\n"NOR,me);
		set("exits/out", __DIR__"gmlg2");            
		remove_call_out("close");
		call_out("close", 5, this_object());    
		return 1;
	}
	return notify_fail("你要推什么？\n");
}

void close(object room)
{
	message("vision",HIY"大石慢慢退回了原位，又挡住了出口。\n"NOR, room);
	room->delete("exits/out");
}
