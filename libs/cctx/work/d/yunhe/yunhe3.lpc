// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "运河上游" NOR);
    set("long", HIY @LONG
船一路行来，两岸的山渐渐多了起来，放眼看去。青山绿
水，河上的船也少了许多，偶尔有一两只快船扬满帆，飞快的
驶过。看样子，那是为京城里的大爷们送东西的。
LONG NOR
    );


    set("outdoors", "city");
    setup();
}


void init()

{	object me=this_player();
	tell_object(me, CYN "\n\n\n船在大河上一路缓缓而行。两岸的风景尽收眼底...\n\n\n" NOR ) ;
	call_out("goto",6, me);
}
void goto(object me)
{   
	int i;
	i=(int)me->query_temp("exit");
	if (i)
	{
	if (i>20 && i<30) {
		me->move (__DIR__"yunhe4");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	if (i>30) {
		me->move (__DIR__"yunhe5");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	if (i<20) {
		me->move (__DIR__"yunhe2");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	}
}