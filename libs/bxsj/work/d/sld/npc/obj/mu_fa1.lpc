//mu_fa.c
//wzfeng
#include <ansi.h>
inherit ROOM;
void run_mufa(object me);
void run_mufa1(object me);
void run_mufa2();
int do_hua(string arg);
int canhua;

void create()
{
	set("short", "小木筏");
	set("long", @LONG
你坐在一个小木筏上，四周是无边无际的的茫茫大海，一阵海风轻轻吹来，
小木筏“咯吱咯吱”的左右摇晃，你不由心底有些发虚，你试图去划(hua)着
木筏前进。
LONG
);
	set("no_fight",1);

	set("outdoors", "神龙岛");
	set_temp("curstatus","ready");

	setup();
}

void init()
{
	canhua=1;
	add_action("do_hua", "hua");
	if(userp(this_player())) {
		remove_call_out("run_mufa2");
		call_out("run_mufa2", 600);
	}
}

int do_hua(string arg)
{
	object me;

	me=this_player();
	if( !arg || arg=="" || canhua==0 ) return 0;

	if(arg!="mufa")
		return notify_fail("你要划什么？\n");

	if(me->query("jing")<30)
		return notify_fail("你现在太疲倦了，休息一下再划吧。\n");   
	me->receive_damage("jing", 20);
	message_vision( HIY "$N拿起木筏上的一根木头，将木筏向前划去。\n" NOR, me);
	set("player",me->query("id"));
	me->start_busy(5);
	if(canhua==1) {
		canhua=0;
		remove_call_out("run_mufa");
		call_out("run_mufa", 10,me);
	}
	return 1;
}

void run_mufa(object me)
{
	mapping myfam;
 
	message("vision","小木筏顺着海风，一直向东飘去。\n", this_object());
    
	myfam = (mapping)me->query("family");
	remove_call_out("run_mufa1");
	if(!myfam || myfam["family_name"] != "神龙教") {
		if(random(10) > 4)
			call_out("run_mufa1", 10, me);
		else
			canhua=1;
	}
	else	 
		call_out("run_mufa1", 10, me);
}

void run_mufa1(object me)
{
	object* ob;
	int i;

	message("vision","只听“轰”的一声，小木筏好象撞到了什么东西，你一下在子被抛了出来。\n", this_object());
	message("vision","你回头一看，小木筏撞得散架，沉到海里了。\n", this_object());
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if(!living(ob[i])) continue;
		ob[i]->move("/d/sld/dukou");
		tell_room(environment(me), ob[i]->name() + "被抛上岸来。\n",({ ob[i] }));  
	}
	remove_call_out("run_mufa2");
	set_temp("curstatus","ready");
}

void run_mufa2()
{
	object* ob,obj=this_object();
	int i;

	if(query_temp("curstatus",1)=="ready")	return;
	message("vision","只听“轰”的一声，小木筏好象撞到了什么东西，你一下在子被抛了出来。\n", obj);
	message("vision","你回头一看，小木筏撞得散架，沉到海里了。\n", obj);
	ob = all_inventory(obj);
	for(i=0; i<sizeof(ob); i++) {
		if(!living(ob[i])) continue;
		ob[i]->move("/d/sld/dukou");
		tell_room(obj, ob[i]->name() + "被抛上岸来。\n");  
	}
	set_temp("curstatus","ready");
}
