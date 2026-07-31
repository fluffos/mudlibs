// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "运河中游" NOR);
    set("long", HIY @LONG
船航行在京杭运河上。岸边不时可以看见一些戏耍的小孩，也
有几个闲者在此垂钓，看上去也没钓到什么鱼，所谓醉翁之意不在
酒，在乎山水之间，这几个人看来只是为游戏而来罢了。
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
	if (i>30) {
		me->move (__DIR__"yunhe6");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		return;}
	if (i<20) {
		me->move (__DIR__"yunhe3");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	else{
		me->move (__DIR__"yunhe4");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
	    }
	}
}