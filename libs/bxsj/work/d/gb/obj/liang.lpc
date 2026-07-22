#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("草料堆", ({ "caoliao dui" }) );
	set_weight(300000);
	set("unit", "个");
	set("long", "这是一个巨大的草料堆。\n");
	set("value", 1000);
	set("material", "wood");
	set("no_get",1);
	set("no_drop",1);
	setup();
}

void init()
{
	add_action("do_dian", "dian");
}

int do_dian(string arg)
{
	object me, obj;

	me = this_player();

	obj = present("yuan bing",environment(me));
	if(obj)
		return notify_fail("你还是先杀了面前的守卫再点火吧。\n");

	message_vision(HIR "$N点着了面前的草料堆，煞时间火光熊熊，越烧越旺。\n" NOR, me );
	me->set_temp("gb_job2_finish",me->query_temp("gb_job2_finish")+1);

	if( me->query_temp("gb_job2_finish")==5)
		write("好，任务已经完成，可以回去复命了。\n" );

	destruct( this_object());

	return 1;
}
