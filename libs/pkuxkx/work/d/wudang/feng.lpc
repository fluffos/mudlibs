// feng.c 天柱峰下
// by llin
#include <ansi.h>
inherit ROOM;

#include "caiqi.h";

void create()
{
	set("short", "天柱峰下");
	set("long", 
"这儿是密林的边缘，眼前是一座直入云霄的山峰－－天柱\n"
"峰，山峰是一片直上直落的峭壁(stiff)，山岩嶙峋狰狞，只看\n"
"到零星生着的几棵松树，数蓬野草。抬首仰望都觉的头晕目眩，\n"
"恐怕是最灵巧的猿猴也要望峰兴叹吧。传说天柱峰上有仙草灵\n"
"药，但谁又能爬上去呢。南边是一片密林，一条小道曲曲折折\n"
"向西行，正是下山的山道。\n"
	);
	set("item_desc", ([
		"stiff" : "在高高的悬崖上突然闪过一个身影，待你定睛一看，却有什么都没有了。\n"
			  "大概是你眼睛花了吧。\n",
			]));
  set("outdoors", "wudang");
	set("exits", ([
		"south"  : "/newbiequest/wudang/milin/milin7",
		"westdown" : __DIR__"tianmen",
	]));
	setup();
}
int do_climb(string arg)
{	
	object me=this_player();
/*
	if (!arg || arg!="stiff") {
		write("你要爬什么？\");
		return 0; }

	else { */
	me->set_temp("times",3);
	message_vision("$N一咬牙，扳住崖上的岩石，手脚并用向上爬去。\n",me);
	remove_call_out("climbing");
	call_out("climbing",1,me);
	return 1; 
}
int climbing(object me)
{
	int times=me->query_temp("times");
	int skl=(int)me->query_skill("dodge",1);
	int hurt=(int)me->query("max_qi")/5+100;

	if (times==3) { 
	me->move(__DIR__"stiff");
	me->start_busy(5);
	me->add_temp("times",-1);
	call_out("climbing",5,me);
	return 1;}
	
	if (times==2 || times==1) 
    {	
	if (skl<80 && random(100-skl)>20) {
	tell_object(me,RED"突然你左脚踏空，向下一滑，听得一声惨叫：啊...... 直坠而下。\n"NOR);
	me->move(__DIR__"feng");
	me->receive_wound("qi", hurt, "爬天柱峰摔下来");
	message("vision",HIY"忽听得崖上一声惨叫，只见" + (string)me->name() + "从半空摔将下来......\n"NOR,
		environment(me),me);
	me->unconcious();
	me->delete_temp("times");
	return 1;}
	me->start_busy(5);
	message_vision("$N手扯草根，脚踏岩缝，在凛冽的山风中艰难的向上爬着。\n",me);
	me->add_temp("times",-1);
	call_out("climbing",5,me);
	return 1;
    }
	if (times==0) {
	tell_object(me,"你爬的精疲力竭，忽然发现上方有一块突出的巨岩，你提起纵身，一个鹞子翻身跃上巨岩。\n");
	me->move(__DIR__"stone");
	return 1;
	}
}
