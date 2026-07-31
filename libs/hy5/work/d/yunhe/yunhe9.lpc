// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "运河下游" NOR);
    set("long", HIY @LONG
船航行在京杭运河上。江面上许多船只来来往往。这里是繁华的
江南，两岸风景如画，垂柳成荫，来往的船只都在此停留观看，靠岸
停着一只大船看样子是一家有钱人的，船头站着几个年轻的女子正在
指指点点的看风景。好像可以跳过去。
LONG NOR
    );


    set("outdoors", "yunhe");
    setup();
}


void init()

{	
	object me=this_player();
	add_action("do_jump","jump");
	tell_object(me, CYN "\n\n\n船在大河上一路缓缓而行。两岸的风景尽收眼底...\n\n\n" NOR ) ;
	call_out("goto",6, me);
}

int do_jump(string arg)
{
	object me=this_player();
	int i_dodge=(int)me->query_skill("dodge",0);
	me->delete_temp("exit");
	if (!arg || arg=="") return 0;
	if ( arg == "ship" && i_dodge > 60)
	{tell_object(me, "\n你一提气，双脚一点，运起水上漂的工夫，足尖在水\n"+
			 "面连点数下，一转眼，便跃到了大船上。\n\n"+
			 "只听见掌舵的艄公失声惊讶的叫了一声，“咕东”一声，掉进水里。\n\n");
	me->move(__DIR__"ship");
	me->delete_temp("exit");
	}
	return 1;
}

void goto(object me)
{   
	int i;
	i=(int)me->query_temp("exit");
	if (i){
	if (i>40) {
		me->move (__DIR__"yunhe10");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		return;}
	
	if (i<40) {
		me->move (__DIR__"yunhe8");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	}
}
