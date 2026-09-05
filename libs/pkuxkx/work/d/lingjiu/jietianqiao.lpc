#include <ansi.h>
inherit ROOM;
void end_busy(object);
void create()
{
  set("short","接天桥");
  set("long",@LONG
这就是去灵鹫宫必经的接天桥，虽说是桥，其实只一根铁链，
横跨两边峭壁，下临乱石嶙峋的深谷，风一吹还左右摇晃，
走在上面真令人胆战心惊。
LONG );
  set("outdoors", "lingjiu");
  set("no_clean_up", 0);
  set("no_task",1);
  setup();
}

void init()
{
	object me=this_player();
	me->start_busy(5);
	call_out("end_busy",2, me);
	return;
}
void end_busy( object me)
{
	object room;   	
	if ( me->is_busy() )
   	 {		
		tell_object( me, "你战战兢兢，晃晃悠悠地向对面走去......\n");
		call_out("end_busy",2,me);
	}
	else
	{
	if (me->query_temp("tiesuo_1"))
		room = load_object(__DIR__"xianchou");
	else
		room = load_object(__DIR__"jian");
	me->delete_temp("tiesuo_1");

	message_vision("$N终于来到了对面，心里的石头终于落地。\n",me);
	me->move(room);
//        tell_room( environment(me), "只见$N衣诀飘飘,飘然而来.\n", ({me}));
	}
        return;
}
