// Room: /u/xdd/gumu/gmqianliu2.c
// Modify By River 98/09
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"潜流"NOR);
	set("long", @LONG
你没在水中，只觉水势甚急，冲得你无法立足。你气闷异常，只得屏气摸
索潜行，当真是进退维谷。
LONG    
    );

	set("exits", ([
		"westup" : __DIR__"gmanhe2",
		"east" : __DIR__"gmql1",
	]));    

	setup();
}

void init()
{
	object me;
	me = this_player();
	if ( me->query_skill("yunu-xinjing", 1) < 120 ) {
		me->receive_damage("qi", 50 );
		me->receive_damage("jing", 50 ); 
		message_vision(HIB"$N的真气正在流失，呼吸十分困难。\n"NOR, me);
		if ((int)me->query("qi") < 10 || (int)me->query("jing") < 10) {
			me->set_temp("last_damage_from","在潜流中被淹");
			me->unconcious();
			me->die();   
			return ;
		}
	}
	message_vision(HIB"$N屏住呼吸，渡过了潜流。\n"NOR, me);
}
