// ding.c 天柱峰顶
// by llin
#include <ansi.h>
inherit ROOM;
#include "caiqi.h";
void create()
{
	set("short", "天柱峰顶");
	set("long", 
"峰顶是一块不大的平地，头顶是一片淡青的"CYN"苍穹"NOR"，没有一\n"
"丝云朵，令人心旷神怡；脚下是环峙的"YEL"金童，玉女"NOR"诸峰，除此\n"
"地外再无可比肩之处，真可谓汇天地灵气的神仙之地。峰顶上\n"
"四处散生着一簇簇的"GRN"野花野草"NOR"，得造化神秀，常常生出几株\n"
HIW"仙草妙药"NOR"，为凡夫俗子梦寐以求。\n"
	);
	set("outdoors","wudang");
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
	message_vision("$N一咬牙，扳住崖上的岩石，手脚并用小心翼翼的向下爬去。\n",me);
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
	me->move(__DIR__"stiff");
	me->start_busy(5);
	me->add_temp("times",-1);
	call_out("climbing",5,me);
	return 1;}
	
	if (times==2 || times==1) 
    {	
	if (skl<130 && random(150-skl)>20) {
	tell_object(me,RED"突然你左脚踏空，向下一滑，听得一声惨叫：啊...... 直坠而下。\n"NOR);
	me->move(__DIR__"feng");
	me->receive_wound("qi", hurt, "爬天柱峰摔下来");
	message("vision",HIY"忽听得崖上一声惨叫，只见" + (string)me->name() + "从半空摔将下来......\n"NOR,
		environment(me),me);
	me->unconcious();
	me->delete_temp("times");
	return 1;}
	me->start_busy(5);
	message_vision("$N手扯草根，脚踏岩缝，在凛冽的山风中艰难的向下爬着。\n",me);
	me->add_temp("times",-1);
	call_out("climbing",5,me);
	return 1;
    }
	if (times==0) {
	tell_object(me,"你低头一看，离地面只有丈余高，你转身一跳，稳稳的落在地上\n");
	me->move(__DIR__"feng");
	return 1;
	}
}

