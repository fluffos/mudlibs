// Room: /d/city/yunhe2.c
// Date:  netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "京杭运河" NOR);
    set("long", HIY @LONG
船航行在京杭运河上。江面上许多船只来来往往。两岸的
景物慢慢向后退去，微风习面。这里距京城不远，两岸的村庄
沿岸而建，村民们靠着运河的繁华，做一些小买卖，日子过的
也不错。
LONG NOR
    );


    set("outdoors", "city");
    setup();
}


   

void init()

{	

	 object me=this_player();
	 tell_object(me, CYN "\n\n\n船在大河上一路缓缓而行。两岸的风景尽收眼底...\n\n\n" NOR ) ;
	 call_out("goto",6, me);
	 
        }

void goto(object me)
{   
	int i;
	i=(int)me->query_temp("exit");
	if (i)
	{
	if (i<20) {
		me->move (__DIR__"yunhe1");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	
	if (i>20) {
		me->move (__DIR__"yunhe3");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	}


}