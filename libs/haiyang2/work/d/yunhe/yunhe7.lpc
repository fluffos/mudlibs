// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "京杭运河" NOR);
    set("long", HIY @LONG
你现在正坐船航行在京杭运河上。江面上许多船只来来往往。
这里距扬州港已经很近了，可以看见码头上喧闹不止，许多人正
在帮运货物，岸边还停着一些官府的船，一些游乐的画舫。
LONG NOR
    );


    set("outdoors", "city");
    setup();
}


void init()

{	
	object me=this_player();
	
	tell_object(me, CYN "\n\n\n船渐渐的向岸边靠去,就快到了...\n\n\n" NOR ) ;
	call_out("goto",6, me);
}
void goto(object me)

{	 if ( (int)me->query_temp("exit") )
	{
         message("vision", "艄公说“扬州到啦，上岸吧。”，随即把一块踏脚板搭上堤岸。\n"
			   "你信步走上了岸\n\n", me );
	 me->move(__DIR__"matou2");
	 message("vision",me->name()+"信步从船上走上岸来。\n",environment(me), ({me}) );
 }      
}