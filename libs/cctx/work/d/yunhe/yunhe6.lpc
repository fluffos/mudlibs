// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "运河中游" NOR);
    set("long", HIY @LONG
你现在正坐船航行在京杭运河上。江面上许多船只来来往往。
这里离扬州不远，所以河上还有不少画舫，河上不时传来阵阵的
歌舞声和游客的嘻笑声，不知不觉中你的情绪仿佛也被感染了，
不由想起了“腰缠十万贯，骑鹤下扬州”这句话。
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
	if (i>30 && i<40 ) {
		me->move (__DIR__"yunhe7");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	if (i>40) {
		me->move (__DIR__"yunhe8");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	if (i<30) {
		me->move (__DIR__"yunhe5");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	}
}