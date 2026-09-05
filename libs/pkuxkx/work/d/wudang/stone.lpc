// stone.c 巨岩
// by llin

#include <ansi.h>
inherit ROOM;

#include "caiqi.h";
void create()
{
	set("short", "巨岩");
	set("long", 
"你的双脚落在一块大岩石上，四处都是壁立的山崖，唯独\n"
"此处竟凸出一块可立足的岩石，令人由衷的佩服造化的神工鬼\n"
"斧。山风凛冽，吹的人几乎站立不稳，随时可能摔下崖去。\n"
	);
	set("outdoors","wudang");
	set("objects", ([
/*                  __DIR__"npc/laoren" : 1,*/
		] ));
	setup();
}
int do_climb()
{	
	object me=this_player();
/*
	if (!arg || arg!="stiff") {
		write("你要爬什么？\");
		return 0; }

	else { */
	me->set_temp("times",3);
	message_vision("$N一咬牙，扳住崖上的岩石，手脚并用继续向上爬去。\n",me);
	remove_call_out("climbing");
	call_out("climbing",1,me);
	return 1; 
}
int climbing(object me)
{
	int times=me->query_temp("times");
	int skl=(int)me->query_skill("dodge",1);
	int hurt=to_int((int)me->query("max_qi")/4)+100;

	if (times==3) { 
	me->move(__DIR__"stiff2");
	me->start_busy(5);
	me->add_temp("times",-1);
	call_out("climbing",5,me);
	return 1;}
	
	if (times==2 || times==1) 
    {	
	if (skl<120 && random(140-skl)>20) {
	tell_object(me,RED"突然你左脚踏空，向下一滑，听得一声惨叫：啊...... 直坠而下。\n"NOR);
	me->move(__DIR__"feng");
	me->receive_wound("qi", hurt, "爬巨岩摔下来");
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
	tell_object(me,"你抬头仰望，突然发现峰顶就在眼前，顿时气力倍增，双脚一蹬跳了上去。\n");
	me->move(__DIR__"ding");
	return 1;
	}
}
