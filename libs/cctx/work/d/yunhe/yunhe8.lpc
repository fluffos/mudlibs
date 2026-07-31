// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "运河下游" NOR);
    set("long", HIY @LONG
船一路缓行，来往的船只络绎不绝，扬州到杭州段恐怕是运河
上最热闹的了，不时有画舫从你身边经过，船上传来阵阵琵琶声，
嘈嘈切切错杂弹，大珠小珠落玉盘。听得你直想跳上船去。

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
	if(i)
	{
	if (i>30 && i<40) {
		me->move (__DIR__"yunhe7");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		return;}
	if (i>40) {
		me->move (__DIR__"yunhe9");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		return;}
	if (i<30) {
		me->move (__DIR__"yunhe6");
		message("vision","一只小船驶了过来。\n",environment(me), ({me}) );
		}
	}
}