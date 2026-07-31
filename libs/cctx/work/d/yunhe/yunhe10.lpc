// Room: /d/city/yunhe10
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "京杭运河" NOR);
    set("long", HIY @LONG
你现在正坐船航行在京杭运河上。江面上许多船只来来往往。
这里距杭州已经很近了，只见岸上柳树成荫，各色人等都有，更
多的是一些书生，在此吟诗作对，饮酒作乐，岸上一阵阵歌声传
了过来...烟笼寒水月笼沙，夜泊秦淮近酒家。商女不知亡国恨，
隔江犹唱后庭花.....
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

{	 if ( (int)me->query_temp("exit"))
	{
         message("vision", "艄公说“杭州到啦，上岸吧。”，随即把一块踏脚板搭上堤岸。\n"
			   "你信步走上了岸\n\n", me );
	
	me->move(__DIR__"matou4");
	 message("vision",me->name()+"信步从船上走上岸来。\n",environment(me), ({me}) );
       }
}
    
    
    
