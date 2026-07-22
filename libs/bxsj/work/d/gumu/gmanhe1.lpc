// Room: /u/xdd/gumu/gmanhe1.c
// Modify By River 98/09
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"暗河"NOR);
	set("long", @LONG
原来这正是一条地下暗河，此处水声已是轰轰，声势极为骇人。你脚下一
处踏空，便有水流直冲咽喉。此潜流不知来自何处，更不知通往何方。
LONG 
       );

	set("exits", ([
		"northup" :  __DIR__"sshi1",
		"westdown" : __DIR__"gmql1",
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
			me->set_temp("last_damage_from","在暗河中被淹");
			me->unconcious();
			me->die();   
			return ;
		}
	}
	message_vision(HIB"$N屏住呼吸，渡过了暗河。\n"NOR, me);
}
